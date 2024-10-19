#ifndef STATISTICSERVICE_H
#define STATISTICSERVICE_H

#include <QList>
#include <QTableWidget>
#include <task.h>

/**
 * @brief Класс предназначен для получения статистики по итогу решения квиза
 * Имеет возможность выведения различной информации разного формата
 */
class StatisticService{
    public:
        StatisticService();
        QTableWidget* getTableStatistic(const QList<Task*> tasks);
        int getCorrectAnswerPercent(const QList<Task*> tasks);
};

#endif // STATISTICSERVICE_H
