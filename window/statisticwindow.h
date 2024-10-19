#ifndef STATISTICWINDOW_H
#define STATISTICWINDOW_H

#include <QWidget>
#include <windowrequest.h>

namespace Ui {
    class StatisticWindow;
}

class StatisticWindow : public QWidget
    {
        Q_OBJECT

    public:
        explicit StatisticWindow(QWidget *parent = nullptr);
        ~StatisticWindow();

    private slots:
        void on_toMainWindowButton_clicked();

    signals:
         void sendRequest(WindowRequest request);

    private:
        Ui::StatisticWindow *ui;
    };

#endif // STATISTICWINDOW_H
