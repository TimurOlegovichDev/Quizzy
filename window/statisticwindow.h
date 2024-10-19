#ifndef STATISTICWINDOW_H
#define STATISTICWINDOW_H

#include <QWidget>
#include <windowrequest.h>
#include <statisticservice.h>
#include <taskrepository.h>

namespace Ui {
    class StatisticWindow;
}

/**
 * @brief Класс представляет собой окно статистики, выводит общий результат теста
 */
class StatisticWindow : public QWidget{
        Q_OBJECT

    public:
        explicit StatisticWindow(QWidget *parent = nullptr);
        ~StatisticWindow();
        void setStatisticService(StatisticService* statisticService);
        void setTaskRepository(TaskRepository* taskRepository);
        void showStatistic();

    private slots:
        void on_toMainWindowButton_clicked();

    signals:
         void sendRequest(WindowRequest request);

    private:
        Ui::StatisticWindow *ui;
        StatisticService* statisticService;
        TaskRepository* taskRepository;
    };

#endif // STATISTICWINDOW_H
