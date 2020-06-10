#include "performsetwindow.h"
#include "ui_performsetwindow.h"

Set<SplayTree<Server>> setSplayServer;
Set<SplayTree<date_time::DateTime>> setSplayDateTime;
Set<SingleLinkedOrderedList<Server>> set_SLO_List_Server;
Set<SingleLinkedOrderedList<date_time::DateTime>> set_SLO_List_DateTime;
CuckooHash<Server> setHashServer({Server{}});
CuckooHash<date_time::DateTime> setHashDateTime({date_time::DateTime{}});



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
    switch(index){
        case 0:
            elementType = elementServer;
            break;
        case 1:
            elementType = elementDateTime;
            break;
        default:
            elementType = elementServer;
        break;
    }
}

QString getName(QTableWidgetItem* it){
    if(!it)
        return "";
    else return it->text();
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

    s.IP = ip::address(convertIpToVector(table->item(0,1)->text().toStdString()));
    s.data_center = table->item(1,1)->text().toStdString();
    s.rack = table->item(2,1)->text().toStdString();
    s.company = table->item(3,1)->text().toStdString();
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
        names[i] = getName(table->item(i,1)).toInt();
        //check correct
    }
    date_time::DateTime newdt(names[0]-1, date_time::Month(names[1]-1), names[2]-1, names[3]-1, names[4]-1, names[5]-1);
    dt = newdt;
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
    }else if(_t == typeList){
        return set_SLO_List_Server.count(s);
    }
    else{
        return setHashServer.count(s);
    }
    return true;
}

bool PerformSetWindow::findDateTimeInSet(containType _t, date_time::DateTime s){
    if(_t == typeBalancedTree){
        return setSplayDateTime.count(s);
    }else if(_t == typeList){
        return set_SLO_List_DateTime.count(s);
    }else{
        return setHashDateTime.count(s);
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
    }else if(_t == typeList){
        set_SLO_List_Server.insert(s);
    }else{
        setHashServer.add(s);
    }
}

void PerformSetWindow::insertDateTimeInSet(containType _t, date_time::DateTime s){
    if(_t == typeBalancedTree){
        setSplayDateTime.insert(s);
    }else if(_t == typeList){
        set_SLO_List_DateTime.insert(s);
    }else{
        setHashDateTime.add(s);
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
    }else if(_t == typeList){
        set_SLO_List_Server.erase(s);
    }else{
        setHashServer.erase(s);
    }
}

void PerformSetWindow::deleteDateTimeInSet(containType _t, date_time::DateTime s){
    if(_t == typeBalancedTree){
        setSplayDateTime.erase(s);
    }else if(_t == typeList){
        set_SLO_List_DateTime.erase(s);
    }else{
        setHashDateTime.erase(s);
    }
}




