#ifndef SORTWINDOW_H
#define SORTWINDOW_H

#include <QMainWindow>

namespace Ui {
class SortWindow;
}

class SortWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SortWindow(QWidget *parent = nullptr);
    ~SortWindow();

signals:
    void mainWindowShow();

private slots:
    void on_listButton_clicked();

    void on_tableButton_clicked();

    void on_backButton_clicked();

private:
    Ui::SortWindow *ui;
};

#endif // SORTWINDOW_H
