#ifndef MANAGEPAGE_H
#define MANAGEPAGE_H

#include <QMainWindow>

namespace Ui {
class ManagePage;
}

class ManagePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagePage(QWidget *parent = nullptr);
    ~ManagePage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_resumeButton_clicked();

private:
    Ui::ManagePage *ui;
};

#endif // MANAGEPAGE_H
