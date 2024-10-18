#ifndef QUIZWINDOW_H
#define QUIZWINDOW_H

#include <QWidget>
#include <windowrequest.h>
#include <QTimer>
#include <task.h>
#include <taskrepository.h>

namespace Ui {
    class QuizWindow;
}

class QuizWindow : public QWidget
    {
        Q_OBJECT

    public:
        explicit QuizWindow(QWidget *parent = nullptr);
        ~QuizWindow();

        void start();

        void setTaskRepository(TaskRepository* taskRepository);

    private slots:
        void nextQuiz();
        void on_completeButton_clicked();
        void decrementTime();
        void quizTimeOut();

        void on_toMainWindowButton_clicked();

        void on_answer2_clicked();

        void on_answer1_clicked();

        void on_answer3_clicked();

        void on_answer4_clicked();

    private:
        Ui::QuizWindow *ui;
        QTimer *timer = new QTimer();
        int taskId = 0;
        Task *currectTask;
        TaskRepository* taskRepository = nullptr;

    signals:
         void sendRequest(WindowRequest request);
    };

#endif // QUIZWINDOW_H
