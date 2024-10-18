#include "mainwindow.h"

#include <QApplication>
#include <QLoggingCategory>
#include "mainwindow.h"
#include "redactwindow.h"
#include "maincontroller.h"

/**
 * @brief Обеспечивает запуск главного окна и всего приложения
 */

int main(int argc, char *argv[]){
    QLoggingCategory log("App");
    qInfo(log) << "Запуск приложения";
    QApplication a(argc, argv);
    MainWindow mainWindow;
    RedactWindow redactWindow;
    MainController *controller = new MainController(&mainWindow, &redactWindow);
    controller->openMainWindow();
    return a.exec();
}
