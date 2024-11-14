#include "addauthor.h"
#include "ui_addauthor.h"
#include "mainwindow.h"

#include <QDebug>
#include <QByteArray>
#include <QDataStream>
#include <QMessageBox>
#include <sstream>
#include <string>
#include <iostream>

#include "data.h"
AddAuthor::AddAuthor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddAuthor)
{
    ui->setupUi(this);
    this->setWindowTitle("添加作者");
    ui->cancle->setIcon(QIcon(":/icons/icons/cancel.png"));
    ui->yes->setIcon(QIcon(":/icons/icons/yes.png"));
}

AddAuthor::~AddAuthor()
{
    delete ui;
}

void AddAuthor::on_yes_clicked()
{
    Author* a;
    if(nameToAuthor.contains(ui->name->text())) {
        QMessageBox::warning(this, "", "该作者已经存在!");
    }
    else {
       if(ui->name->text() == "" || ui->unit->text() == "") {
           QMessageBox::warning(this, "", "请输入正确的姓名/单位名称");
       }
       else {
          a = new Author();
          a->Name = ui->name->text();
          a->Gender = ui->gender->currentText();
          a->Unit = ui->unit->text();
          a->Field = ui->field->currentText();
          a->Email = ui->emailEdit->text();
          author.append(a);
          nameToAuthor[a->Name] = a;
          QMessageBox::information(this, "", "成功添加！");
       }
    }
    ui->name->clear();
    ui->unit->clear();
    ui->gender->setCurrentIndex(0);
    ui->field->setCurrentIndex(0);
    ui->emailEdit->clear();
}
/*****************************************************************************************/

#include "adddocumentspage.h"
#include "ui_adddocumentspage.h"

AddDocumentsPage::AddDocumentsPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddDocumentsPage)
{
    ui->setupUi(this);
    this->setWindowTitle("添加文献");
    ui->yesButton->setIcon(QIcon(":/icons/icons/yes.png"));
    ui->cancelButton->setIcon(QIcon(":/icons/icons/cancel.png"));
    ui->comboBox->addItem("学术会议");
    ui->comboBox->addItem("学术期刊");
    ui->sourceLabel->hide();
    ui->sourceEdit->hide();
    ui->selectCombo->hide();
}

AddDocumentsPage::~AddDocumentsPage()
{
    delete ui;
}

void AddDocumentsPage::on_yesButton_clicked()
{
    Author* a;
    //todo: 完善论文相关信息
    Documents* doc = new Documents();
//    qDebug() << "First" << endl;
    std::stringstream ss;
    std::string str = ui->nameOfAuthors->text().toStdString();
//    qDebug() << "Second" << endl;
    ss << str;
    std::string tmp;
    QString name = "init";
    doc->Name = ui->nameOfDoc->text();
    while(true) {
        tmp = "";
        ss >> tmp;
        name = QString::fromStdString(tmp);
        qDebug() << name << endl;
        if(name == "") break;
        if(nameToAuthor.contains(name)) {
            Author* a = nameToAuthor[name];
            a->docs.append(doc);
        }
        else {
            a = new Author();
            a->Name = name;
            a->Unit = "Undefied";
            a->docs.append(doc);
            author.append(a);
            nameToAuthor[name] = a;
        }
    }
    doc->Number = ui->lineEdit->text();
    doc->Date = ui->dateEdit->date();
    doc->KeyWords = ui->plainTextEdit->toPlainText();
    doc->Summary = ui->plainTextEdit_2->toPlainText();
    doc->Source = ui->sourceEdit_2->text();
    //    if(ui->comboBox->currentText() == "学术周刊") {
    //       if(ui->selectCombo->currentText() == "其他") {
    //         Journals* j = new Journals();
    //       j->Name = ui->sourceEdit->text();
    //     journals.append(j);
    //   nameToJournal[j->Name] = j;
    // doc->Source = j->Name;
    //}
    //else
    // doc->Source = ui->selectCombo->currentText();
    //}
    //else if(ui->comboBox->currentText() == "学术会议"){
    //  if(ui->selectCombo->currentText() == "其他") {
    //    Conference* c = new Conference();
    //  c->Name = ui->sourceEdit->text();
    //conference.append(c);
    //  nameToConference[c->Name] = c;
    //doc->Source = c->Name;
    //  }
    //   else
    //      doc->Source = ui->selectCombo->currentText();
    //}
    documents.append(doc);
    nameToDocument[doc->Name] = doc;
    this->close();
}

