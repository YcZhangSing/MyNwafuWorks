/********************************************************************************
** Form generated from reading UI file 'showdocpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWDOCPAGE_H
#define UI_SHOWDOCPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showdocpage
{
public:
    QWidget *centralwidget;
    QLabel *label3;
    QLabel *label5;
    QLabel *label2;
    QLabel *label;
    QLabel *label4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *showdocpage)
    {
        if (showdocpage->objectName().isEmpty())
            showdocpage->setObjectName(QString::fromUtf8("showdocpage"));
        showdocpage->resize(524, 377);
        centralwidget = new QWidget(showdocpage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label3 = new QLabel(centralwidget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(180, 150, 141, 51));
        label5 = new QLabel(centralwidget);
        label5->setObjectName(QString::fromUtf8("label5"));
        label5->setGeometry(QRect(180, 270, 281, 51));
        label2 = new QLabel(centralwidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(180, 90, 171, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 30, 181, 51));
        label4 = new QLabel(centralwidget);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(180, 210, 131, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 40, 72, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 110, 72, 15));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 170, 72, 15));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 230, 72, 15));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 290, 72, 15));
        showdocpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(showdocpage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 524, 26));
        showdocpage->setMenuBar(menubar);
        statusbar = new QStatusBar(showdocpage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        showdocpage->setStatusBar(statusbar);

        retranslateUi(showdocpage);

        QMetaObject::connectSlotsByName(showdocpage);
    } // setupUi

    void retranslateUi(QMainWindow *showdocpage)
    {
        showdocpage->setWindowTitle(QApplication::translate("showdocpage", "MainWindow", nullptr));
        label3->setText(QString());
        label5->setText(QString());
        label2->setText(QString());
        label->setText(QString());
        label4->setText(QString());
        label_2->setText(QApplication::translate("showdocpage", "\346\226\207\347\214\256\345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("showdocpage", "\347\274\226\345\217\267\357\274\232", nullptr));
        label_4->setText(QApplication::translate("showdocpage", "\345\205\263\351\224\256\350\257\215\357\274\232", nullptr));
        label_5->setText(QApplication::translate("showdocpage", "\346\221\230\350\246\201\357\274\232", nullptr));
        label_6->setText(QApplication::translate("showdocpage", "\346\227\245\346\234\237\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showdocpage: public Ui_showdocpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWDOCPAGE_H
