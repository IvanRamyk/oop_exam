#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "setwindow.h"
#include "containerwindow.h"
#include "sortwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_setButton_clicked();
    void on_containerButton_clicked();
    void on_sortButton_clicked();

    void on_benchmarkButton_clicked();

private:
    Ui::MainWindow *ui;
    SetWindow *setWindow;
    ContainerWindow *containerWindow;
    SortWindow *sortWindow;
};
#endif // MAINWINDOW_H
