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

void Task::complete(Answer answer) {
    for (const auto& ans : answers) {
        if (ans.isCorrectAnswer() && ans.getText() == answer.getText()) {
            isDoneCorrect = true;
            break;
        }
    }
}
