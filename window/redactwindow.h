#ifndef REDACTWINDOW_H
#define REDACTWINDOW_H

#include <QList>
#include <QTableWidget>
#include <QWidget>
#include <task.h>
#include <windowrequest.h>
#include <taskrepository.h>

namespace Ui {
    class RedactWindow;
}


/**
 * @brief  Окно редактирования квиза. Представляет собой синхронизированные по
 * количеству строк (задач) таблицы (вопросы и ответы). Пользователь может самостоятельно
 * задать необходимые вопросы и отметить верные ответы. Имеется автоматическая валидация
 * таблиц, для правильного определения задач в системе (отметка правильных ответов, заполнение строк)
 */
class RedactWindow : public QWidget
    {
        Q_OBJECT

    public:
        explicit RedactWindow(QWidget *parent = nullptr);
        ~RedactWindow();

        void setTaskRepository(TaskRepository* taskRepository);
    private slots:
        void on_toMainWindowBtn_clicked();

        void on_decrementRow_clicked();

        void on_incrementRow_clicked();

        void on_markCorrectAnswer_clicked();

    private:
        Ui::RedactWindow *ui;

        bool hasGreenCellInRow(int row);

        void handleSelectedItem(QTableWidgetItem *item);

        void showMessage(const QString &title, const QString &text);

        bool hasEmptyCells();

        TaskRepository* taskRepository;

        void sendTasksToRepository();

    signals:
         void sendRequest(WindowRequest request);
    };

#endif // REDACTWINDOW_H
