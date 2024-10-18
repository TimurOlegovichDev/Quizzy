#include "maincontroller.h"

MainController::MainController(MainWindow* mainWindow,
                               RedactWindow* redactWindow,
                               QuizWindow* quizWindow,
                               TaskRepository* taskRepository)
    : QObject(),
      mainWindow(mainWindow),
      redactWindow(redactWindow),
      quizWindow(quizWindow)
{
    QObject::connect(this->mainWindow,
                     &MainWindow::sendRequest,
                     this,
                     &MainController::handleRequest
    );
    QObject::connect(this->redactWindow,
                     &RedactWindow::sendRequest,
                     this,
                     &MainController::handleRequest
    );
    QObject::connect(this->quizWindow,
                     &QuizWindow::sendRequest,
                     this,
                     &MainController::handleRequest
    );
    qInfo() << "Инжект репозитория в классы";
    this->taskRepository = taskRepository;
    quizWindow->setTaskRepository(taskRepository);
    mainWindow->setTaskRepository(taskRepository);
    redactWindow->setTaskRepository(taskRepository);
}

void MainController::openMainWindow(){
    qInfo() << "Открывается главное окно";
    qInfo() << "В репозитории сейчас тасков: " + QString::number(taskRepository->getAll().size());
    mainWindow->show();
}

void MainController::openQuizWindow(){
    qInfo() << "Открывается окно квиза";
    quizWindow->show();
    quizWindow->start();
}

void MainController::openQuizRedactWindow(){
    qInfo() << "Открывается окно редактирования";
    redactWindow->show();
}

void MainController::openQuizResultWindow(){

}

void MainController::handleRequest(WindowRequest request){
    qInfo() << "Получен запрос";
    switch (request.getNextStatement()) {
        case Statement::QUIZ_REDACT: {
                openQuizRedactWindow();
                break;
        }
        case Statement::MAIN: {
                openMainWindow();
                break;
        }
        case Statement::QUIZ_RUN: {
                openQuizWindow();
                break;
        }
        default: {
                break;
        }
    }
}
