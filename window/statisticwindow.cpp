#include "statisticwindow.h"
#include "ui_statisticwindow.h"

StatisticWindow::StatisticWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatisticWindow){
    ui->setupUi(this);
}

StatisticWindow::~StatisticWindow(){
    delete ui;
}

void StatisticWindow::on_toMainWindowButton_clicked(){
    emit sendRequest(WindowRequest(Statement::MAIN));
    this->close();
}
