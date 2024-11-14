/********************************************************************************
** Form generated from reading UI file 'docnamepage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCNAMEPAGE_H
#define UI_DOCNAMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_docnamepage
{
public:
    QWidget *centralwidget;
    QListWidget *list;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *docnamepage)
    {
        if (docnamepage->objectName().isEmpty())
            docnamepage->setObjectName(QString::fromUtf8("docnamepage"));
        docnamepage->resize(614, 431);
        centralwidget = new QWidget(docnamepage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        list = new QListWidget(centralwidget);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(140, 20, 301, 231));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 320, 111, 41));
        docnamepage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(docnamepage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 614, 26));
        docnamepage->setMenuBar(menubar);
        statusbar = new QStatusBar(docnamepage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        docnamepage->setStatusBar(statusbar);

        retranslateUi(docnamepage);

        QMetaObject::connectSlotsByName(docnamepage);
    } // setupUi

    void retranslateUi(QMainWindow *docnamepage)
    {
        docnamepage->setWindowTitle(QApplication::translate("docnamepage", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("docnamepage", "\347\202\271\345\207\273\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class docnamepage: public Ui_docnamepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCNAMEPAGE_H
