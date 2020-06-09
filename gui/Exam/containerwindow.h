#ifndef CONTAINERWINDOW_H
#define CONTAINERWINDOW_H

#include "performcontainerwindow.h"
#include <QMainWindow>

namespace Ui {
class ContainerWindow;
}

class ContainerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ContainerWindow(QWidget *parent = nullptr);
    ~ContainerWindow();

signals:
    void mainWindowShow();

private slots:
    void on_backButton_clicked();

    void on_tableButton_clicked();

    void on_treeButton_clicked();

    void on_listButton_clicked();

private:
    Ui::ContainerWindow *ui;
    PerformContainerWindow *performContainerWindow;
};

#endif // CONTAINERWINDOW_H
