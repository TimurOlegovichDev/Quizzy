#include "task.h"
#include <QDebug>

Task::Task(QList<Answer> answers, Question question)
    : answers(std::move(answers)),
      question(std::move(question)),
      isDoneCorrect(false) {
    initCorrectAnswer();
}

/**
 * @brief Метод необходим для определения правильного ответа в объекте.
 * Если метод не вызвать, ответ пользователя всегда будет неверный, так как
 * правильного ответа система не инициализировала
 */
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

/**
 * @brief метод проверяет решение задачи, и изменяет состояние текущего объекта
 * в зависимости от полученного ответа
 * @param currentAnswer - ответ, полученный от пользователя
 */
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