void AddDocumentsPage::on_comboBox_currentTextChanged(const QString &str) {
    ui->selectCombo->clear();
    if(str == "学术会议") {
        QList<Conference*>::iterator it = conference.begin();
        for(; it != conference.end(); it++) {
            QString str = (*it)->Name;
            ui->selectCombo->addItem(str);
        }
        ui->selectCombo->addItem("其他");
    }
    else if(str == "学术期刊") {
        QList<Journals*>::iterator it2 = journals.begin();
        for(;it2 != journals.end(); it2++) {
            QString str = (*it2)->Name;
            ui->selectCombo->addItem(str);
        }
        ui->selectCombo->addItem("其他");
    }
    else qDebug() << "Something went wrong" << endl;
    ui->selectCombo->show();

}
void AddDocumentsPage::on_selectCombo_currentIndexChanged(const QString &str) {
    if(str == "其他") {
        ui->sourceLabel->show();
        ui->sourceEdit->show();
    }
    else {
        ui->sourceLabel->hide();
        ui->sourceEdit->hide();
    }
}
/*****************************************************************************************/

#include "editauthorpage.h"
#include "ui_editauthorpage.h"

EditAuthorPage::EditAuthorPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditAuthorPage)
{
    ui->setupUi(this);
    this->setWindowTitle("编辑项目");
    ui->pushButton->setIcon(QIcon(":/icons/icons/yes.png"));
    ui->cancelButton->setIcon(QIcon(":/icons/icons/cancel.png"));
    ui->removeButton->setIcon(QIcon(":/icons/icons/delete.png"));
    QList<Author*>::iterator it;
    for(it = author.begin(); it != author.end(); it++) {
        ui->nameCombo->addItem((*it)->Name);
    }
    qDebug() << "EditAuthorPage Constrected" << endl;
}

EditAuthorPage::~EditAuthorPage()
{
    delete ui;
}

void EditAuthorPage::on_pushButton_clicked() {
    QString AuthorName = ui->nameCombo->currentText();
    QMap<QString, Author*>::iterator it;
    if(nameToAuthor.contains(ui->nameCombo->currentText())) {
       it = nameToAuthor.find(AuthorName);
       Author* a = nameToAuthor[AuthorName];
       a->Name = ui->nameEdit->text();
       a->Gender = ui->genderCombo->currentText();
       a->Unit = ui->unitEdit->text();
       a->Field = ui->fieldCombo->currentText();
       a->Email = ui->emailEdit->text();
//       author.append(a);
       nameToAuthor.erase(it);
       nameToAuthor[a->Name] = a;
       QMessageBox::information(this, "", "成功修改该作者");
       this->close();
    }
    else {
        QMessageBox::warning(this, "", "请先至少添加一个作者");
        qDebug() << "请先至少添加一个作者" << endl;
    }
}

