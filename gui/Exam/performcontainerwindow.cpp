#include "performcontainerwindow.h"
#include "ui_performcontainerwindow.h"

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

    s.data_center = getField(table->item(1,1)).toStdString();
    s.rack = getField(table->item(2,1)).toStdString();

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

Server* PerformContainerWindow::findServerInContainer(containType _t, std::string key){
    return nullptr;
}

date_time::DateTime* PerformContainerWindow::findDateTimeInContainer(containType _t, std::string key){
    return nullptr;
}


void PerformContainerWindow::on_findButton_clicked()
{
    if(elementType == elementServer){
        currentKey = ui->findKey->toPlainText().toStdString();
        Server* element = findServerInContainer(containerType, currentKey);
        if(element == nullptr){
            ui->foundIndicator->setText("Not found...");
        } else {
            ui->foundIndicator->setText("Found!");
            QTableWidgetItem* it = new QTableWidgetItem(QString::fromStdString(element->IP.toString()));
            ui->findElement->setItem(0,0,it);
            it = new QTableWidgetItem(QString::fromStdString(element->data_center));
            ui->findElement->setItem(0,1,it);
            it = new QTableWidgetItem(QString::fromStdString(element->rack));
            ui->findElement->setItem(0,2,it);
            it = new QTableWidgetItem(QString::fromStdString(element->company));
            ui->findElement->setItem(0,3,it);
        }

    } else {
        currentKey = ui->findKey->toPlainText().toStdString();
        date_time::DateTime* element = findDateTimeInContainer(containerType, currentKey);
        if(element == nullptr){
            ui->foundIndicator->setText("Not found...");
        } else {
            ui->foundIndicator->setText("Found!");
            std::vector<int> dt = element->to_vector();
            QTableWidgetItem* it;
            for(int i = 0; i < 6; i++){
                it = new QTableWidgetItem(QString::fromStdString(std::to_string(dt[i]+1)));
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

        std::cout << "1" << std::endl;// setSplayServer.insert(s);
    }else if(_t == typeList){

        std::cout << "2" << std::endl;// set_SLO_List_Server.insert(s);
    }
}

void PerformContainerWindow::insertDateTimeInContainer(containType _t, std::string key, date_time::DateTime s){
    if(_t == typeBalancedTree){

        std::cout << "1" << std::endl;// setSplayDateTime.insert(s);
    }else if(_t == typeList){

        std::cout << "2" << std::endl;//set_SLO_List_DateTime.insert(s);
    }
}


void PerformContainerWindow::on_deleteButton_clicked()
{
    currentKey = ui->findKey->toPlainText().toStdString();

    if(elementType == elementServer){
        currentKey = ui->findKey->toPlainText().toStdString();

    } else {
    }
}


void PerformContainerWindow::deleteServerInContainer(containType _t, Server elem){
    if(_t == typeBalancedTree){
         std::cout << "1" << std::endl;

    }else if(_t == typeList){

        std::cout << "2" << std::endl;
        //set_SLO_List_Server.erase(s);
    }
}

void PerformContainerWindow::deleteDateTimeInContainer(containType _t, date_time::DateTime elem){
    if(_t == typeBalancedTree){

        std::cout << "1" << std::endl;//setSplayDateTime.erase(s);
    }else if(_t == typeList){

        std::cout << "1" << std::endl;
//        set_SLO_List_DateTime.erase(s);
    }
}
