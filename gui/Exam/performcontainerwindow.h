#ifndef PERFORMCONTAINERWINDOW_H
#define PERFORMCONTAINERWINDOW_H

#include "../../src/Server/Server.hpp"
#include "../../src/Date/Date.hpp"
#include "perform.h"
#include <QMainWindow>



namespace Ui {
class PerformContainerWindow;
}

class PerformContainerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PerformContainerWindow(containType _type, QWidget *parent = nullptr);
    ~PerformContainerWindow();

signals:
    void ContainerWindowShow();

private slots:
    void on_backButton_clicked();

private:
    Ui::PerformContainerWindow *ui;
    void fillTable(int index);
    void fillElement(int tableId, Server& s);
    void fillElement(int tableId, date_time::DateTime& dt);
    containType containerType;
    elemType elementType;

    Server getServerElement();
    date_time::DateTime getDateTimeElement();

    bool findServerInSet(containType _t, Server elem);
    bool findDateTimeInSet(containType _t, date_time::DateTime elem);

};

#endif // PERFORMCONTAINERWINDOW_H