void EditAuthorPage::on_nameCombo_currentTextChanged(const QString &AuthorName) {
    if(AuthorName == "") {
        ui->nameEdit->clear();
        ui->unitEdit->clear();
        ui->emailEdit->clear();
        return;
    }
    ui->documentsListView->clear();
    QMap<QString, Author*>::iterator it;
    it = nameToAuthor.find(AuthorName);
    qDebug() << "p1" << endl;
    ui->nameEdit->setText((*it)->Name);
    ui->unitEdit->setText((*it)->Unit);
    ui->emailEdit->setText((*it)->Email);
    QString curGender = (*it)->Gender;
    QString curField = (*it)->Field;
    for(int i = 0; i < ui->genderCombo->count(); i++) {
        if(curGender == ui->genderCombo->itemText(i)) {
            ui->genderCombo->setCurrentIndex(i);
            break;
        }
    }
    for(int i = 0; i < ui->fieldCombo->count(); i++) {
        if(curField == ui->fieldCombo->itemText(i)) {
            ui->fieldCombo->setCurrentIndex(i);
            break;
        }
    }
    QList<Documents*>::iterator it2;
    qDebug() << (*it)->docs.size() << endl;
    for(it2 = (*it)->docs.begin(); it2 != (*it)->docs.end(); it2++) {
//        qDebug() << "itemAdded" << endl;
        ui->documentsListView->addItem((*it2)->Name);
    }
}

void EditAuthorPage::on_removeButton_clicked() {
    //todo: 从记录中移除所选文献
    //当前实现，从作者的库中删除文献
    if(ui->documentsListView->count() == 0) {
        QMessageBox::information(this, "", "当前系统无作者或当前作者还未添加论文！");
    }
    else if(ui->documentsListView->currentItem() == NULL){
        QMessageBox::warning(this, "", "请选择文献");
    }
    else {
       QString docName = ui->documentsListView->currentItem()->text(); //获取当前的论文题目
       qDebug() << docName << endl;
       QList<Documents*>::iterator it;
       Author* a = nameToAuthor[ui->nameCombo->currentText()];
       bool flag = false;
       for(it = a->docs.begin(); it != a->docs.end(); it++) {
          if((*it)->Name == docName) {
             flag = true;
             a->docs.erase(it);
         ui->documentsListView->removeItemWidget(
                     ui->documentsListView->currentItem());
             break;
          }
       }
       if(flag)
          QMessageBox::information(this, "", "移除成功！");
       else QMessageBox::warning(this, "", "出错了!");
    }
}
void EditAuthorPage::on_deleteAuthor_clicked() {
    //todo: 删除作者记录
    if(ui->nameCombo->currentText() == "") {
        QMessageBox::warning(this, "", "当前系统中无作者!");
        return;
    }
    QList<Author*>::iterator itA;
    QList<Documents*>::iterator itD;
    qDebug() << ui->nameCombo->currentText() << endl;
    for(itA = author.begin(); itA != author.end(); itA++)
        if((*itA)->Name == ui->nameCombo->currentText()) {
            author.erase(itA);
            break;
        }
    QMap<QString, Author*>::iterator mpA;
    mpA = nameToAuthor.find(ui->nameCombo->currentText());
    nameToAuthor.erase(mpA);
    ui->nameCombo->removeItem(ui->nameCombo->currentIndex());
    QMessageBox::information(this, "", "删除成功!");
}

/*****************************************************************************************/
//ManagePage构造函数和槽函数的实现
#include "managepage.h"
#include "ui_managepage.h"

#include "editdocpage.h"

ManagePage::ManagePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagePage)
{
    ui->setupUi(this);
    this->setWindowTitle("管理项目");
    ui->pushButton_2->setIcon(QIcon(":/icons/icons/e.png"));
    ui->pushButton->setIcon(QIcon(":/icons/icons/add.png"));
    ui->resumeButton->setIcon(QIcon(":/icons/icons/resume.png"));
    ui->exitButton->setIcon(QIcon(":/icons/icons/close.png"));
}

ManagePage::~ManagePage()
{
    delete ui;
}

void ManagePage::on_pushButton_clicked()
{
    int x = ui->select->currentIndex();
    AddAuthor* add = new AddAuthor(this);
    AddDocumentsPage* add2 = new AddDocumentsPage(this);
    switch (x) {
       case 0:
            add->show();
            break;
       case 1:
            add2->show();
            break;
       qDebug() << "Error" << endl;
    }

}

void ManagePage::on_pushButton_2_clicked()
{
    int x = ui->select->currentIndex();
    EditAuthorPage* edA = new EditAuthorPage();
    editDocPage* edD = new editDocPage();
    switch (x) {
        case 0:
        edA->show();
        break;
        case 1:
        edD->show();
        break;
    }

}
void ManagePage::on_resumeButton_clicked() {
    MainWindow* w = new MainWindow();
    w->show();
    this->close();
}

