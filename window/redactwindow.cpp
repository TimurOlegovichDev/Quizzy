#include "redactwindow.h"
#include "ui_redactwindow.h"
#include <QDebug>
#include <QMessageBox>

RedactWindow::RedactWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RedactWindow)
{
    ui->setupUi(this);
}

void RedactWindow::on_toMainWindowBtn_clicked(){
    this->close();
    emit sendRequest(WindowRequest(Statement::MAIN));
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
    if (!hasGreenCellInRow(row)) {
        item->setBackground(QColor(Qt::green));
    } else {
        showMessage("В этой строке уже есть зеленая ячейка.",
                    "Пожалуйста, выберите другую ячейку.");
    }
}

bool RedactWindow::hasGreenCellInRow(int row) {
    for (int col = 0; col < ui->answersTable->columnCount(); ++col) {
        QTableWidgetItem* item = ui->answersTable->item(row, col);
        if (item && item->background() == QColor(Qt::green)) {
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

RedactWindow::~RedactWindow()
{
    delete ui;
}
