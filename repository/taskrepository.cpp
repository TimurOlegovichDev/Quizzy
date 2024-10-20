#include "taskrepository.h"

TaskRepository::TaskRepository(){}

QList<Task*> TaskRepository::getAll(){
    return data;
}

void TaskRepository::add(Task* task){
    data.append(task);
}

/**
 * @brief Возвращает задачу по номеру
 * @param id - номер задачи
 * @return задача
 */
Task* TaskRepository::get(int id) {
    if (id >= 0 && id < data.size()) {
        return data.at(id);
    } else {
        throw std::out_of_range("ID is out of range");
    }
}

void TaskRepository::clear(){
    data.clear();
}

/**
 * @brief Метод возвращает все квизу к изначальному состоянию
 */
void TaskRepository::resetAllTasks(){
    QList<Task*> copyTasks = std::move(data);
    data.clear();
    for(auto& task : copyTasks){
        data.append(new Task(task->getAnswers(), task->getQuestion()));
        delete task;
    }
}

void TaskRepository::shuffleList() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    for (int i = data.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1); // Генерация случайного индекса от 0 до i
        data.swap(i, j); // Меняем элементы местами
    }
}
