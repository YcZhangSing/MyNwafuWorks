#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addauthor.h"
#include "objects.h"

#include <QMainWindow>
#include <QLineEdit>
#include <QList>
#include <QPushButton>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMediaPlayer *player1;
    QMediaPlayer *player2;

private slots:
    void on_action_DMS_triggered();

    void on_manageButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
    QList<Author*> author;
};

void readData();
void writeData();

#endif // MAINWINDOW_H
