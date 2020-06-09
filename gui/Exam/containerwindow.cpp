#include "containerwindow.h"
#include "ui_containerwindow.h"

ContainerWindow::ContainerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ContainerWindow)
{
    ui->setupUi(this);
}

ContainerWindow::~ContainerWindow()
{
    delete ui;
}

void ContainerWindow::on_backButton_clicked()
{
    this->close();
    emit mainWindowShow();
}

void ContainerWindow::on_tableButton_clicked()
{
    performContainerWindow = new PerformContainerWindow(typeTable);
    connect(performContainerWindow, &PerformContainerWindow::ContainerWindowShow, this, &ContainerWindow::show);

    this->close();
    performContainerWindow->show();
}

void ContainerWindow::on_treeButton_clicked()
{
    performContainerWindow = new PerformContainerWindow(typeBalancedTree);
    connect(performContainerWindow, &PerformContainerWindow::ContainerWindowShow, this, &ContainerWindow::show);

    this->close();
    performContainerWindow->show();
}

void ContainerWindow::on_listButton_clicked()
{
    performContainerWindow = new PerformContainerWindow(typeList);
    connect(performContainerWindow, &PerformContainerWindow::ContainerWindowShow, this, &ContainerWindow::show);

    this->close();
    performContainerWindow->show();
}
