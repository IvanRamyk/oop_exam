#include "performcontainerwindow.h"
#include "ui_performcontainerwindow.h"

PerformContainerWindow::PerformContainerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PerformContainerWindow)
{
    ui->setupUi(this);
}

PerformContainerWindow::~PerfmContainerWindow()
{
    delete ui;
}
