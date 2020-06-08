/********************************************************************************
** Form generated from reading UI file 'sortwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTWINDOW_H
#define UI_SORTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SortWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *backButton;
    QPushButton *listButton;
    QPushButton *tableButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SortWindow)
    {
        if (SortWindow->objectName().isEmpty())
            SortWindow->setObjectName(QString::fromUtf8("SortWindow"));
        SortWindow->resize(800, 600);
        centralwidget = new QWidget(SortWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 50, 181, 17));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(330, 500, 141, 41));
        listButton = new QPushButton(centralwidget);
        listButton->setObjectName(QString::fromUtf8("listButton"));
        listButton->setGeometry(QRect(250, 150, 300, 100));
        tableButton = new QPushButton(centralwidget);
        tableButton->setObjectName(QString::fromUtf8("tableButton"));
        tableButton->setGeometry(QRect(250, 310, 300, 100));
        SortWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SortWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        SortWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SortWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SortWindow->setStatusBar(statusbar);

        retranslateUi(SortWindow);

        QMetaObject::connectSlotsByName(SortWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SortWindow)
    {
        SortWindow->setWindowTitle(QApplication::translate("SortWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("SortWindow", "\320\244\321\203\320\275\320\272\321\206\321\226\320\276\320\275\320\260\320\273: \321\201\320\276\321\200\321\202\321\203\320\262\320\260\320\275\320\275\321\217", nullptr));
        backButton->setText(QApplication::translate("SortWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        listButton->setText(QApplication::translate("SortWindow", "\320\241\320\277\320\270\321\201\320\272\320\270", nullptr));
        tableButton->setText(QApplication::translate("SortWindow", "\320\224\320\265\321\200\320\265\320\262\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SortWindow: public Ui_SortWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTWINDOW_H
