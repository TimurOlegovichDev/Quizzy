#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <Statement.h>
#include "redactwindow.h"
#include "mainwindow.h"

class MainController : public QObject {
    Q_OBJECT

public:
    MainController(MainWindow* mainWindow, RedactWindow* redactWindow);

    void openMainWindow();
    void openQuizWindow();
    void openQuizRedactWindow();
    void openQuizResultWindow();

public slots:
    void handleRequest(WindowRequest request);

private:
    MainWindow* mainWindow;
    RedactWindow* redactWindow;
};

#endif // MAINCONTROLLER_H
