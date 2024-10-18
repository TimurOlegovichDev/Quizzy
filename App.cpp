#include "mainwindow.h"

#include <QApplication>
#include <QLoggingCategory>

/**
 * @brief Обеспечивает запуск главного окна и всего приложения
 */

int main(int argc, char *argv[]){
    QLoggingCategory log("App");
    qInfo(log) << "Запуск приложения";
    QApplication a(argc, argv);
    MainWindow w;
    qInfo(log) << "Открытие главного окна";
    w.show();
    return a.exec();
}
