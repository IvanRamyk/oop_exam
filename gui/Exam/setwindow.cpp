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
    perfromWindow = new PerformSetWindow(typeList);
    connect(perfromWindow, &PerformSetWindow::SetWindowShow, this, &SetWindow::show);

    perfromWindow->show();
    this->close();
}

void SetWindow::on_treeButton_clicked()
{
    perfromWindow = new PerformSetWindow(typeBalancedTree);
    connect(perfromWindow, &PerformSetWindow::SetWindowShow, this, &SetWindow::show);

    this->close();
    perfromWindow->show();
}

void SetWindow::on_tableButton_clicked()
{
    perfromWindow = new PerformSetWindow(typeTable);
    connect(perfromWindow, &PerformSetWindow::SetWindowShow, this, &SetWindow::show);

    perfromWindow->show();
    this->close();
}

void SetWindow::on_backButton_clicked()
{
    this->close();
    emit mainWindowShow();
}
