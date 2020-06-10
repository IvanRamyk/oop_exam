#ifndef SORTWINDOW_H
#define SORTWINDOW_H

#include "perform.h"
#include "../../src/Date/Date.hpp"
#include"../../src/Server/Server.hpp"
#include "../../src/Sort/Sort.h"
#include <QMainWindow>
#include <QMessageBox>

enum sortingType{selectionSort, mergeSort, Heapsort, InsertSort, QuickSort, nonInt};

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

    void on_backButton_2_clicked();

    void on_insertButton_clicked();

    void on_ipRadio_clicked();

    void on_DataCenterRadio_clicked();

    void on_RackRadio_clicked();

    void on_CompanyRadio_clicked();

    void on_contentBox_activated(int index);

    void on_contentBox_activated(const QString &arg1);

    void on_sortButton_clicked();

private:
    Ui::SortWindow *ui;
    void fillTable(int index);
    void fillElement(Server& element);
    void fillElement(date_time::DateTime &dt);
    containType containerType;
    elemType elementType;
    sortingType sortType;



    std::vector<Server> getVectorServer();
    void setVectorServer(std::vector<Server> res);

    std::vector<date_time::DateTime> getVectorDateTime();
    void setVectorDateTime(std::vector<date_time::DateTime> res);

    void insertServerInTable(Server s);
    void insertDateTimeInTable(date_time::DateTime s);
};

#endif // SORTWINDOW_H
