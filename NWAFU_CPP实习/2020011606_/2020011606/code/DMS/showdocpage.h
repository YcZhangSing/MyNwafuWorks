#ifndef SHOWDOCPAGE_H
#define SHOWDOCPAGE_H

#include <QMainWindow>

namespace Ui {
class showdocpage;
}

class showdocpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit showdocpage(QWidget *parent = nullptr);
    ~showdocpage();
    Ui::showdocpage *ui;

};

#endif // SHOWDOCPAGE_H
