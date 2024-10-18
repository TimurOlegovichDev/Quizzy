#ifndef QUESTION_H
#define QUESTION_H

#include <QString>



class Question
    {
    public:
        Question(QString text);

        QString getText();

    private:
        QString text;
    };

#endif // QUESTION_H
