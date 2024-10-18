#include "question.h"

Question::Question(QString text){
    this->text = text;
}

QString Question::getText(){
    return text;
}
