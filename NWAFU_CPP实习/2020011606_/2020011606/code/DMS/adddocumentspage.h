#ifndef ADDDOCUMENTSPAGE_H
#define ADDDOCUMENTSPAGE_H

#include <QMainWindow>

namespace Ui {
class AddDocumentsPage;
}

class AddDocumentsPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddDocumentsPage(QWidget *parent = nullptr);
    ~AddDocumentsPage();

private slots:
    void on_yesButton_clicked();

    void on_comboBox_currentTextChanged(const QString &str);

    void on_selectCombo_currentIndexChanged(const QString &arg1);

private:
    Ui::AddDocumentsPage *ui;
};

#endif // ADDDOCUMENTSPAGE_H
