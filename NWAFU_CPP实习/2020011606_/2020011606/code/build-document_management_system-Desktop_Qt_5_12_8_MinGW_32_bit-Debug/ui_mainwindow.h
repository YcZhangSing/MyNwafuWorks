/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_DMS;
    QAction *action_2;
    QAction *action_4;
    QAction *actionAuthor;
    QWidget *centralwidget;
    QPushButton *searchButton;
    QPushButton *manageButton;
    QMenuBar *menubar;
    QMenu *menuDMS;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(428, 288);
        action_DMS = new QAction(MainWindow);
        action_DMS->setObjectName(QString::fromUtf8("action_DMS"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        actionAuthor = new QAction(MainWindow);
        actionAuthor->setObjectName(QString::fromUtf8("actionAuthor"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(140, 60, 140, 50));
        manageButton = new QPushButton(centralwidget);
        manageButton->setObjectName(QString::fromUtf8("manageButton"));
        manageButton->setGeometry(QRect(140, 150, 140, 50));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 428, 24));
        menuDMS = new QMenu(menubar);
        menuDMS->setObjectName(QString::fromUtf8("menuDMS"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuDMS->menuAction());
        menuDMS->addAction(action_DMS);
        menuDMS->addSeparator();
        menuDMS->addAction(action_2);
        menuDMS->addSeparator();
        menuDMS->addAction(action_4);

        retranslateUi(MainWindow);
        QObject::connect(action_4, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\254\242\350\277\216", nullptr));
        action_DMS->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216DMS", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        action_4->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actionAuthor->setText(QApplication::translate("MainWindow", "Author", nullptr));
        searchButton->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\351\241\271\347\233\256", nullptr));
        manageButton->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\351\241\271\347\233\256", nullptr));
        menuDMS->setTitle(QApplication::translate("MainWindow", "DMS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
