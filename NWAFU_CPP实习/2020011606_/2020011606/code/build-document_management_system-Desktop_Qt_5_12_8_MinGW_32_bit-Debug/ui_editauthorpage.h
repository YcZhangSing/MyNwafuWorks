/********************************************************************************
** Form generated from reading UI file 'editauthorpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITAUTHORPAGE_H
#define UI_EDITAUTHORPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditAuthorPage
{
public:
    QWidget *centralwidget;
    QComboBox *nameCombo;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QComboBox *genderCombo;
    QLabel *label_3;
    QLineEdit *unitEdit;
    QLabel *label_4;
    QComboBox *fieldCombo;
    QPushButton *pushButton;
    QPushButton *cancelButton;
    QListWidget *documentsListView;
    QLabel *label_5;
    QPushButton *removeButton;
    QLabel *label_6;
    QLineEdit *emailEdit;
    QPushButton *deleteAuthor;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EditAuthorPage)
    {
        if (EditAuthorPage->objectName().isEmpty())
            EditAuthorPage->setObjectName(QString::fromUtf8("EditAuthorPage"));
        EditAuthorPage->resize(545, 421);
        centralwidget = new QWidget(EditAuthorPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        nameCombo = new QComboBox(centralwidget);
        nameCombo->setObjectName(QString::fromUtf8("nameCombo"));
        nameCombo->setGeometry(QRect(40, 40, 91, 32));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 90, 60, 16));
        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(100, 90, 113, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 130, 60, 16));
        genderCombo = new QComboBox(centralwidget);
        genderCombo->addItem(QString());
        genderCombo->addItem(QString());
        genderCombo->addItem(QString());
        genderCombo->setObjectName(QString::fromUtf8("genderCombo"));
        genderCombo->setGeometry(QRect(100, 120, 111, 32));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 170, 60, 16));
        unitEdit = new QLineEdit(centralwidget);
        unitEdit->setObjectName(QString::fromUtf8("unitEdit"));
        unitEdit->setGeometry(QRect(100, 170, 113, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 210, 60, 16));
        fieldCombo = new QComboBox(centralwidget);
        fieldCombo->addItem(QString());
        fieldCombo->addItem(QString());
        fieldCombo->addItem(QString());
        fieldCombo->addItem(QString());
        fieldCombo->addItem(QString());
        fieldCombo->setObjectName(QString::fromUtf8("fieldCombo"));
        fieldCombo->setGeometry(QRect(120, 200, 91, 32));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 330, 113, 32));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(300, 330, 113, 32));
        documentsListView = new QListWidget(centralwidget);
        documentsListView->setObjectName(QString::fromUtf8("documentsListView"));
        documentsListView->setGeometry(QRect(230, 40, 261, 211));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(239, 16, 261, 20));
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setGeometry(QRect(360, 210, 121, 41));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 240, 60, 16));
        emailEdit = new QLineEdit(centralwidget);
        emailEdit->setObjectName(QString::fromUtf8("emailEdit"));
        emailEdit->setGeometry(QRect(100, 240, 113, 21));
        deleteAuthor = new QPushButton(centralwidget);
        deleteAuthor->setObjectName(QString::fromUtf8("deleteAuthor"));
        deleteAuthor->setGeometry(QRect(80, 280, 331, 28));
        EditAuthorPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EditAuthorPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 545, 26));
        EditAuthorPage->setMenuBar(menubar);
        statusbar = new QStatusBar(EditAuthorPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EditAuthorPage->setStatusBar(statusbar);

        retranslateUi(EditAuthorPage);
        QObject::connect(cancelButton, SIGNAL(clicked()), EditAuthorPage, SLOT(close()));

        QMetaObject::connectSlotsByName(EditAuthorPage);
    } // setupUi

    void retranslateUi(QMainWindow *EditAuthorPage)
    {
        EditAuthorPage->setWindowTitle(QApplication::translate("EditAuthorPage", "MainWindow", nullptr));
        label->setText(QApplication::translate("EditAuthorPage", "\345\247\223\345\220\215:", nullptr));
        label_2->setText(QApplication::translate("EditAuthorPage", "\346\200\247\345\210\253:", nullptr));
        genderCombo->setItemText(0, QApplication::translate("EditAuthorPage", "\347\224\267", nullptr));
        genderCombo->setItemText(1, QApplication::translate("EditAuthorPage", "\345\245\263", nullptr));
        genderCombo->setItemText(2, QApplication::translate("EditAuthorPage", "\345\205\266\344\273\226", nullptr));

        label_3->setText(QApplication::translate("EditAuthorPage", "\345\215\225\344\275\215:", nullptr));
        label_4->setText(QApplication::translate("EditAuthorPage", "\347\240\224\347\251\266\351\242\206\345\237\237:", nullptr));
        fieldCombo->setItemText(0, QApplication::translate("EditAuthorPage", "\345\206\234\346\236\227\347\211\247\346\270\224\343\200\201\345\215\253\347\224\237\343\200\201\347\247\221\345\255\246\347\240\224\347\251\266", nullptr));
        fieldCombo->setItemText(1, QApplication::translate("EditAuthorPage", "\345\273\272\347\255\221\343\200\201\350\203\275\346\272\220\343\200\201\345\206\266\347\202\274\343\200\201\344\272\244\351\200\232\350\277\220\350\276\223", nullptr));
        fieldCombo->setItemText(2, QApplication::translate("EditAuthorPage", "\345\210\266\351\200\240\343\200\201\344\277\241\346\201\257\346\212\200\346\234\257\343\200\201\350\264\270\346\230\223", nullptr));
        fieldCombo->setItemText(3, QApplication::translate("EditAuthorPage", "\345\205\232\346\224\277\343\200\201\347\244\276\345\233\242\343\200\201\345\233\275\351\230\262\343\200\201\346\263\225\345\276\213\343\200\201\351\207\221\350\236\215", nullptr));
        fieldCombo->setItemText(4, QApplication::translate("EditAuthorPage", "\346\225\231\350\202\262\343\200\201\345\205\254\345\205\261\346\226\207\345\214\226\343\200\201\347\244\276\344\274\232\346\234\215\345\212\241", nullptr));

        pushButton->setText(QApplication::translate("EditAuthorPage", "\347\241\256\350\256\244", nullptr));
        cancelButton->setText(QApplication::translate("EditAuthorPage", "\345\217\226\346\266\210", nullptr));
        label_5->setText(QApplication::translate("EditAuthorPage", "\346\213\245\346\234\211\346\210\226\345\217\202\344\270\216\347\232\204\346\226\207\347\214\256", nullptr));
        removeButton->setText(QApplication::translate("EditAuthorPage", "\347\247\273\351\231\244", nullptr));
        label_6->setText(QApplication::translate("EditAuthorPage", "Email:", nullptr));
        deleteAuthor->setText(QApplication::translate("EditAuthorPage", "\345\210\240\351\231\244\350\257\245\344\275\234\350\200\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditAuthorPage: public Ui_EditAuthorPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITAUTHORPAGE_H
