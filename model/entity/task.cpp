#include "task.h"

Task::Task(QList<Answer> answers, Question question)
    : answers(std::move(answers)),
      question(std::move(question)),
      isDoneCorrect(false) {
}

QList<Answer> Task::getAnswers() {
    return answers;
}

bool Task::isCorrect() {
    return isDoneCorrect;
}

Question Task::getQuestion() {
    return question;
}

void Task::complete(Answer currentAnswer) {
    for (auto& answer : answers) {
        if (answer.isCorrectAnswer() && answer.getText() == currentAnswer.getText()) {
            isDoneCorrect = true;
            break;
        }
    }
    isDoneCorrect = false;
}
