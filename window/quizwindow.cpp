#include "quizwindow.h"
#include "ui_quizwindow.h"

QuizWindow::QuizWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuizWindow){
    ui->setupUi(this);
}

QuizWindow::~QuizWindow(){
    delete ui;
}

void QuizWindow::on_completeButton_clicked(){
    emit sendRequest(WindowRequest(Statement::MAIN));
    this->close();
}

