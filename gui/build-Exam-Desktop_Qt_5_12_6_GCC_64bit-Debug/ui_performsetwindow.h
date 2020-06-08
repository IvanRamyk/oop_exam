/********************************************************************************
** Form generated from reading UI file 'performsetwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERFORMSETWINDOW_H
#define UI_PERFORMSETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PerformSetWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QFrame *line_2;
    QPushButton *insertButton;
    QPushButton *findButton;
    QPushButton *deleteButton;
    QTableWidget *insertElement;
    QTableWidget *findElement;
    QTableWidget *deleteElement;
    QLabel *foundIndicator;
    QLabel *functionalLlabel;
    QLabel *realisationLabel;
    QLabel *contextLabel;
    QPushButton *backButton;
    QComboBox *contentBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PerformSetWindow)
    {
        if (PerformSetWindow->objectName().isEmpty())
            PerformSetWindow->setObjectName(QString::fromUtf8("PerformSetWindow"));
        PerformSetWindow->resize(930, 600);
        centralwidget = new QWidget(PerformSetWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(300, 70, 20, 251));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(610, 70, 20, 251));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        insertButton = new QPushButton(centralwidget);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));
        insertButton->setGeometry(QRect(80, 40, 150, 40));
        findButton = new QPushButton(centralwidget);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        findButton->setGeometry(QRect(390, 40, 150, 40));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(700, 40, 150, 40));
        insertElement = new QTableWidget(centralwidget);
        if (insertElement->columnCount() < 2)
            insertElement->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        insertElement->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        insertElement->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        insertElement->setObjectName(QString::fromUtf8("insertElement"));
        insertElement->setGeometry(QRect(30, 100, 250, 203));
        findElement = new QTableWidget(centralwidget);
        if (findElement->columnCount() < 2)
            findElement->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        findElement->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        findElement->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        findElement->setObjectName(QString::fromUtf8("findElement"));
        findElement->setGeometry(QRect(340, 100, 250, 203));
        deleteElement = new QTableWidget(centralwidget);
        if (deleteElement->columnCount() < 2)
            deleteElement->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        deleteElement->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        deleteElement->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        deleteElement->setObjectName(QString::fromUtf8("deleteElement"));
        deleteElement->setGeometry(QRect(650, 100, 250, 203));
        foundIndicator = new QLabel(centralwidget);
        foundIndicator->setObjectName(QString::fromUtf8("foundIndicator"));
        foundIndicator->setGeometry(QRect(430, 330, 67, 17));
        functionalLlabel = new QLabel(centralwidget);
        functionalLlabel->setObjectName(QString::fromUtf8("functionalLlabel"));
        functionalLlabel->setGeometry(QRect(30, 370, 171, 17));
        realisationLabel = new QLabel(centralwidget);
        realisationLabel->setObjectName(QString::fromUtf8("realisationLabel"));
        realisationLabel->setGeometry(QRect(30, 410, 171, 17));
        contextLabel = new QLabel(centralwidget);
        contextLabel->setObjectName(QString::fromUtf8("contextLabel"));
        contextLabel->setGeometry(QRect(30, 450, 151, 17));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(30, 480, 100, 30));
        contentBox = new QComboBox(centralwidget);
        contentBox->addItem(QString());
        contentBox->addItem(QString());
        contentBox->setObjectName(QString::fromUtf8("contentBox"));
        contentBox->setGeometry(QRect(200, 445, 101, 25));
        PerformSetWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PerformSetWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 930, 22));
        PerformSetWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PerformSetWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PerformSetWindow->setStatusBar(statusbar);

        retranslateUi(PerformSetWindow);

        QMetaObject::connectSlotsByName(PerformSetWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PerformSetWindow)
    {
        PerformSetWindow->setWindowTitle(QApplication::translate("PerformSetWindow", "MainWindow", nullptr));
        insertButton->setText(QApplication::translate("PerformSetWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\320\270 \320\265\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        findButton->setText(QApplication::translate("PerformSetWindow", "\320\227\320\275\320\260\320\271\321\202\320\270 \320\265\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        deleteButton->setText(QApplication::translate("PerformSetWindow", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \320\265\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem = insertElement->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PerformSetWindow", "Field name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = insertElement->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PerformSetWindow", "Field Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = findElement->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("PerformSetWindow", "Field name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = findElement->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("PerformSetWindow", "Field Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = deleteElement->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("PerformSetWindow", "Field name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = deleteElement->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("PerformSetWindow", "Field Value", nullptr));
        foundIndicator->setText(QString());
        functionalLlabel->setText(QApplication::translate("PerformSetWindow", "\320\244\321\203\320\275\320\272\321\206\321\226\320\276\320\275\320\260\320\273: \320\274\320\275\320\276\320\266\320\270\320\275\320\260", nullptr));
        realisationLabel->setText(QApplication::translate("PerformSetWindow", "\320\240\320\265\320\260\320\273\321\226\320\267\320\260\321\206\321\226\321\217:", nullptr));
        contextLabel->setText(QApplication::translate("PerformSetWindow", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202\320\275\320\260 \320\276\320\261\320\273\320\260\321\201\321\202\321\214:", nullptr));
        backButton->setText(QApplication::translate("PerformSetWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        contentBox->setItemText(0, QApplication::translate("PerformSetWindow", "\320\241\320\265\321\200\320\262\320\265\321\200\320\270", nullptr));
        contentBox->setItemText(1, QApplication::translate("PerformSetWindow", "\320\224\320\260\321\202\320\260 \321\226 \321\207\320\260\321\201", nullptr));

    } // retranslateUi

};

namespace Ui {
    class PerformSetWindow: public Ui_PerformSetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERFORMSETWINDOW_H