/*****************************************************************************************/
#include "mainwindow.h"

#include <QFile>
#include <QDir>

void writeData()
{
    qDebug() << "Write" << endl;
    QFile file(QDir::currentPath()+"/save.txt");
    file.open(QIODevice::WriteOnly);
    qDebug() << QDir::currentPath() << endl;
    QTextStream ss(&file);
    QList<Author*>::iterator itA;
    QList<Documents*>::iterator itD;
    ss << "AuthorBegin" << endl;
    for(itA = author.begin(); itA != author.end(); ++itA) { //将author链表内的数据存放在文件中
        ss << (*itA)->Name << " ";
        ss << (*itA)->Gender << " ";
        ss << (*itA)->Unit << " ";
        ss << (*itA)->Field << " ";
        ss << (*itA)->Email << endl;
        ss << "DocsOfAuthorBegin" << endl;
        for(itD = (*itA)->docs.begin(); itD != (*itA)->docs.end(); ++itD) {
            ss << (*itD)->Name << " ";
        }
        ss << endl << "DocsOfAuthorEnd" << endl;
    }
    ss << endl << "AuthorEnd" << endl;

    //文档信息的存放
    ss << "DocBegin" << endl;
    for(itD = documents.begin(); itD != documents.end(); itD++) {
        ss << (*itD)->Name << " ";
        ss << (*itD)->Number << " ";
        ss << (*itD)->Summary << " ";
        ss << (*itD)->KeyWords << " ";
        ss << (*itD)->Date.toString("yyyyMMdd") << " ";
        ss << (*itD)->Source << " ";
    }
    ss << endl <<  "DocEnd" << endl;
}

void readData()
{
    //todo: 完善读取操作
    QFile file(QDir::currentPath() + "/save.txt");
    if(file.exists()) {
        qDebug() << "Read" << endl;
        Author* a;
        Documents* d;
        file.open(QIODevice::ReadOnly);
        QTextStream ss(&file);
        QString str = "init";
        ss >> str;
        Q_ASSERT(str == "AuthorBegin");
        ss >> str;
        while(str != "AuthorEnd") {
            a = new Author();
            a->Name = str;
            ss >> str;
            a->Gender = str;
            ss >> str;
            a->Unit = str;
            ss >> str;
            a->Field = str;
            ss >> str;
            a->Email = str;
            ss >> str;
            Q_ASSERT(str == "DocsOfAuthorBegin");
            ss >> str;
            while(str!= "DocsOfAuthorEnd") {
                d = new Documents();
                d->Name = str;
                ss >> str;
                a->docs.append(d);
                nameToDocument[d->Name] = d;
            }
            ss >> str;
            author.append(a);
            nameToAuthor[a->Name] = a;
        }
        qDebug() << "Author records has been resumed" << endl;
        ss >> str;
        Q_ASSERT(str == "DocBegin");
        ss >> str;
        while(str != "DocEnd") {
            d = nameToDocument[str];
            if(d == NULL) {
                d = new Documents();
                nameToDocument[str] = d;
            }
            documents.append(d);
            d->Name = str;
            ss >> str;
            d->Number = str;
            ss >> str;
            d->Summary = str;
            ss >> str;
            d->KeyWords = str;
            ss >> str;
            d->Date = QDate::fromString(str, "yyyyMMdd");
            ss >> str;
            qDebug() << str << endl;
            d->Source = str;
            ss >> str;
//            qDebug() << str << endl;
        }
    }
    else {
        qDebug() << "Init the file"<< endl;
    }
}


//now
#include "searchpage.h"
#include "ui_searchpage.h"
#include "docnamepage.h"
#include "docnamepage.h"
#include "ui_docnamepage.h"
#include "showdocpage.h"
#include "ui_showdocpage.h"
SearchPage::SearchPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchPage)
{
    ui->setupUi(this);
    ui->yes->setIcon(QIcon(":icons/icons/search_.png"));
    ui->return_2->setIcon(QIcon(":icons/icons/resume.png"));
}

