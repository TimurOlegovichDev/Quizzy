#include "answer.h"

Answer::Answer(QString text, bool isCorrect){
    this->text = text;
    this->isCorrect = isCorrect;
}

bool Answer::isCorrectAnswer() const{
    return isCorrect;
}

QString Answer::getText() const{
    return text;
}
