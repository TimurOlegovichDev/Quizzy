#ifndef REDACTWINDOW_H
#define REDACTWINDOW_H

#include <QTableWidget>
#include <QWidget>
#include <windowrequest.h>

namespace Ui {
    class RedactWindow;
}

class RedactWindow : public QWidget
    {
        Q_OBJECT

    public:
        explicit RedactWindow(QWidget *parent = nullptr);
        ~RedactWindow();

    private slots:
        void on_toMainWindowBtn_clicked();

        void on_decrementRow_clicked();

        void on_incrementRow_clicked();

        void on_markCorrectAnswer_clicked();

    private:
        Ui::RedactWindow *ui;

        bool hasGreenCellInRow(int row);

        void handleSelectedItem(QTableWidgetItem *item);

        void showMessage(const QString &title, const QString &text);

    signals:
         void sendRequest(WindowRequest request);
    };

#endif // REDACTWINDOW_H
