#ifndef DOCUMENTS_H
#define DOCUMENTS_H
#include <QString>
#include <vector>
#include <QDate>
#include "object.h"

class Documents : Object
{
public:
    QString Number, Name;
    std::vector<QString> KeyWords;
    QString Summary;
    QDate Date;
    Documents();
    Documents(QString num, QString name, std::vector<QString>& key, QString sum, QString Date);
    void Display() override;
};

#endif
