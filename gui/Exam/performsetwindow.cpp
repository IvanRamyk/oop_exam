#include "performsetwindow.h"
#include "ui_performsetwindow.h"


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

   /* if(containerType == typeList){
        set = nullptr;
    } else if(containerType == typeBalancedTree){
        if(elementType == elementServer){
            set = new SplayTree<Server>();
        } else{
            set = new SplayTree<date_time::Date>();
        }
    } else {
        set = nullptr;
    }*/

    //->horizontalHeader()->setResizeMode();//->setResizeMode(QHeaderView::Stretch);
}


PerformSetWindow::~PerformSetWindow()
{
   // delete set;
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

void PerformSetWindow::on_findButton_clicked()
{
    static int COUNTER = 0;
    if(COUNTER%2){
        ui->foundIndicator->setText("Found!");
    } else {
        ui->foundIndicator->setText("Not found...");
    }
    COUNTER++;

}


/*

void PerformSetWindow<setType, elemType>::on_findButton_clicked()
{
    elemType* elem = createNewElement(1);
    if(set->find(elem) != nullptr){
        ui->foundIndicator->setText("Found!");
    } else {
        ui->foundIndicator->setText("Not found...");
    }
}
*/
