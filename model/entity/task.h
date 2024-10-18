#ifndef TASK_H
#define TASK_H

#include <QList>
#include <question.h>
#include <answer.h>


class Task
    {
    public:
        Task(QList<Answer> answers,
             Question question);

        QList<Answer> getAnswers();
        bool isCorrect();
        Question getQuestion();
        void complete(Answer answer);

    private:
        QList<Answer> answers;
        Question question;
        bool isDoneCorrect = false;
    };

#endif // TASK_H
