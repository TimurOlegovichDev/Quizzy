#ifndef ANSWER_H
#define ANSWER_H

#include <QString>



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
