#include "sortwindow.h"
#include "ui_sortwindow.h"

#define dateTimeFunc std::function<bool(date_time::DateTime, date_time::DateTime)>

SortWindow::SortWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SortWindow)
{
    {
        ui->setupUi(this);
        ui->insertElement->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        fillTable(0);
        this->elementType = elementServer;
    }
}



void SortWindow::fillTable(int index){
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
        i++;
    }
    while(i >= n){
        ui->insertElement->removeRow(i);
        i--;
    }
    QTableWidgetItem* it;
    for(int j = 0; j < n; j++){
        it = new QTableWidgetItem(names[j]);
        it->setFlags(Qt::ItemIsEnabled);
        ui->insertElement->setItem(j,0,it);
    }
}

SortWindow::~SortWindow()
{
    delete ui;
}

void SortWindow::on_listButton_clicked()
{

}

void SortWindow::on_tableButton_clicked()
{

}

QString getValue(QTableWidgetItem* it){
    if(!it)
        return "";
    return it->text();
}

void SortWindow::fillElement(Server& s){
    auto table = ui->insertElement;
    ip::address aps(1,2,3,4);
    s.IP = aps;
    s.data_center = getValue(table->item(1,1)).toStdString();
    s.rack = getValue(table->item(2,1)).toStdString();
    s.company = getValue(table->item(3,1)).toStdString();
}

void SortWindow::fillElement(date_time::DateTime& dt){
    auto table = ui->insertElement;
    int names[6];
    for(int i  =0; i < 6; i++){
        names[i] = getValue(table->item(i,1)).toInt();
        //check correct
    }
    date_time::DateTime newdt(names[0]-1, date_time::Month(names[1]-1), names[2]-1, names[3]-1, names[4]-1, names[5]-1);
    dt = newdt;
}

void SortWindow::on_insertButton_clicked()
{
    if(elementType == elementServer){
        auto element = Server();
        fillElement(element);
        insertServerInTable(element);
    } else {
        auto element = date_time::DateTime();
        fillElement(element);
        insertDateTimeInTable(element);
    }
}

void SortWindow::on_backButton_clicked()
{
    this->close();
    emit mainWindowShow();
}

void SortWindow::on_backButton_2_clicked()
{
    this->close();
    emit mainWindowShow();
}


void SortWindow::insertServerInTable(Server s){
    int n = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(n);
    QString id = QString::fromStdString(std::to_string(n + 1));
    QTableWidgetItem* it = new QTableWidgetItem(id);
    ui->tableWidget->setItem(n,0, it);
    it = new QTableWidgetItem(QString::fromStdString(s.IP.toString()));
    ui->tableWidget->setItem(n,1, it);
    it = new QTableWidgetItem(QString::fromStdString(s.data_center));
    ui->tableWidget->setItem(n,2, it);
    it = new QTableWidgetItem(QString::fromStdString(s.rack));
    ui->tableWidget->setItem(n,3, it);
    it = new QTableWidgetItem(QString::fromStdString(s.company));
    ui->tableWidget->setItem(n,4, it);
}

void SortWindow::insertDateTimeInTable(date_time::DateTime dt){
    int n = ui->tableWidget->rowCount();
    int m = ui->tableWidget->columnCount();
    std::vector<int> date_time_vector = dt.to_vector();
    ui->tableWidget->insertRow(n);
    QTableWidgetItem* it = new QTableWidgetItem(QString::fromStdString(std::to_string(n)));
    ui->tableWidget->setItem(n,0, it);
    for(int j = 0; j < m; j++){
        it = new QTableWidgetItem(QString::fromStdString(std::to_string(date_time_vector[j])));
        ui->tableWidget->setItem(n, j, it);
    }
}

void SortWindow::on_ipRadio_clicked()
{

}

void SortWindow::on_DataCenterRadio_clicked()
{

}

void SortWindow::on_RackRadio_clicked()
{

}

void SortWindow::on_CompanyRadio_clicked()
{

}

void SortWindow::on_contentBox_activated(int index)
{

}

void SortWindow::on_contentBox_activated(const QString &arg1)
{
    ui->tableWidget->clear();
    QTableWidget* table = ui->tableWidget;
    int n;



    if(arg1 == "Сервери"){
       // ui->sortingParamether->clear();
        ui->sortingParamether->setItemText(0,"Hello");
        fillTable(0);
        elementType = elementServer;
        n = 4;
   }else {
        n = 6;
        fillTable(1);
        ui->sortingParamether->setItemText(0,"DateTime");
        elementType = elementDateTime;
    }
    table->setColumnCount(n);

    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //else{

//    }
    std::vector<QString> serverHeaders = {"IP", "Data center", "Rack", "Company"};
    std::vector<QString> dateTimeHeaders = { "year", "month", "day", "hour", "minute", "second"};


    if(arg1 == "Сервери"){
        for (int col = 0; col < serverHeaders.size(); ++col) {
                auto hitem = new QTableWidgetItem;
                hitem->setText(serverHeaders[col]);
                table->setHorizontalHeaderItem(col, hitem);
                table->model()->setHeaderData(col, Qt::Horizontal, serverHeaders[col], Qt::DisplayRole);
        }
        for(int i = 0; i < 4; i++)
        ui->sortingParamether->setItemText(i,serverHeaders[i]);
        ui->sortingParamether->setMaxCount(4);



    }else if(arg1 == "Дата і час"){
        for (int col = 0; col < dateTimeHeaders.size(); ++col) {
                auto hitem = new QTableWidgetItem;
                hitem->setText(dateTimeHeaders[col]);
                table->setHorizontalHeaderItem(col, hitem);
                table->model()->setHeaderData(col, Qt::Horizontal, dateTimeHeaders[col], Qt::DisplayRole);
        }
        ui->sortingParamether->setMaxCount(6);
        ui->sortingParamether->addItem(dateTimeHeaders[4]);
        ui->sortingParamether->addItem(dateTimeHeaders[5]);
        for(int i = 0; i < 6; i++)
            ui->sortingParamether->setItemText(i,dateTimeHeaders[i]);
    }
        else{
            std::cout << arg1.toStdString();
        }
}

