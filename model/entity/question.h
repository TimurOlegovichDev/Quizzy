#ifndef QUESTION_H
#define QUESTION_H

#include <QString>


/**
 * @brief Класс вопроса, хранит в себе текст вопроса
 */
class Question
    {
    public:
        Question(QString text);

        QString getText();

    private:
        QString text;
    };

#endif // QUESTION_H
