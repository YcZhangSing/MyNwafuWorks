#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "managepage.h"
#include "searchpage.h"

#include <QMessageBox>
#include <QString>
#include <QLineEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //todo:文件读取放在这里
    ui->setupUi(this);
    qDebug() << "New" << endl;
    ui->manageButton->setIcon(QIcon(":/icons/icons/manage.ico"));
    ui->searchButton->setIcon(QIcon(":/icons/icons/search_.png"));
    player1=new QMediaPlayer;
    player2=new QMediaPlayer;
    player1->setMedia(QUrl("qrc:/click.mp3"));
    player1->setVolume(100);
    player2->setMedia(QUrl("qrc:/click.mp3"));
    player2->setVolume(100);
}

MainWindow::~MainWindow()
{
    qDebug() << "delete" << endl;
    writeData();
    delete ui;
}

void MainWindow::on_action_DMS_triggered()
{
    QMessageBox::about(this, "about", "Constructed by ZZQ and ZT\nVerson 1.0");
}

void MainWindow::on_manageButton_clicked()
{
    player1->play();
    ManagePage* mgp = new ManagePage();
    mgp->show();
    this->close();
}

void MainWindow::on_searchButton_clicked()
{
    player2->play();
    SearchPage* sear= new SearchPage();
    sear->show();
    this->close();
}
