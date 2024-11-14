#ifndef EDITDOCPAGE_H
#define EDITDOCPAGE_H

#include <QMainWindow>

namespace Ui {
class editDocPage;
}

class editDocPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit editDocPage(QWidget *parent = nullptr);
    ~editDocPage();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_docCombo_currentTextChanged(const QString &arg1);

    void on_yesButton_clicked();

private:
    Ui::editDocPage *ui;
};

#endif // EDITDOCPAGE_H
