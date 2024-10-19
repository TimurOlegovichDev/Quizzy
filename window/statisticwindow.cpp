#include "statisticwindow.h"
#include "ui_statisticwindow.h"
#include <QDebug>

StatisticWindow::StatisticWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatisticWindow){
    ui->setupUi(this);
}

StatisticWindow::~StatisticWindow(){
    delete ui;
}

void StatisticWindow::setStatisticService(StatisticService *statisticService){
    this->statisticService = statisticService;
}

void StatisticWindow::setTaskRepository(TaskRepository *taskRepository){
    this->taskRepository = taskRepository;
}

void StatisticWindow::on_toMainWindowButton_clicked(){
    qInfo() << "Запрос на выход в главное меню";
    emit sendRequest(WindowRequest(Statement::MAIN));
    this->close();
}

void StatisticWindow::showStatistic(){
    qInfo() << "Выполняется вывод статистики";
    if(taskRepository == nullptr || statisticService == nullptr){
        qWarning() << "Репозиторий или сервис статистики не инициализированы";
        return;
    }
    QWidget *existingWidget = ui->widget;
    QLayout *existingLayout = ui->widget->layout();
    if (existingLayout) {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0))) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
        delete existingLayout;
    }
    QVBoxLayout *layout = new QVBoxLayout(existingWidget);
    layout->addWidget(
                statisticService->getTableStatistic(
                    taskRepository->getAll()
                    )
                );
    existingWidget->setLayout(layout);
    ui->resultLabel->setText("Результат " +
                             QString::number(
                                 statisticService->getCorrectAnswerPercent(
                                     taskRepository->getAll()
                                     )
                                 )
                             + "%"
                             );
    QList<Task*> copyTasks = taskRepository->getAll();
    taskRepository->clear();
    for(auto& task : copyTasks){
        taskRepository->add(new Task(task->getAnswers(), task->getQuestion()));
    }
    qInfo() << "Статистика выведена";
}
