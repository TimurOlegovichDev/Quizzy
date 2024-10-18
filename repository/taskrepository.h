#ifndef TASKREPOSITORY_H
#define TASKREPOSITORY_H

#include <task.h>



class TaskRepository
    {
    public:
        TaskRepository();

        QList<Task*> getAll();
        void add(Task* task);
        Task* get(int id);
        void clear();
    private:

        QList<Task*> data;
    };

#endif // TASKREPOSITORY_H