SearchPage::~SearchPage()
{
    delete ui;
}


showdocpage::showdocpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showdocpage)
{
    ui->setupUi(this);
}

showdocpage::~showdocpage()
{
    delete ui;
}



//void SearchPage::on_return_2_clicked()
//{
//    MainWindow *win=new MainWindow();
//    win->show();
//    this->close();
//}
//void SearchPage::on_yes_clicked()
//{
//    int y=ui->select->currentIndex();
//    if(y==0){
//        docnamepage * doc=new docnamepage();
//        QString t=ui->text->text();
//        QMap<QString, Author*>::iterator it;
//        it = nameToAuthor.find(t);
//        QList<Documents*>::iterator i;
//        for(i=(*it)->docs.begin(); i!=(*it)->docs.end();i++){
//           doc->ui->list->addItem((*i)->Name);
//        }
//        doc->show();
//        this->close();
//    }
//    else if(y==1){
//        showdocpage *sh=new showdocpage();
//        QString s=ui->text->text();
//        QMap<QString, Documents*>::iterator r;
//        r=nameToDocument.find(s);
//        sh->ui->label->setText((*r)->Name);
//        sh->ui->label2->setText((*r)->Number);
//        sh->show();
//        this->close();
//    }

//}
void SearchPage::on_return_2_clicked()
{
    MainWindow *win=new MainWindow();
    win->show();
    this->close();
}
void SearchPage::on_yes_clicked()
{
    int y=ui->select->currentIndex();
    if(y==0){
        docnamepage * doc=new docnamepage();
        QString t=ui->text->text();
        if(t == "") {
            QMessageBox::warning(this, "", "请输入正确信息！");
        }
        else {
        QMap<QString, Author*>::iterator it;
        it = nameToAuthor.find(t);
        if(it == nameToAuthor.end()) {
            QMessageBox::warning(this, "", "无该作者!");
        }
        else {
        QList<Documents*>::iterator i;
        for(i=(*it)->docs.begin(); i!=(*it)->docs.end();i++){
           doc->ui->list->addItem((*i)->Name);
        }
        doc->show();
//        this->close();
        }
        }
    }
    else if(y==1){
        showdocpage *sh=new showdocpage();
        QString s=ui->text->text();
        if(s==""){
            QMessageBox::warning(this, "", "请输入正确信息！");
        }
        else{
        QMap<QString, Documents*>::iterator r;
        r=nameToDocument.find(s);
        if(r==nameToDocument.end()){
            QMessageBox::warning(this,"","无该文献！");
        }else{
        sh->ui->label->setText((*r)->Name);
        sh->ui->label2->setText((*r)->Number);
        sh->ui->label3->setText((*r)->Summary);
        sh->ui->label4->setText((*r)->KeyWords);
        sh->ui->label5->setText((*r)->Date.toString());
        sh->show();
        }
    }
    }
    else if(y==2){
        showdocpage *p=new showdocpage();
        QString s=ui->text->text();
        QList<Documents*>::iterator t;
        int flag=0;
        for(t=documents.begin();t!=documents.end();t++){
            if(s==(*t)->Number){
                flag=1;
                p->ui->label->setText((*t)->Name);
                p->ui->label2->setText((*t)->Number);
                p->ui->label3->setText((*t)->Summary);
                p->ui->label4->setText((*t)->KeyWords);
                p->ui->label5->setText((*t)->Date.toString());
                p->show();
                break;

            }
            else{

//                QMessageBox::warning(this,"","无该编号文献");
            }        
        }
        if(flag==0){
            QMessageBox::warning(this,"","无该编号文献");

        }
    }

}

