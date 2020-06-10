#include "sortwindow.h"
#include "ui_sortwindow.h"

SortWindow::SortWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SortWindow)
{
    ui->setupUi(this);
}

SortWindow::~SortWindow()
{
    delete ui;
}

void SortWindow::on_listButton_clicked()
{

}

void SortWindow::on_tableButton_clicked()
{

}

void SortWindow::on_backButton_clicked()
{
    this->close();
    emit mainWindowShow();
}

void SortWindow::on_backButton_2_clicked()
{
    this->close();
    emit mainWindowShow();
}
