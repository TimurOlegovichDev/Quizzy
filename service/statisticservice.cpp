#include "statisticservice.h"
#include <QDebug>

StatisticService::StatisticService(){}

/**
 * @brief Метод предназначен для создания таблицы с отображением вопрос, правильного ответа
 * и состояния ответа пользователя. Красный (неверный ответ), желтый (нет ответа),
 * зеленый (ответ верный)
 * @param tasks - список всех задач
 * @return созданную таблицу
 */
QTableWidget *StatisticService::getTableStatistic(const QList<Task*> tasks){
    qInfo() << "Выполняется подсчет статистики";
     QTableWidget* table = new QTableWidget(tasks.size(), 4);
     table->setStyleSheet("background-color: rgb(255, 255, 255); font: 75  18pt \"Bahnschrift\";");
     table->setHorizontalHeaderLabels(
                 QStringList() << "Вопрос" << "Правильный ответ" << "Оценка" << "Оставшееся время"
     );
     int row = 0;
     for(auto& task : tasks){
         QTableWidgetItem* itemQuestion = new QTableWidgetItem(task->getQuestion().getText());
         QTableWidgetItem* itemCorrectAnswer = new QTableWidgetItem(task->getCorrectAnswer()->getText());
         QTableWidgetItem* itemTime = new QTableWidgetItem(task->timeInSeconds);
         table->setItem(row, 0, itemQuestion);
         table->setItem(row, 1, itemCorrectAnswer);
         table->setItem(row, 3, itemTime);

         table->setRowHeight(row, 50);
         QTableWidgetItem* itemColor = new QTableWidgetItem();
         if(!task->hasAnswer()){
             itemColor->setBackgroundColor(Qt::yellow);
         } else if(task->isCorrect()){
             itemColor->setBackgroundColor(Qt::green);
         } else {
             itemColor->setBackgroundColor(Qt::red);
         }
         table->setItem(row, 2, itemColor);
         row++;
     }
     return table;
}


/**
 * @brief метод предназначен для получения процента правильных ответов
 * @param tasks - список всех задач
 * @return процент правильных ответов
 */
int StatisticService::getCorrectAnswerPercent(const QList<Task *> tasks){
    qInfo() << "Выполняется подсчет процента правильных ответов";
    int correctCount = 0;
    int totalCount = tasks.size();
    int totalPersents = 100;

    for(auto& task : tasks){
        if(task->isCorrect()){
            correctCount++;
        }
    }
    return static_cast<int>((static_cast<double>(correctCount) / totalCount) * totalPersents);
}
