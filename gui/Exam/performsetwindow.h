
#ifndef PERFORMSETWINDOW_H
#define PERFORMSETWINDOW_H

#include "../../src/Server/Server.hpp"
#include "../../src/Date/Date.hpp"
#include "displayelement.h"
#include "../../src/containers/Set/Set.hpp"
#include "../../src/structures/balanced_searched_trees/SplayTree.hpp"
#include "../../src/structures/lists/SingleLinkedList/SingleLinkedOrderedList.hpp"
#include "../../src/Hash/CuckooHash.h"
#include <iterator>
#include <QMainWindow>

#include "perform.h"

namespace Ui {
class PerformSetWindow;
}

class PerformSetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PerformSetWindow(containType _type, QWidget *parent = nullptr);
    ~PerformSetWindow();

signals:
    void SetWindowShow();

private slots:

    void on_backButton_clicked();
    void on_contentBox_activated(int index);

    void on_findButton_clicked();

    void on_insertButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::PerformSetWindow *ui;
    void fillTable(int index);
    void fillElement(int tableId, Server& s);
    void fillElement(int tableId, date_time::DateTime& dt);
    containType containerType;
    elemType elementType;

    Server getServerElement();
    date_time::DateTime getDateTimeElement();

    bool findServerInSet(containType _t, Server elem);
    bool findDateTimeInSet(containType _t, date_time::DateTime elem);

    void insertServerInSet(containType _t, Server elem);
    void insertDateTimeInSet(containType _t, date_time::DateTime elem);

    void deleteServerInSet(containType _t, Server elem);
    void deleteDateTimeInSet(containType _t, date_time::DateTime elem);



};

#endif // PERFORMSETWINDOW_H
