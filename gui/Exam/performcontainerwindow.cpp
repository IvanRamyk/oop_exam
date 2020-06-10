#include "performcontainerwindow.h"
#include "ui_performcontainerwindow.h"

Map<std::string, Server, SplayTree> mapSplayServer;
Map<std::string, date_time::DateTime, SplayTree> mapSplayDateTime;
Map<std::string, Server, SingleLinkedOrderedList> mapListServer;
Map<std::string, date_time::DateTime, SingleLinkedOrderedList> mapListDateTime;
//Map<std::string, Server, CuckooHash<Server>>setHashServer;
//Map<std::string, date_time::DateTime, CuckooHash<date_time::DateTime>> setHashDateTime;

PerformContainerWindow::PerformContainerWindow(containType _type, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PerformContainerWindow),
    containerType(_type)
{
    ui->setupUi(this);
    ui->insertElement->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->findElement->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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


void PerformContainerWindow::fillTable(int index){
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
        i++;
    }
    while(i >= n){
        ui->insertElement->removeRow(i);
        ui->findElement->removeRow(i);\
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
    }
}

QString getField(QTableWidgetItem* it){
    if(!it)
        return "";
    else return it->text();
}


void PerformContainerWindow::fillElement(Server &s){
    QTableWidget* table;
    ip::address aps(127,0,0,1);
    s.IP = aps;
    std::string name;
    table = ui->insertElement;


    s.IP = ip::address(convertIpToVector(table->item(0,1)->text().toStdString()));
    s.data_center = table->item(1,1)->text().toStdString();
    s.rack = table->item(2,1)->text().toStdString();
    s.company = table->item(3,1)->text().toStdString();

}

void PerformContainerWindow::fillElement(date_time::DateTime &dt){
    QTableWidget* table;

    table = ui->insertElement;

    int names[6];
    for(int i  =0; i < 6; i++){
        names[i] = getField(table->item(i,1)).toInt();
        //check correct
    }
    date_time::DateTime newdt(names[0]-1, date_time::Month(names[1]-1), names[2]-1, names[3]-1, names[4]-1, names[5]-1);
    dt = newdt;
}


PerformContainerWindow::~PerformContainerWindow()
{
    delete ui;
}


void PerformContainerWindow::on_backButton_clicked()
{
    emit ContainerWindowShow();
    this->close();
}

Server PerformContainerWindow::getServerElement(){
    Server s;
    return s;
}

date_time::DateTime PerformContainerWindow::getDateTimeElement(){
    date_time::DateTime dt;
    return dt;
}

std::pair<bool, Server> PerformContainerWindow::findServerInContainer(std::string key){
    std::pair<bool, Server> result = {false, Server()};
    if(containerType == typeBalancedTree){
        if(mapSplayServer.count(key))
            result = {true, mapSplayServer.getValue(key)};
    } else if (containerType == typeList){
        if(mapListServer.count(key))
            result = {true, mapListServer.getValue(key)};
    }


    return result;
}

std::pair<bool, date_time::DateTime> PerformContainerWindow::findDateTimeInContainer(std::string key){
    std::pair<bool, date_time::DateTime>  result = {false, date_time::DateTime()};
    if(containerType == typeBalancedTree){
        if(mapSplayDateTime.count(key))
            result = {true, mapSplayDateTime.getValue(key)};
    } else if (containerType == typeList){
        if(mapListDateTime.count(key))
            result = {true, mapListDateTime.getValue(key)};
    }
    return result;
}


