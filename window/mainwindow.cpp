#include "mainwindow.h"
#include "ui_mainwindow.h"


/**
 * @brief Главное окно, в котором пользователь выбирает между созданием квиза и запуском его.
 * Является точкой входа в программу.
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    log("MainWindow")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    qInfo(log) << "Закрытие главного окна";
    delete ui;
}

void MainWindow::setTaskRepository(TaskRepository* taskRepository){
     this->taskRepository = taskRepository;
}

void MainWindow::on_redactButton_clicked(){
    emit sendRequest(WindowRequest(Statement::QUIZ_REDACT));
    this->close();
}


void MainWindow::on_startButton_clicked(){
    if(taskRepository->getAll().size() == 0){
        qInfo() << "Тасков нет, запуск квиза невозможен";
        return;
    }
    taskRepository->shuffleList();
    emit sendRequest(WindowRequest(Statement::QUIZ_RUN));
    this->close();
}


void MainWindow::on_exitButton_clicked(){
    exit(0);
}

