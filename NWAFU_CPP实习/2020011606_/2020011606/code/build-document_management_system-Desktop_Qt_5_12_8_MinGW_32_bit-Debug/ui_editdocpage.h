/********************************************************************************
** Form generated from reading UI file 'editdocpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDOCPAGE_H
#define UI_EDITDOCPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editDocPage
{
public:
    QWidget *centralwidget;
    QComboBox *docCombo;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label_3;
    QLineEdit *numberEdit;
    QLabel *label_4;
    QLineEdit *summaryEdit;
    QLabel *label_5;
    QLineEdit *keysEdit;
    QLabel *label_6;
    QDateEdit *dateEdit;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *comboBox;
    QLabel *sourceLabel;
    QLineEdit *sourceEdit;
    QPushButton *yesButton;
    QPushButton *cancelButton;
    QLabel *label;
    QLineEdit *sourceEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *editDocPage)
    {
        if (editDocPage->objectName().isEmpty())
            editDocPage->setObjectName(QString::fromUtf8("editDocPage"));
        editDocPage->resize(556, 403);
        centralwidget = new QWidget(editDocPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        docCombo = new QComboBox(centralwidget);
        docCombo->setObjectName(QString::fromUtf8("docCombo"));
        docCombo->setGeometry(QRect(240, 30, 221, 22));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 72, 15));
        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(80, 100, 113, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 150, 72, 15));
        numberEdit = new QLineEdit(centralwidget);
        numberEdit->setObjectName(QString::fromUtf8("numberEdit"));
        numberEdit->setGeometry(QRect(80, 150, 113, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 200, 72, 15));
        summaryEdit = new QLineEdit(centralwidget);
        summaryEdit->setObjectName(QString::fromUtf8("summaryEdit"));
        summaryEdit->setGeometry(QRect(80, 200, 111, 81));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(260, 90, 72, 15));
        keysEdit = new QLineEdit(centralwidget);
        keysEdit->setObjectName(QString::fromUtf8("keysEdit"));
        keysEdit->setGeometry(QRect(380, 90, 113, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(270, 240, 72, 15));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(370, 240, 110, 22));
        dateEdit->setDateTime(QDateTime(QDate(2021, 8, 23), QTime(0, 0, 0)));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 30, 201, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(700, 500, 72, 15));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(810, 500, 87, 22));
        sourceLabel = new QLabel(centralwidget);
        sourceLabel->setObjectName(QString::fromUtf8("sourceLabel"));
        sourceLabel->setGeometry(QRect(700, 560, 72, 15));
        sourceEdit = new QLineEdit(centralwidget);
        sourceEdit->setObjectName(QString::fromUtf8("sourceEdit"));
        sourceEdit->setGeometry(QRect(800, 560, 113, 21));
        yesButton = new QPushButton(centralwidget);
        yesButton->setObjectName(QString::fromUtf8("yesButton"));
        yesButton->setGeometry(QRect(150, 310, 93, 28));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(330, 310, 93, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 150, 72, 15));
        sourceEdit_2 = new QLineEdit(centralwidget);
        sourceEdit_2->setObjectName(QString::fromUtf8("sourceEdit_2"));
        sourceEdit_2->setGeometry(QRect(350, 160, 113, 21));
        editDocPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(editDocPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 556, 26));
        editDocPage->setMenuBar(menubar);
        statusbar = new QStatusBar(editDocPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        editDocPage->setStatusBar(statusbar);

        retranslateUi(editDocPage);
        QObject::connect(cancelButton, SIGNAL(clicked()), editDocPage, SLOT(close()));

        QMetaObject::connectSlotsByName(editDocPage);
    } // setupUi

    void retranslateUi(QMainWindow *editDocPage)
    {
        editDocPage->setWindowTitle(QApplication::translate("editDocPage", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("editDocPage", "\346\240\207\351\242\230:", nullptr));
        label_3->setText(QApplication::translate("editDocPage", "\347\274\226\345\217\267:", nullptr));
        label_4->setText(QApplication::translate("editDocPage", "\346\221\230\350\246\201:", nullptr));
        label_5->setText(QApplication::translate("editDocPage", "\345\205\263\351\224\256\345\255\227:", nullptr));
        label_6->setText(QApplication::translate("editDocPage", "\346\227\245\346\234\237:", nullptr));
        label_7->setText(QApplication::translate("editDocPage", "\351\200\211\346\213\251\350\246\201\347\274\226\350\276\221\347\232\204\350\256\272\346\226\207\346\240\207\351\242\230:", nullptr));
        label_8->setText(QApplication::translate("editDocPage", "\346\235\245\346\272\220:", nullptr));
        sourceLabel->setText(QApplication::translate("editDocPage", "\345\205\266\344\273\226\346\235\245\346\272\220:", nullptr));
        yesButton->setText(QApplication::translate("editDocPage", "\347\241\256\350\256\244", nullptr));
        cancelButton->setText(QApplication::translate("editDocPage", "\345\217\226\346\266\210", nullptr));
        label->setText(QApplication::translate("editDocPage", "\346\235\245\346\272\220:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editDocPage: public Ui_editDocPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDOCPAGE_H