#include "docnamepage.h"
#include <QListWidget>
void docnamepage::on_pushButton_clicked(){
    QString docName = ui->list->currentItem()->text();
    showdocpage *s=new showdocpage;
    s->show();
    QMap<QString, Documents*>::iterator r;
    r=nameToDocument.find(docName);
    s->ui->label->setText((*r)->Name);
    s->ui->label2->setText((*r)->Number);
    s->ui->label3->setText((*r)->Summary);
    s->ui->label4->setText((*r)->KeyWords);
    s->ui->label5->setText((*r)->Date.toString());

}


docnamepage::docnamepage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::docnamepage)
{
    ui->setupUi(this);
}

docnamepage::~docnamepage()
{
    delete ui;
}




/*****************************************************************************************/
#include "editdocpage.h"
#include "ui_editdocpage.h"

editDocPage::editDocPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editDocPage)
{
    ui->setupUi(this);
    ui->yesButton->setIcon(QIcon(":/icons/icons/yes.png"));
    ui->cancelButton->setIcon(QIcon(":/icons/icons/cancel.png"));
    this->setWindowTitle("编辑论文");
    QList<Documents*>::iterator itD;
    for(itD = documents.begin(); itD != documents.end(); itD++) {
        ui->docCombo->addItem((*itD)->Name);
    }
    ui->sourceLabel->hide();
    ui->sourceEdit->hide();
    QList<Conference*>::iterator it = conference.begin();
    for(; it != conference.end(); it++) {
        QString str = (*it)->Name;
        ui->comboBox->addItem(str);
    }
    QList<Journals*>::iterator it2 = journals.begin();
    for(;it2 != journals.end(); it2++) {
        QString str = (*it2)->Name;
        ui->comboBox->addItem(str);
    }
    ui->comboBox->insertItem(-1, "其他");
    qDebug() << "Edit Author " << endl;
}

editDocPage::~editDocPage()
{
    delete ui;
}

void editDocPage::on_comboBox_currentTextChanged(const QString &str) {
    if(str == "其他") {
        qDebug() << "entered" << endl;
        ui->sourceEdit->show();
        ui->sourceLabel->show();
    }
    else {
        ui->sourceEdit->hide();
        ui->sourceLabel->hide();
    }
}

void editDocPage::on_docCombo_currentTextChanged(const QString &str) {
    Documents* doc = nameToDocument[str];
    ui->nameEdit->setText(doc->Name);
    ui->numberEdit->setText(doc->Number);
    ui->keysEdit->setText(doc->KeyWords);
    ui->summaryEdit->setText(doc->Summary);
    ui->sourceEdit_2->setText(doc->Source);
    ui->dateEdit->setDate(doc->Date);
//    QString source = doc->Source;
//    if(nameToJournal.contains(doc->Source)) {
//        ui->comboBox->setCurrentIndex(0);
//    }
//    else if(nameToConference.contains(doc->Source)) {
//        ui->comboBox->setCurrentIndex(1);
//    }
//    else qDebug() << "Something went wrong" << endl;
}

void editDocPage::on_yesButton_clicked() {
    QString DocName = ui->docCombo->currentText();
    QMap<QString, Documents*>::iterator it;
    if(nameToDocument.contains(DocName)) {
        it = nameToDocument.find(DocName);
        Documents* doc = nameToDocument[ui->docCombo->currentText()];
        doc->Name = ui->nameEdit->text();
        doc->Number = ui->numberEdit->text();
        doc->Summary = ui->summaryEdit->text();
        doc->KeyWords = ui->keysEdit->text();
        doc->Source = ui->sourceEdit_2->text();
        doc->Date = ui->dateEdit->date();
//        if(ui->comboBox->currentText() == "其他") {
//            doc->Source = ui->sourceEdit->text();
//        }
//        else {
//            doc->Source = ui->comboBox->currentText();
//        }
        nameToDocument.erase(it);
        nameToDocument[doc->Name] = doc;
        QMessageBox::information(this, "提示", "成功修改！");
    }
    else {
        qDebug() << "something went wrong" << endl;
        QMessageBox::warning(this, "警告", "当前系统中不存在文献！");
    }
}
