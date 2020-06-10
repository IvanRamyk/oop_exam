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

    void on_insertButton_clicked();

    void on_findButton_clicked();

    void on_deleteButton_clicked();

private:
    std::string currentKey;

    Ui::PerformContainerWindow *ui;
    void fillTable(int index);
    void fillElement(Server& s);
    void fillElement(date_time::DateTime& dt);
    containType containerType;
    elemType elementType;

    Server getServerElement();
    date_time::DateTime getDateTimeElement();

    Server* findServerInContainer(containType _t, std::string key);
    date_time::DateTime* findDateTimeInContainer(containType _t, std::string key);

    void insertServerInContainer(containType _t, std::string key, Server elem);
    void insertDateTimeInContainer(containType _t, std::string key, date_time::DateTime elem);

    void deleteServerInContainer(containType _t, Server elem);
    void deleteDateTimeInContainer(containType _t, date_time::DateTime elem);

};

#endif // PERFORMCONTAINERWINDOW_H
