#include "quizwindow.h"
#include "ui_quizwindow.h"
#include <QDebug>

QuizWindow::QuizWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuizWindow){

    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(decrementTime()));
}

QuizWindow::~QuizWindow(){
    delete currectTask;
    delete ui;
}

void QuizWindow::start(){
    taskId = -1;
    nextQuiz();
}

void QuizWindow::setTaskRepository(TaskRepository *taskRepository){
    this->taskRepository = taskRepository;
}

/**
 * @brief Выполняет переключение к следующей задаче
 */
void QuizWindow::nextQuiz(){
    if(taskId >= taskRepository->getAll().size()-1){
        emit sendRequest(WindowRequest(Statement::QUIZ_RESULT));
        this->close();
        return;
    }
    timer->start(1000);
    ui->answer1->setAutoExclusive(false);
    ui->answer2->setAutoExclusive(false);
    ui->answer3->setAutoExclusive(false);
    ui->answer4->setAutoExclusive(false);
    ui->answer1->setChecked(false);
    ui->answer2->setChecked(false);
    ui->answer3->setChecked(false);
    ui->answer4->setChecked(false);
    ui->answer1->setAutoExclusive(true);
    ui->answer2->setAutoExclusive(true);
    ui->answer3->setAutoExclusive(true);
    ui->answer4->setAutoExclusive(true);
    currectTask = taskRepository->get(++taskId);
    ui->answer1->setText(currectTask->getAnswers().at(0).getText());
    ui->answer2->setText(currectTask->getAnswers().at(1).getText());
    ui->answer3->setText(currectTask->getAnswers().at(2).getText());
    ui->answer4->setText(currectTask->getAnswers().at(3).getText());
    ui->app_title_label->setText("Quiz " +
                                 QString::number(taskId+1) +
                                 " из " +
                                 QString::number(taskRepository->getAll().size())
    );
    ui->questionLabel->setText(currectTask->getQuestion().getText());
}

void QuizWindow::on_completeButton_clicked(){
   quizTimeOut();
}

/**
 * @brief Анимация таймера в самом окне и уменьшение времени на секунду
 */
void QuizWindow::decrementTime(){
    if(taskRepository->get(taskId)->timeInSeconds <= 0) {
        quizTimeOut();
        return;
    }
    ui->timeLabel->setText(
                QString::number(--taskRepository->get(taskId)->timeInSeconds)
    );
}

/**
 * @brief Останавливает текущее решение и переходит к следующему заданию
 */
void QuizWindow::quizTimeOut(){
    qDebug() << "Решение окончено, оставшееся время: " +
                QString::number(currectTask->timeInSeconds);
    timer->stop();
    nextQuiz();
}


void QuizWindow::on_toMainWindowButton_clicked(){
    qDebug() << "Вызов кнопки выхода в главное меню";
    emit sendRequest(WindowRequest(Statement::MAIN));
    this->close();
}

void QuizWindow::on_answer1_clicked(){
    currectTask->complete(
                currectTask->getAnswers().at(0)
    );
}

void QuizWindow::on_answer2_clicked(){
    currectTask->complete(
                currectTask->getAnswers().at(1)
    );
}

void QuizWindow::on_answer3_clicked(){
    currectTask->complete(
                currectTask->getAnswers().at(2)
    );
}

void QuizWindow::on_answer4_clicked(){
    currectTask->complete(
                currectTask->getAnswers().at(3)
    );
}

