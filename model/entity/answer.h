#ifndef ANSWER_H
#define ANSWER_H

#include <QString>


/**
 * @brief Класс ответа, хранит в себе текст ответа и является ли он
 * правильным
 */
class Answer
    {
    public:
        Answer(QString text, bool isCorrect);

        bool isCorrectAnswer() const;
        QString getText() const;

    private:
        bool isCorrect;
        QString text;
    };

#endif // ANSWER_H
