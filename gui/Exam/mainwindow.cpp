#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_setButton_clicked()
{
    setWindow = new SetWindow();
    connect(setWindow, &SetWindow::mainWindowShow, this, &MainWindow::show);
    this->close();
    setWindow->show();

}

void MainWindow::on_containerButton_clicked()
{
    containerWindow = new ContainerWindow();
    connect(containerWindow, &ContainerWindow::mainWindowShow, this, &MainWindow::show);
    this->close();
    containerWindow->show();
}

void MainWindow::on_sortButton_clicked()
{
    sortWindow = new SortWindow();
    connect(sortWindow, &SortWindow::mainWindowShow, this, &MainWindow::show);
    this->close();
    sortWindow->show();
}
