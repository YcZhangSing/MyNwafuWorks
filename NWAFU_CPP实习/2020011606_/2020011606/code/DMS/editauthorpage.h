#ifndef EDITAUTHORPAGE_H
#define EDITAUTHORPAGE_H

#include <QMainWindow>

namespace Ui {
class EditAuthorPage;
}

class EditAuthorPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditAuthorPage(QWidget *parent = nullptr);
    ~EditAuthorPage();

private slots:
    void on_pushButton_clicked();

    void on_nameCombo_currentTextChanged(const QString &arg1);

    void on_removeButton_clicked();

    void on_deleteAuthor_clicked();

private:
    Ui::EditAuthorPage *ui;
};

#endif // EDITAUTHORPAGE_H
