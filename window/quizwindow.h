#ifndef QUIZWINDOW_H
#define QUIZWINDOW_H

#include <QWidget>
#include <windowrequest.h>

namespace Ui {
    class QuizWindow;
}

class QuizWindow : public QWidget
    {
        Q_OBJECT

    public:
        explicit QuizWindow(QWidget *parent = nullptr);
        ~QuizWindow();

    private slots:
        void on_completeButton_clicked();

    private:
        Ui::QuizWindow *ui;

    signals:
         void sendRequest(WindowRequest request);
    };

#endif // QUIZWINDOW_H
