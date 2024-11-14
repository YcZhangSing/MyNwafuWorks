#ifndef ADDAUTHORPAGE_H
#define ADDAUTHORPAGE_H

#include <QMainWindow>

namespace Ui {
class AddAuthorPage;
}

class AddAuthorPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddAuthorPage(QWidget *parent = nullptr);
    ~AddAuthorPage();

private:
    Ui::AddAuthorPage *ui;
};

#endif // ADDAUTHORPAGE_H
