#include "objects.h"

Author::Author()
{
     Name = Gender = Unit = Email = Field = "UNDIFIED";
}
Author::Author(QString N, QString G, QString U, QString E, QString F) :
   Name(N), Gender(G), Unit(U), Email(E), Field(F) {}

Bibliography::Bibliography()
{

}

Bibliography::Bibliography(QString num, QString name, int level, QString explain, Bibliography* next)
{
    Number = num;
    Name = name;
    Level = level;
    Explain = explain;
    Next = next;
}
Conference::Conference()
{

}

Conference::Conference(QString num, QString abb, QString name, QString field,
                       QString location, QString publishing, QString unitlocation, QString search, QString remarks)
{
    Number = num;
    Abbreviation = abb;
    Name = name;
    Field = field;
    Location = location;
    PublishingUnit = publishing;
    UnitLocation = unitlocation;
    SearchType = search;
    Remarks = remarks;
}

Documents::Documents() {

}

Documents::Documents(QString num, QString name, QString key, QString sum, QString date)
{
    Number = num;
    Name = name;
    KeyWords = key;
    Summary = sum;
    Date = QDate::fromString(date);
}

Enclosure::Enclosure()
{
}

Enclosure::Enclosure(QString num, QString name, QString which, QString content)
{
    Number = num;
    Name = name;
    whichDocuments = which;
    Content = content;
}

Journals::Journals()
{

}

 Journals::Journals(QString num, QString abb, QString field, QString publishing, QString location,
                    QString search, double factor, QString remarks)
 {
     Number = num;
     Name = abb;
     Field = field;
     PublishingUnit = publishing;
     UnitLocation = location;
     SearchType = search;
     InfluenceFactor = factor;
     Remarks = remarks;
 }
