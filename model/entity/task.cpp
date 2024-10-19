#include "task.h"
#include <QDebug>

Task::Task(QList<Answer> answers, Question question)
    : answers(std::move(answers)),
      question(std::move(question)),
      isDoneCorrect(false) {
    initCorrectAnswer();
}

void Task::initCorrectAnswer(){
    for(auto& ans : answers){
        if(ans.isCorrectAnswer()){
            correctAnswer = &ans;
        }
    }
}

QList<Answer> Task::getAnswers() {
    return answers;
}

bool Task::isCorrect() {
    return isDoneCorrect;
}

bool Task::hasAnswer(){
    return hasUserAnswer;
}

Question Task::getQuestion() {
    return question;
}

Answer* Task::getCorrectAnswer(){
    return correctAnswer;
}

void Task::complete(Answer currentAnswer) {
    qInfo() << "Получен ответ от пользователя с текстом: " + currentAnswer.getText();
    hasUserAnswer = true;
    qInfo() << "Сравнение: правильный ответ -  " +
               correctAnswer->getText() +
               " полученный ответ - " +
               currentAnswer.getText();
    if(correctAnswer != nullptr
            && correctAnswer->getText() == currentAnswer.getText()){
        isDoneCorrect = true;
        return;
    }
    isDoneCorrect = false;
}

