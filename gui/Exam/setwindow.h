#ifndef SETWINDOW_H
#define SETWINDOW_H

#include <QMainWindow>

namespace Ui {
class SetWindow;
}

class SetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SetWindow(QWidget *parent = nullptr);
    ~SetWindow();

signals:
    void mainWindowShow();

private slots:
    void on_listButton_clicked();

    void on_treeButton_clicked();

    void on_tableButton_clicked();

    void on_backButton_clicked();

private:
    Ui::SetWindow *ui;
};

#endif // SETWINDOW_H
