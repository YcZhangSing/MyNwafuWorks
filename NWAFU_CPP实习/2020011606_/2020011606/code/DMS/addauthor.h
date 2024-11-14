#ifndef ADDAUTHOR_H
#define ADDAUTHOR_H

#include <QMainWindow>

namespace Ui {
class AddAuthor;
}

class AddAuthor : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddAuthor(QWidget *parent = nullptr);
    ~AddAuthor();

private slots:
    void on_yes_clicked();

private:
    Ui::AddAuthor *ui;
};

#endif // ADDAUTHOR_H
