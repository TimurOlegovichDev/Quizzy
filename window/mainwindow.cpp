#include "mainwindow.h"
#include "ui_mainwindow.h"


/**
 * @brief Главное окно, в котором пользователь выбирает между созданием квиза и запуском его.
 * Является точкой входа в программу.
 */

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), log("MainWindow"){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    qInfo(log) << "Закрытие главного окна";
    delete ui;
}

