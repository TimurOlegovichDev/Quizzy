#include "maincontroller.h"

MainController::MainController(MainWindow* mainWindow,
                               RedactWindow* redactWindow,
                               TaskRepository* taskRepository)
    : QObject(),
      mainWindow(mainWindow),
      redactWindow(redactWindow)
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
    this->taskRepository = taskRepository;
    mainWindow->setTaskRepository(taskRepository);
    redactWindow->setTaskRepository(taskRepository);
}

void MainController::openMainWindow(){
    qInfo() << "Открывается главное окно";
    qInfo() << "В репозитории сейчас тасков: " + QString::number(taskRepository->getAll().size());
    mainWindow->show();
}

void MainController::openQuizWindow(){

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
        default: {
                break;
        }
    }
}
