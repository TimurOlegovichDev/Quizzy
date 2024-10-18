#include "redactwindow.h"
#include "ui_redactwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <question.h>

RedactWindow::RedactWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RedactWindow)
{
    ui->setupUi(this);
}

RedactWindow::~RedactWindow(){
    delete ui;
}

void RedactWindow::setTaskRepository(TaskRepository* taskRepository){
    this->taskRepository = taskRepository;
}

void RedactWindow::on_toMainWindowBtn_clicked(){
    if(!hasEmptyCells()){
        sendTasksToRepository();
        emit sendRequest(WindowRequest(Statement::MAIN));
        this->close();
    }
}

void RedactWindow::on_decrementRow_clicked() {
    int rowCount = ui->answersTable->rowCount();
    if (rowCount > 0) {
        ui->questionTable->removeRow(rowCount - 1);
        ui->answersTable->removeRow(rowCount - 1);
    }
}

void RedactWindow::on_incrementRow_clicked() {
    int rowCount = ui->answersTable->rowCount();
    ui->questionTable->insertRow(rowCount);
    ui->answersTable->insertRow(rowCount);
    ui->questionTable->setItem(rowCount, 0, new QTableWidgetItem());
    ui->answersTable->setItem(rowCount, 0, new QTableWidgetItem());
}

void RedactWindow::on_markCorrectAnswer_clicked() {
    qDebug() << "Пользователь отмечает ячейку";
    QList<QTableWidgetItem*> selectedItems = ui->answersTable->selectedItems();
    if (!selectedItems.isEmpty()) {
        handleSelectedItem(selectedItems.first());
    } else {
        showMessage("Нет выделенных ячеек",
                    "Пожалуйста, выберите ячейку для отметки");
    }
}

void RedactWindow::handleSelectedItem(QTableWidgetItem* item) {
    int row = item->row();
    for (int column = 0; column < ui->answersTable->columnCount(); column++) {
        QTableWidgetItem* answerItem = ui->answersTable->item(row, column);
        if (answerItem != nullptr) {
            answerItem->setBackground(QColor(Qt::white));
        }
    }
    item->setBackground(QColor(Qt::green));
}

void RedactWindow::sendTasksToRepository() {
    taskRepository->clear();
    int rowCount = ui->answersTable->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        Question question(ui->questionTable->item(row, 0)->text());
        QList<Answer> answers;
        for (int col = 0; col < ui->answersTable->columnCount(); ++col) {
            if (ui->answersTable->item(row, col)->background() == QColor(Qt::green)) {
                Answer answer(
                            ui->answersTable->item(row, col)->text(),
                            true
                );
                answers.append(answer);
            } else {
                Answer answer(
                            ui->answersTable->item(row, col)->text(),
                            false
                );
                answers.append(answer);
            }
        }
        taskRepository->add(new Task(answers, question));
    }
}

bool RedactWindow::hasEmptyCells() {
    int rowCount = ui->questionTable->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        if (ui->questionTable->item(row, 0) == nullptr ||
            ui->questionTable->item(row, 0)->text().isEmpty()) {
            showMessage("Ошибка", "Вопрос не может быть пустым в строке " + QString::number(row + 1));
            return true;
        }
    }
    for (int row = 0; row < rowCount; ++row) {
        bool hasCorrectAnswer = false;
        for (int col = 0; col < ui->answersTable->columnCount(); ++col) {
            if (ui->answersTable->item(row, col) == nullptr ||
                ui->answersTable->item(row, col)->text().isEmpty()) {
                showMessage("Ошибка", "Ответ не может быть пустым в строке " + QString::number(row + 1) + ", столбце " + QString::number(col + 1));
                return true;
            }
            if (ui->answersTable->item(row, col)->background() == QColor(Qt::green)) {
                hasCorrectAnswer = true;
            }
        }
        if (!hasCorrectAnswer) {
            showMessage("Ошибка", "В строке " + QString::number(row + 1) + " должен быть хотя бы один правильный ответ.");
            return true;
        }
    }
    return false;
}

void RedactWindow::showMessage(
        const QString& title,
        const QString& text) {
    QMessageBox msgBox;
    msgBox.setFixedSize(600, 400);
    msgBox.setText(title);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setInformativeText(text);
    msgBox.exec();
}
