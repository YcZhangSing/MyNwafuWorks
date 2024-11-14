#include "addauthorpage.h"
#include "ui_addauthorpage.h"

AddAuthorPage::AddAuthorPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddAuthorPage)
{
    ui->setupUi(this);
}

AddAuthorPage::~AddAuthorPage()
{
    delete ui;
}
void AddAuthor::on_yes_clicked()
{
    a = new Author();
    a->Name = ui->name->text();
    a->Gender = ui->gender->currentText();
    a->Unit = ui->unit->text();
    a->Field = ui->field->currentText();
    author.append(a);
    this->close();
}