void PerformContainerWindow::on_findButton_clicked()
{
    QTableWidgetItem* it;
    if(elementType == elementServer){
        currentKey = ui->findKey->toPlainText().toStdString();
        std::pair<bool, Server> pr = findServerInContainer(currentKey);
        if(!pr.first){
            ui->foundIndicator->setText("Not found...");
            for(int i = 0; i < ui->findElement->rowCount(); i++){
                it = new QTableWidgetItem("");
                it->setFlags(Qt::ItemIsEnabled);
                ui->findElement->setItem(i,1,it);
            }
        } else {
            Server* element = &pr.second;
            ui->foundIndicator->setText("Found!");
            QTableWidgetItem* it = new QTableWidgetItem(QString::fromStdString(element->IP.toString()));
            it->setFlags(Qt::ItemIsEnabled);
            ui->findElement->setItem(0,1,it);
            it = new QTableWidgetItem(QString::fromStdString(element->data_center));
            it->setFlags(Qt::ItemIsEnabled);
            ui->findElement->setItem(1,1,it);
            it = new QTableWidgetItem(QString::fromStdString(element->rack));
            it->setFlags(Qt::ItemIsEnabled);
            ui->findElement->setItem(2,1,it);
            it = new QTableWidgetItem(QString::fromStdString(element->company));
            it->setFlags(Qt::ItemIsEnabled);
            ui->findElement->setItem(3,1,it);
        }

    } else {
        currentKey = ui->findKey->toPlainText().toStdString();
        std::pair<bool, date_time::DateTime> pr = findDateTimeInContainer(currentKey);

        if(!pr.first){
            ui->foundIndicator->setText("Not found...");
            for(int i = 0; i < ui->findElement->rowCount(); i++){
                it = new QTableWidgetItem("");
                it->setFlags(Qt::ItemIsEnabled);
                ui->findElement->setItem(i,1,it);
            }
        } else {
            date_time::DateTime* element = &pr.second;
            ui->foundIndicator->setText("Found!");
            std::vector<int> dt = element->to_vector();

            for(int i = 0; i < 6; i++){
                it = new QTableWidgetItem(QString::fromStdString(std::to_string(dt[i]+1)));
                it->setFlags(Qt::ItemIsEnabled);
                ui->findElement->setItem(i,1,it);
            }
        }

    }

}



void PerformContainerWindow::on_insertButton_clicked()
{
    if(elementType == elementServer){
        auto element = getServerElement();
        fillElement(element);
        currentKey = ui->insertKey->toPlainText().toStdString();

        insertServerInContainer(containerType, currentKey, element);
    } else {
        auto element = getDateTimeElement();
        fillElement(element);
        currentKey = ui->insertKey->toPlainText().toStdString();

        insertDateTimeInContainer(containerType, currentKey, element);

    }
}

void PerformContainerWindow::insertServerInContainer(containType _t, std::string key, Server s){
    if(_t == typeBalancedTree){
        mapSplayServer.insert(key, s);
    }else if(_t == typeList){
        mapListServer.insert(key, s);
    }
}

void PerformContainerWindow::insertDateTimeInContainer(containType _t, std::string key, date_time::DateTime s){
    if(_t == typeBalancedTree){
        mapSplayDateTime.insert(key, s);
    }else if(_t == typeList){
        mapListDateTime.insert(key, s);
    }
}


void PerformContainerWindow::on_deleteButton_clicked()
{
    currentKey = ui->deleteKey->toPlainText().toStdString();

    if(elementType == elementServer){
        deleteServerInContainer(containerType, currentKey);
    } else {
        deleteDateTimeInContainer(containerType, currentKey);
    }
}


void PerformContainerWindow::deleteServerInContainer(containType _t, std::string key){
    if(_t == typeBalancedTree){
         mapSplayServer.erase(key);

    }else if(_t == typeList){
        mapListServer.erase(key);
    }
}

void PerformContainerWindow::deleteDateTimeInContainer(containType _t, std::string key){
    if(_t == typeBalancedTree){
        mapSplayDateTime.erase(key);
    }else if(_t == typeList){
        mapListDateTime.erase(key);
    }
}

void PerformContainerWindow::on_contentBox_activated(int index)
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
        std::cout << "WRONG!\n";
        break;
    }
}
