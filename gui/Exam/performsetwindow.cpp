#include "performsetwindow.h"
#include "ui_performsetwindow.h"

Set<SplayTree<Server>> setSplayServer;
Set<SplayTree<date_time::DateTime>> setSplayDateTime;



Server PerformSetWindow::getServerElement(){
    ip::address ads(127,0,0,1);
    Server s(ads);
    return s;

}
date_time::DateTime PerformSetWindow::getDateTimeElement(){
    date_time::DateTime dt;
    return dt;
}


PerformSetWindow::PerformSetWindow(containType _type, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PerformSetWindow),
    containerType(_type)
{
    ui->setupUi(this);
    ui->insertElement->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->findElement->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->deleteElement->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    fillTable(0);
    elementType = elementServer;

    switch (containerType) {
        case typeList:
            ui->realisationLabel->setText("Реалізація: Список");
            break;
        case typeBalancedTree:
            ui->realisationLabel->setText("Реалізація: Дерево");
            break;
        case typeTable:
            ui->realisationLabel->setText("Реалізація: Геш-таблиця");
            break;
    }

}


PerformSetWindow::~PerformSetWindow()
{
    delete ui;
}


void PerformSetWindow::on_backButton_clicked()
{
    emit SetWindowShow();
    this->close();
}


void PerformSetWindow::fillTable(int index){
    int n;
    std::vector <QString> names;
    if(index == 0){
        names = {
            QString::fromStdString("Сервер"),
            QString::fromStdString("Датацентр"),
            QString::fromStdString("Rack"),
            QString::fromStdString("Компанія")
        };
    }
    else{
        names = {
            QString::fromStdString("Рік"),
            QString::fromStdString("Місяць"),
            QString::fromStdString("День"),
            QString::fromStdString("Година"),
            QString::fromStdString("Хвилина"),
            QString::fromStdString("Секунда")
        };
    }
    n = names.size();
    int i = ui->insertElement->rowCount();
    while(i < n){
        ui->insertElement->insertRow(i);
        ui->findElement->insertRow(i);
        ui->deleteElement->insertRow(i);
        i++;
    }
    while(i >= n){
        ui->insertElement->removeRow(i);
        ui->findElement->removeRow(i);
        ui->deleteElement->removeRow(i);
        i--;
    }
    QTableWidgetItem* it;
    for(int j = 0; j < n; j++){
        it = new QTableWidgetItem(names[j]);
        it->setFlags(Qt::ItemIsEnabled);
        ui->insertElement->setItem(j,0,it);
        it = new QTableWidgetItem(names[j]);
        it->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->findElement->setItem(j,0,it);
        it = new QTableWidgetItem(names[j]);
        it->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->deleteElement->setItem(j,0,it);
    }
}


void PerformSetWindow::on_contentBox_activated(int index)
{
    fillTable(index);
}


template <class T>
T getElement(elemType _t){
    if(_t == elementServer){
        ip::address adr(127,0,0,1);
        Server s(adr);
        return s;
    } else {
        date_time::DateTime dt;
        return dt;
    }
}



void PerformSetWindow::fillElement(int tableId, Server &s){
    QTableWidget* table;
    switch(tableId){
        case 0:
            table = ui->insertElement;
            break;
        case 1:
            table = ui->findElement;
            break;
        case 2:
            table = ui->deleteElement;
            break;
    }

    std::vector<int> id = {1,2,3,4};
    ip::address aps(1,2,3,4);
    s.IP = aps;
    auto dc = table->item(1,1)->text().toStdString();
    s.data_center = dc;
    auto rc = table->item(2,1)->text().toStdString();
    s.rack = rc;

}


void PerformSetWindow::fillElement(int tableId, date_time::DateTime& dt){
    QTableWidget* table;
    switch(tableId){
        case 0:
            table = ui->insertElement;
            break;
        case 1:
            table = ui->findElement;
            break;
        case 2:
            table = ui->deleteElement;
            break;
    }
    int names[6];
    for(int i  =0; i < 6; i++){
        names[i] = table->item(i,1)->text().toInt();
        //check correct
    }
    //date_time::DateTime newdt(2001, date_time::Feb, 25, 7, 7, 0);
    //dt = newdt;
}


void PerformSetWindow::on_findButton_clicked()
{
    if(elementType == elementServer){
        auto element = getServerElement();
        fillElement(1,element);
        bool OK = findServerInSet(containerType, element);
        if(OK)
            ui->foundIndicator->setText("Found!");
        else
            ui->foundIndicator->setText("Not found...");
    } else {
        auto element = getDateTimeElement();
        fillElement(1,element);
        bool OK = findDateTimeInSet(containerType, element);//bool OK = findDateTimeInSet(containerType, element);
        if(OK)
            ui->foundIndicator->setText("Found!");
        else
            ui->foundIndicator->setText("Not found...");
    }

}


bool PerformSetWindow::findServerInSet(containType _t, Server s){
    if(_t == typeBalancedTree){
        auto x = setSplayServer.count(s);
        std::cout << x << std::endl;
        return x;
        //return false;//setSplayServer.count(s);
    }
    return true;
}

bool PerformSetWindow::findDateTimeInSet(containType _t, date_time::DateTime s){
    if(_t == typeBalancedTree){
     //   return setSplayServer.count(s);
        return setSplayDateTime.count(s);
    }
    return true;
}


void PerformSetWindow::on_insertButton_clicked()
{
    if(elementType == elementServer){
        auto element = getServerElement();
        fillElement(0,element);
        insertServerInSet(containerType, element);
    } else {
        auto element = getDateTimeElement();
        fillElement(0,element);
        insertDateTimeInSet(containerType, element);
    }
}

void PerformSetWindow::insertServerInSet(containType _t, Server s){
    if(_t == typeBalancedTree){
         setSplayServer.insert(s);
    }
}

void PerformSetWindow::insertDateTimeInSet(containType _t, date_time::DateTime s){
    if(_t == typeBalancedTree){
        setSplayDateTime.insert(s);
    }
}


void PerformSetWindow::on_deleteButton_clicked()
{
    if(elementType == elementServer){
        auto element = getServerElement();
        fillElement(2,element);
        deleteServerInSet(containerType, element);
    } else {
        auto element = getDateTimeElement();
        fillElement(2,element);
        deleteDateTimeInSet(containerType, element);
    }
}


void PerformSetWindow::deleteServerInSet(containType _t, Server s){
    if(_t == typeBalancedTree){
         setSplayServer.erase(s);
    }
}

void PerformSetWindow::deleteDateTimeInSet(containType _t, date_time::DateTime s){
    if(_t == typeBalancedTree){
        setSplayDateTime.erase(s);
    }
}




