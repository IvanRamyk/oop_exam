#ifndef PERFORMCONTAINERWINDOW_H
#define PERFORMCONTAINERWINDOW_H

#include "../../src/Server/Server.hpp"
#include "../../src/Date/Date.hpp"
#include "displayelement.h"
#include "../../src/containers/Set/Set.hpp"
#include "../../src/structures/balanced_searched_trees/SplayTree.hpp"
#include <QMainWindow>


namespace Ui {
class PerformContainerWindow;
}

class PerformContainerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PerformContainerWindow(QWidget *parent = nullptr);
    ~PerformContainerWindow();

signals:
    void SetWindowShow();

private slots:

    void on_backButton_clicked();
    void on_contentBox_activated(int index);

    void on_findButton_clicked();

private:
    Ui::PerformContainerWindow *ui;
    void fillTable(int index);
    void fillElement(int tableId, Server& s);
    void fillElement(int tableId, date_time::DateTime& dt);
    //containType containerType;
    //elemType elementType;

    Server getServerElement();
    date_time::DateTime getDateTimeElement();

    //bool findServerInSet(containType _t, Server elem);
    //bool findDateTimeInSet(containType _t, date_time::DateTime elem);



};

#endif // PERFORMCONTAINERWINDOW_H
