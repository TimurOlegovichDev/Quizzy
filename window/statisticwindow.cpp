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

/**
 * @brief При нажатии на кнопку выхода в меню, отправляется запрос контроллеру
 * и закрывается текущее окно
 */
void StatisticWindow::on_toMainWindowButton_clicked(){
    qInfo() << "Запрос на выход в главное меню";
    emit sendRequest(WindowRequest(Statement::MAIN));
    this->close();
}

/**
 * @brief Получаем статистику от сервиса и выводим ее на экран
 */
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
    taskRepository->resetAllTasks();
    qInfo() << "Статистика выведена";
}
