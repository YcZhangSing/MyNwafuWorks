#include "mainwindow.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    readData();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
