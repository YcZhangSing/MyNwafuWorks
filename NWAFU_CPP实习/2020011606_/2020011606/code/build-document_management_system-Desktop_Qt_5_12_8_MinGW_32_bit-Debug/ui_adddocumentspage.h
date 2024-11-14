/********************************************************************************
** Form generated from reading UI file 'adddocumentspage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDOCUMENTSPAGE_H
#define UI_ADDDOCUMENTSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddDocumentsPage
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *nameOfDoc;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QLabel *label_6;
    QComboBox *comboBox;
    QPushButton *yesButton;
    QPushButton *cancelButton;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_8;
    QLineEdit *nameOfAuthors;
    QLabel *label_9;
    QLabel *sourceLabel;
    QLineEdit *sourceEdit;
    QComboBox *selectCombo;
    QLabel *label_7;
    QLabel *label_10;
    QLineEdit *sourceEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddDocumentsPage)
    {
        if (AddDocumentsPage->objectName().isEmpty())
            AddDocumentsPage->setObjectName(QString::fromUtf8("AddDocumentsPage"));
        AddDocumentsPage->resize(498, 413);
        centralwidget = new QWidget(AddDocumentsPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 110, 60, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 110, 113, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 150, 60, 16));
        nameOfDoc = new QLineEdit(centralwidget);
        nameOfDoc->setObjectName(QString::fromUtf8("nameOfDoc"));
        nameOfDoc->setGeometry(QRect(110, 150, 113, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 190, 60, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(280, 80, 60, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 40, 60, 16));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(350, 40, 110, 22));
        dateEdit->setDateTime(QDateTime(QDate(2021, 8, 17), QTime(0, 0, 0)));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(700, 500, 60, 16));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(780, 490, 91, 32));
        yesButton = new QPushButton(centralwidget);
        yesButton->setObjectName(QString::fromUtf8("yesButton"));
        yesButton->setGeometry(QRect(110, 310, 113, 32));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(290, 310, 113, 32));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(110, 190, 104, 71));
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(350, 70, 104, 71));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 30, 60, 16));
        nameOfAuthors = new QLineEdit(centralwidget);
        nameOfAuthors->setObjectName(QString::fromUtf8("nameOfAuthors"));
        nameOfAuthors->setGeometry(QRect(120, 30, 113, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 60, 251, 20));
        sourceLabel = new QLabel(centralwidget);
        sourceLabel->setObjectName(QString::fromUtf8("sourceLabel"));
        sourceLabel->setGeometry(QRect(700, 580, 81, 16));
        sourceEdit = new QLineEdit(centralwidget);
        sourceEdit->setObjectName(QString::fromUtf8("sourceEdit"));
        sourceEdit->setGeometry(QRect(790, 580, 113, 21));
        selectCombo = new QComboBox(centralwidget);
        selectCombo->setObjectName(QString::fromUtf8("selectCombo"));
        selectCombo->setGeometry(QRect(780, 540, 87, 22));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(700, 540, 72, 15));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(260, 190, 72, 15));
        sourceEdit_2 = new QLineEdit(centralwidget);
        sourceEdit_2->setObjectName(QString::fromUtf8("sourceEdit_2"));
        sourceEdit_2->setGeometry(QRect(350, 180, 113, 21));
        AddDocumentsPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddDocumentsPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 498, 26));
        AddDocumentsPage->setMenuBar(menubar);
        statusbar = new QStatusBar(AddDocumentsPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AddDocumentsPage->setStatusBar(statusbar);
        QWidget::setTabOrder(nameOfAuthors, lineEdit);
        QWidget::setTabOrder(lineEdit, nameOfDoc);
        QWidget::setTabOrder(nameOfDoc, plainTextEdit);
        QWidget::setTabOrder(plainTextEdit, dateEdit);
        QWidget::setTabOrder(dateEdit, comboBox);
        QWidget::setTabOrder(comboBox, plainTextEdit_2);
        QWidget::setTabOrder(plainTextEdit_2, yesButton);
        QWidget::setTabOrder(yesButton, cancelButton);

        retranslateUi(AddDocumentsPage);
        QObject::connect(cancelButton, SIGNAL(clicked()), AddDocumentsPage, SLOT(close()));

        QMetaObject::connectSlotsByName(AddDocumentsPage);
    } // setupUi

    void retranslateUi(QMainWindow *AddDocumentsPage)
    {
        AddDocumentsPage->setWindowTitle(QApplication::translate("AddDocumentsPage", "MainWindow", nullptr));
        label->setText(QApplication::translate("AddDocumentsPage", "\347\274\226\345\217\267:", nullptr));
        label_2->setText(QApplication::translate("AddDocumentsPage", "\351\242\230\347\233\256:", nullptr));
        label_3->setText(QApplication::translate("AddDocumentsPage", "\345\205\263\351\224\256\350\257\215:", nullptr));
        label_4->setText(QApplication::translate("AddDocumentsPage", "\346\221\230\350\246\201:", nullptr));
        label_5->setText(QApplication::translate("AddDocumentsPage", "\345\217\221\350\241\250\346\227\266\351\227\264:", nullptr));
        label_6->setText(QApplication::translate("AddDocumentsPage", "\346\235\245\346\272\220:", nullptr));
        yesButton->setText(QApplication::translate("AddDocumentsPage", "\347\241\256\350\256\244", nullptr));
        cancelButton->setText(QApplication::translate("AddDocumentsPage", "\345\217\226\346\266\210", nullptr));
        label_8->setText(QApplication::translate("AddDocumentsPage", "\344\275\234\350\200\205:", nullptr));
        label_9->setText(QApplication::translate("AddDocumentsPage", "\346\263\250\346\204\217:\344\275\234\350\200\205\345\246\202\346\234\211\345\244\232\344\270\252\357\274\214\350\257\267\347\224\250\347\251\272\346\240\274\351\232\224\345\274\200", nullptr));
        sourceLabel->setText(QApplication::translate("AddDocumentsPage", "\345\205\266\344\273\226\346\235\245\346\272\220:", nullptr));
        label_7->setText(QString());
        label_10->setText(QApplication::translate("AddDocumentsPage", "\346\235\245\346\272\220:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDocumentsPage: public Ui_AddDocumentsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDOCUMENTSPAGE_H
