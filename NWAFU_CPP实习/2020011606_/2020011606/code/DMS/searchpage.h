#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QMainWindow>

namespace Ui {
class SearchPage;
}

class SearchPage : public QMainWindow
{
    Q_OBJECT

public:
    SearchPage(QWidget *parent = nullptr);
    ~SearchPage();
    Ui::SearchPage *ui;

private slots:
    void on_return_2_clicked();

    void on_yes_clicked();

};

#endif // SEARCHPAGE_H
