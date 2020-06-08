#include "setwindow.h"
#include "ui_setwindow.h"

SetWindow::SetWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetWindow)
{
    ui->setupUi(this);
}

SetWindow::~SetWindow()
{
    delete ui;
}

void SetWindow::on_listButton_clicked()
{

}

void SetWindow::on_treeButton_clicked()
{

}

void SetWindow::on_tableButton_clicked()
{

}

void SetWindow::on_backButton_clicked()
{
    this->close();
    emit mainWindowShow();
}
