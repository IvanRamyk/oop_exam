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
    emit mainWindowOpen();
}
