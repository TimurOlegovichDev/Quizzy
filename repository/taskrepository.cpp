#include "taskrepository.h"

TaskRepository::TaskRepository(){

}

QList<Task> TaskRepository::getAll(){
    return data;
}

void TaskRepository::add(Task task){
    data.append(task);
}

Task TaskRepository::get(int id) {
    if (id >= 0 && id < data.size()) {
        return data.at(id);
    } else {
        throw std::out_of_range("ID is out of range");
    }
}

void TaskRepository::clear(){
    data.clear();
}
