#ifndef DOCNAMEPAGE_H
#define DOCNAMEPAGE_H
#include <QMainWindow>

namespace Ui {
class docnamepage;
}

class docnamepage : public QMainWindow
{
    Q_OBJECT

public:
    explicit docnamepage(QWidget *parent = nullptr);
    ~docnamepage();

    Ui::docnamepage *ui;

private slots:
    void on_pushButton_clicked();
};

#endif // DOCNAMEPAGE_H