std::map <QString, std::function<bool(Server, Server)>> lambdaMapServer = {
    {"IP", [](Server a, Server b){ return  a.IP < b.IP;}},
    {"Data center", [](Server a, Server b){ return  a.data_center < b.data_center;}},
    {"Rack", [](Server a, Server b){ return  a.rack < b.rack;}},
    {"Company", [](Server a, Server b){ return  a.company < b.company;}}
        };

std::map <QString, dateTimeFunc> lambdaMapDateTime = {
        {"years", [](date_time::DateTime a, date_time::DateTime b){ auto va = a.to_vector(); auto vb = b.to_vector(); return  va[0] < vb[0];}},
    {"month", [](date_time::DateTime a, date_time::DateTime b){ auto va = a.to_vector(); auto vb = b.to_vector(); return  va[1] < vb[1];}},
    {"days", [](date_time::DateTime a, date_time::DateTime b){ auto va = a.to_vector(); auto vb = b.to_vector(); return  va[2] < vb[2];}},
    {"hours", [](date_time::DateTime a, date_time::DateTime b){ auto va = a.to_vector(); auto vb = b.to_vector(); return  va[3] < vb[3];}},
    {"minutes", [](date_time::DateTime a, date_time::DateTime b){ auto va = a.to_vector(); auto vb = b.to_vector(); return  va[4] < vb[4];}},
    {"seconds", [](date_time::DateTime a, date_time::DateTime b){ auto va = a.to_vector(); auto vb = b.to_vector(); return  va[5] < vb[5];}},
        };



std::vector<Server> SortWindow::getVectorServer(){
    std::vector<Server> result;
    auto table = ui->tableWidget;
    int n = table->rowCount();
    for(int i = 0; i < n; i++){
        ip::address ad(convertIpToVector(table->item(i,0)->text().toStdString()));
        std::string s1 = table->item(i,1)->text().toStdString();
        std::string s2 = table->item(i,2)->text().toStdString();
        std::string s3 = table->item(i,3)->text().toStdString();
        Server s(ad, s2, s1, s3);
        result.push_back(s);
    }
    return result;
}

void SortWindow::setVectorServer(std::vector<Server> res){
    auto table = ui->tableWidget;
    int n = table->rowCount();
    QTableWidgetItem* it;
    for(int i = 0; i < n; i++){
        //QString qs = QString
        it = new QTableWidgetItem(QString::fromStdString(res[i].IP.toString()));
        table->setItem(i,0, it);
        it = new QTableWidgetItem(QString::fromStdString(res[i].data_center));
        table->setItem(i,1, it);
        it = new QTableWidgetItem(QString::fromStdString(res[i].rack));
        table->setItem(i,2, it);
        it = new QTableWidgetItem(QString::fromStdString(res[i].company));
        table->setItem(i,3, it);
    }
}

int stringToInt(std::string s){
    int val = 0;
    int n = s.length();
    for(int i = 0; i < n; i++){
        if(!isdigit(s[i]))
            return 0;
        else{
            val *= 10;
            val += s[i] - '0';
        }
    }
    return val;
}

std::vector<date_time::DateTime> SortWindow::getVectorDateTime(){
    std::vector<date_time::DateTime> result;
    auto table = ui->tableWidget;
    int n = table->rowCount();
    for(int i = 0; i < n; i++){
        std::vector <int> s(6,0);
        s[0] = stringToInt(table->item(i,0)->text().toStdString());
        s[1] = stringToInt(table->item(i,1)->text().toStdString());
        s[2] = stringToInt(table->item(i,2)->text().toStdString());
        s[3] = stringToInt(table->item(i,3)->text().toStdString());
        s[4] = stringToInt(table->item(i,4)->text().toStdString());
        s[5] = stringToInt(table->item(i,5)->text().toStdString());
        date_time::DateTime dt(s[0], date_time::Month(s[1]), s[2], s[3], s[4], s[5]);
        result.push_back(dt);
    }
    return result;
}

void SortWindow::setVectorDateTime(std::vector<date_time::DateTime> res){
    auto table = ui->tableWidget;
    int n = table->rowCount();
    QTableWidgetItem* it;
    for(int i = 0; i < n; i++){
        auto vectorTime = res[i].to_vector();
        for(int j = 0; j < 6; j++){
            it = new QTableWidgetItem(QString::fromStdString(std::to_string(vectorTime[j])));
            table->setItem(i,0, it);
        }
    }
}


void SortWindow::on_sortButton_clicked()
{
    if(elementType == elementServer){
        auto lambda = lambdaMapServer[ui->sortingParamether->currentText()];
        std::vector<Server> vec = getVectorServer();
            Sort<Server> sort(vec);
            sort.selectionSort(lambda);
        auto res = sort.getData();
        setVectorServer(res);
    } else {
        auto lambda = lambdaMapDateTime[ui->sortingParamether->currentText()];
        auto vec = getVectorDateTime();
            Sort<date_time::DateTime> sort(vec);
            sort.selectionSort(lambda);
        auto res = sort.getData();
        setVectorDateTime(res);
    }


}
