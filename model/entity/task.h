#ifndef TASK_H
#define TASK_H

#include <QList>
#include <question.h>
#include <answer.h>


/**
 * @brief Класс задачи, хранит в себе список возможных ответов и вопрос.
 * По умолчанию стоит ограничение по времени в 30 секунд, при желании его можно заменить
 * у каждого задания по отдельности. Имеет методы, позволяющие ответить на вопрос
 * класс автоматически определяет правильность ответа.
 */
class Task
    {
    public:
        Task(QList<Answer> answers,
             Question question);

        QList<Answer> getAnswers();
        bool isCorrect();
        bool hasAnswer();
        Question getQuestion();
        Answer* getCorrectAnswer();
        void complete(Answer answer);
        int timeInSeconds = 30;

    private:
        QList<Answer> answers;
        Answer* correctAnswer = nullptr;
        Question question;
        bool isDoneCorrect = false;
        bool hasUserAnswer = false;
        void initCorrectAnswer();
    };

#endif // TASK_H
