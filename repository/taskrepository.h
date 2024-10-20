#ifndef TASKREPOSITORY_H
#define TASKREPOSITORY_H

#include <task.h>

/**
 * @brief Главное хранилище задач
 */
class TaskRepository
    {
    public:
        TaskRepository();

        QList<Task*> getAll();
        void add(Task* task);
        Task* get(int id);
        void clear();
        void resetAllTasks();

        void shuffleList();
    private:

        QList<Task*> data;
    };

#endif // TASKREPOSITORY_H
