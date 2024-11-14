/********************************************************************************
** Form generated from reading UI file 'searchpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHPAGE_H
#define UI_SEARCHPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchPage
{
public:
    QWidget *centralwidget;
    QComboBox *select;
    QPushButton *return_2;
    QPushButton *yes;
    QLineEdit *text;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SearchPage)
    {
        if (SearchPage->objectName().isEmpty())
            SearchPage->setObjectName(QString::fromUtf8("SearchPage"));
        SearchPage->resize(666, 487);
        centralwidget = new QWidget(SearchPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        select = new QComboBox(centralwidget);
        select->addItem(QString());
        select->addItem(QString());
        select->addItem(QString());
        select->setObjectName(QString::fromUtf8("select"));
        select->setGeometry(QRect(80, 120, 131, 51));
        return_2 = new QPushButton(centralwidget);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(360, 290, 121, 51));
        yes = new QPushButton(centralwidget);
        yes->setObjectName(QString::fromUtf8("yes"));
        yes->setGeometry(QRect(160, 290, 121, 51));
        text = new QLineEdit(centralwidget);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(270, 110, 351, 71));
        SearchPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SearchPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 666, 26));
        SearchPage->setMenuBar(menubar);
        statusbar = new QStatusBar(SearchPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SearchPage->setStatusBar(statusbar);

        retranslateUi(SearchPage);

        QMetaObject::connectSlotsByName(SearchPage);
    } // setupUi

    void retranslateUi(QMainWindow *SearchPage)
    {
        SearchPage->setWindowTitle(QApplication::translate("SearchPage", "MainWindow", nullptr));
        select->setItemText(0, QApplication::translate("SearchPage", "\344\275\234\350\200\205", nullptr));
        select->setItemText(1, QApplication::translate("SearchPage", "\346\226\207\347\214\256\345\220\215", nullptr));
        select->setItemText(2, QApplication::translate("SearchPage", "\347\274\226\345\217\267", nullptr));

        return_2->setText(QApplication::translate("SearchPage", "\350\277\224\345\233\236", nullptr));
        yes->setText(QApplication::translate("SearchPage", "\346\243\200\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchPage: public Ui_SearchPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHPAGE_H
