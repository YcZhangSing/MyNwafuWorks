/********************************************************************************
** Form generated from reading UI file 'addauthor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDAUTHOR_H
#define UI_ADDAUTHOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAuthor
{
public:
    QWidget *centralwidget;
    QLineEdit *name;
    QLabel *label;
    QLineEdit *unit;
    QLabel *label_3;
    QLabel *label_2;
    QComboBox *gender;
    QLabel *label_4;
    QComboBox *field;
    QPushButton *yes;
    QPushButton *cancle;
    QLabel *label_5;
    QLineEdit *emailEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddAuthor)
    {
        if (AddAuthor->objectName().isEmpty())
            AddAuthor->setObjectName(QString::fromUtf8("AddAuthor"));
        AddAuthor->resize(615, 394);
        centralwidget = new QWidget(AddAuthor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        name = new QLineEdit(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(240, 60, 113, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 60, 81, 21));
        unit = new QLineEdit(centralwidget);
        unit->setObjectName(QString::fromUtf8("unit"));
        unit->setGeometry(QRect(240, 130, 113, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 130, 81, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 100, 60, 16));
        gender = new QComboBox(centralwidget);
        gender->addItem(QString());
        gender->addItem(QString());
        gender->addItem(QString());
        gender->setObjectName(QString::fromUtf8("gender"));
        gender->setGeometry(QRect(235, 90, 124, 32));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(159, 170, 61, 20));
        field = new QComboBox(centralwidget);
        field->addItem(QString());
        field->addItem(QString());
        field->addItem(QString());
        field->addItem(QString());
        field->addItem(QString());
        field->setObjectName(QString::fromUtf8("field"));
        field->setGeometry(QRect(235, 160, 124, 32));
        yes = new QPushButton(centralwidget);
        yes->setObjectName(QString::fromUtf8("yes"));
        yes->setGeometry(QRect(150, 260, 113, 32));
        cancle = new QPushButton(centralwidget);
        cancle->setObjectName(QString::fromUtf8("cancle"));
        cancle->setGeometry(QRect(290, 260, 113, 32));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 210, 60, 16));
        emailEdit = new QLineEdit(centralwidget);
        emailEdit->setObjectName(QString::fromUtf8("emailEdit"));
        emailEdit->setGeometry(QRect(240, 210, 113, 21));
        AddAuthor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddAuthor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 615, 24));
        AddAuthor->setMenuBar(menubar);
        statusbar = new QStatusBar(AddAuthor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AddAuthor->setStatusBar(statusbar);

        retranslateUi(AddAuthor);
        QObject::connect(cancle, SIGNAL(clicked()), AddAuthor, SLOT(close()));

        QMetaObject::connectSlotsByName(AddAuthor);
    } // setupUi

    void retranslateUi(QMainWindow *AddAuthor)
    {
        AddAuthor->setWindowTitle(QApplication::translate("AddAuthor", "MainWindow", nullptr));
        label->setText(QApplication::translate("AddAuthor", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("AddAuthor", "\345\215\225\344\275\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("AddAuthor", "\346\200\247\345\210\253\357\274\232", nullptr));
        gender->setItemText(0, QApplication::translate("AddAuthor", "\347\224\267", nullptr));
        gender->setItemText(1, QApplication::translate("AddAuthor", "\345\245\263", nullptr));
        gender->setItemText(2, QApplication::translate("AddAuthor", "\345\205\266\344\273\226", nullptr));

        label_4->setText(QApplication::translate("AddAuthor", "\347\240\224\347\251\266\351\242\206\345\237\237:", nullptr));
        field->setItemText(0, QApplication::translate("AddAuthor", "\345\206\234\346\236\227\347\211\247\346\270\224\343\200\201\345\215\253\347\224\237\343\200\201\347\247\221\345\255\246\347\240\224\347\251\266", nullptr));
        field->setItemText(1, QApplication::translate("AddAuthor", "\345\273\272\347\255\221\343\200\201\350\203\275\346\272\220\343\200\201\345\206\266\347\202\274\343\200\201\344\272\244\351\200\232\350\277\220\350\276\223", nullptr));
        field->setItemText(2, QApplication::translate("AddAuthor", "\345\210\266\351\200\240\343\200\201\344\277\241\346\201\257\346\212\200\346\234\257\343\200\201\350\264\270\346\230\223", nullptr));
        field->setItemText(3, QApplication::translate("AddAuthor", "\345\205\232\346\224\277\343\200\201\347\244\276\345\233\242\343\200\201\345\233\275\351\230\262\343\200\201\346\263\225\345\276\213\343\200\201\351\207\221\350\236\215", nullptr));
        field->setItemText(4, QApplication::translate("AddAuthor", "\346\225\231\350\202\262\343\200\201\345\205\254\345\205\261\346\226\207\345\214\226\343\200\201\347\244\276\344\274\232\346\234\215\345\212\241", nullptr));

        yes->setText(QApplication::translate("AddAuthor", "\347\241\256\345\256\232", nullptr));
        cancle->setText(QApplication::translate("AddAuthor", "\345\217\226\346\266\210", nullptr));
        label_5->setText(QApplication::translate("AddAuthor", "Email:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddAuthor: public Ui_AddAuthor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDAUTHOR_H
