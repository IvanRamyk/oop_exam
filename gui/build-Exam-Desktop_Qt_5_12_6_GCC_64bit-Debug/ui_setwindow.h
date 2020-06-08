/********************************************************************************
** Form generated from reading UI file 'setwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETWINDOW_H
#define UI_SETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *listButton;
    QPushButton *treeButton;
    QPushButton *tableButton;
    QPushButton *backButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SetWindow)
    {
        if (SetWindow->objectName().isEmpty())
            SetWindow->setObjectName(QString::fromUtf8("SetWindow"));
        SetWindow->resize(800, 600);
        centralwidget = new QWidget(SetWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 50, 171, 17));
        listButton = new QPushButton(centralwidget);
        listButton->setObjectName(QString::fromUtf8("listButton"));
        listButton->setGeometry(QRect(250, 110, 300, 100));
        treeButton = new QPushButton(centralwidget);
        treeButton->setObjectName(QString::fromUtf8("treeButton"));
        treeButton->setGeometry(QRect(250, 230, 300, 100));
        tableButton = new QPushButton(centralwidget);
        tableButton->setObjectName(QString::fromUtf8("tableButton"));
        tableButton->setGeometry(QRect(250, 350, 300, 100));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(330, 500, 141, 41));
        SetWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SetWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        SetWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SetWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SetWindow->setStatusBar(statusbar);

        retranslateUi(SetWindow);

        QMetaObject::connectSlotsByName(SetWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SetWindow)
    {
        SetWindow->setWindowTitle(QApplication::translate("SetWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("SetWindow", "\320\244\321\203\320\275\320\272\321\206\321\226\320\276\320\275\320\260\320\273: \320\274\320\275\320\276\320\266\320\270\320\275\320\260", nullptr));
        listButton->setText(QApplication::translate("SetWindow", "\320\241\320\277\320\270\321\201\320\272\320\270", nullptr));
        treeButton->setText(QApplication::translate("SetWindow", "\320\224\320\265\321\200\320\265\320\262\320\260", nullptr));
        tableButton->setText(QApplication::translate("SetWindow", "\320\223\320\265\321\210-\321\202\320\260\320\261\320\273\320\270\321\206\321\226", nullptr));
        backButton->setText(QApplication::translate("SetWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetWindow: public Ui_SetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETWINDOW_H
