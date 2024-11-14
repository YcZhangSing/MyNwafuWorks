/********************************************************************************
** Form generated from reading UI file 'managepage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEPAGE_H
#define UI_MANAGEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagePage
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QComboBox *select;
    QPushButton *pushButton_2;
    QPushButton *resumeButton;
    QPushButton *exitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManagePage)
    {
        if (ManagePage->objectName().isEmpty())
            ManagePage->setObjectName(QString::fromUtf8("ManagePage"));
        ManagePage->resize(419, 276);
        centralwidget = new QWidget(ManagePage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 50, 161, 31));
        select = new QComboBox(centralwidget);
        select->addItem(QString());
        select->addItem(QString());
        select->setObjectName(QString::fromUtf8("select"));
        select->setGeometry(QRect(50, 50, 131, 81));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 100, 161, 31));
        resumeButton = new QPushButton(centralwidget);
        resumeButton->setObjectName(QString::fromUtf8("resumeButton"));
        resumeButton->setGeometry(QRect(200, 170, 111, 31));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(70, 170, 111, 31));
        ManagePage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ManagePage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 419, 26));
        ManagePage->setMenuBar(menubar);
        statusbar = new QStatusBar(ManagePage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ManagePage->setStatusBar(statusbar);

        retranslateUi(ManagePage);
        QObject::connect(exitButton, SIGNAL(clicked()), ManagePage, SLOT(close()));

        QMetaObject::connectSlotsByName(ManagePage);
    } // setupUi

    void retranslateUi(QMainWindow *ManagePage)
    {
        ManagePage->setWindowTitle(QApplication::translate("ManagePage", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("ManagePage", "\346\267\273\345\212\240", nullptr));
        select->setItemText(0, QApplication::translate("ManagePage", "\344\275\234\350\200\205", nullptr));
        select->setItemText(1, QApplication::translate("ManagePage", "\346\226\207\347\214\256", nullptr));

        pushButton_2->setText(QApplication::translate("ManagePage", "\347\274\226\350\276\221", nullptr));
        resumeButton->setText(QApplication::translate("ManagePage", "\350\277\224\345\233\236", nullptr));
        exitButton->setText(QApplication::translate("ManagePage", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagePage: public Ui_ManagePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEPAGE_H
