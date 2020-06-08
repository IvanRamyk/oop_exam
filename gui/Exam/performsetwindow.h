#ifndef PERFORMSETWINDOW_H
#define PERFORMSETWINDOW_H

#include <QMainWindow>

enum containerType {List, Tree, Table};

namespace Ui {
class PerformSetWindow;
}

class PerformSetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PerformSetWindow(QWidget *parent = nullptr);
    ~PerformSetWindow();

signals:
    void SetWindowShow();

private slots:
    void on_backButton_clicked();

    void on_contentBox_activated(int index);

private:
    Ui::PerformSetWindow *ui;
    void fillTable(int index);
};

#endif // PERFORMSETWINDOW_H
