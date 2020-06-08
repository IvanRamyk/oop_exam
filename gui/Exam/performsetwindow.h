#ifndef PERFORMSETWINDOW_H
#define PERFORMSETWINDOW_H

#include "../../src/Server/Server.hpp"
//#include "../../src/Date/Date.hpp"
//#include "../../src/structures/balanced_searched_trees/SplayTree.hpp"
#include <QMainWindow>

enum containType {typeList, typeBalancedTree, typeTable};
enum elemType{elementServer, elementDateTime};


namespace Ui {
class PerformSetWindow;
}

//template<class T>
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

private:
    Ui::PerformSetWindow *ui;
    void fillTable(int index);
    containType containerType;
    elemType elementType;
   // T* set;
};

#endif // PERFORMSETWINDOW_H
