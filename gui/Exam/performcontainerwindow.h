#ifndef PERFORMCONTAINERWINDOW_H
#define PERFORMCONTAINERWINDOW_H

#include "../../src/Server/Server.hpp"
#include "../../src/Date/Date.hpp"
#include "../../src/containers/Map/Map.hpp"
#include "../../src/Hash/HopscotchHash.h"
#include "../../src/Hash/CuckooHash.h"
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

    void on_contentBox_activated(int index);

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

    std::pair<bool, Server> findServerInContainer(std::string key);
    std::pair<bool, date_time::DateTime> findDateTimeInContainer( std::string key);

    void insertServerInContainer(containType _t, std::string key, Server elem);
    void insertDateTimeInContainer(containType _t, std::string key, date_time::DateTime elem);

    void deleteServerInContainer(containType _t, std::string key);
    void deleteDateTimeInContainer(containType _t, std::string key);

};

#endif // PERFORMCONTAINERWINDOW_H
