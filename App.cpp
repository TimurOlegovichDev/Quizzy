#include "mainwindow.h"

#include <QApplication>
#include <QLoggingCategory>
#include "mainwindow.h"
#include "redactwindow.h"
#include "maincontroller.h"
#include "statisticwindow.h"

/**
 * @brief Обеспечивает запуск главного окна и всего приложения
 */
int main(int argc, char *argv[]){
    QLoggingCategory log("App");
    qInfo(log) << "Запуск приложения";
    QApplication a(argc, argv);
    MainWindow mainWindow;
    RedactWindow redactWindow;
    QuizWindow quizWindow;
    StatisticWindow statisticWindow;
    TaskRepository taskRepository;
    MainController *controller = new MainController(
                &mainWindow,
                &redactWindow,
                &quizWindow,
                &taskRepository,
                &statisticWindow
    );
    controller->openMainWindow();
    return a.exec();
}
