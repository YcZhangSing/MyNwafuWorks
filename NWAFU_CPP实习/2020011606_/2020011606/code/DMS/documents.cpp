#include "documents.h"

Documents::Documents() {
}

Documents::Documents(QString num, QString name, std::vector<QString>& key, QString sum, QString date)
{
    Number = num;
    Name = name;
    std::vector<QString> Key = key;
    Summary = sum;
    Date = QDate::fromString(date);
}

void Documents::Display()
{}
