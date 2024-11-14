#ifndef OBJECTS_H
#define OBJECTS_H
#include <QString>
#include <QString>
#include <vector>
#include <QDate>

class Documents
{
public:
    QString Number, Name;
    QString KeyWords;
    QString Summary;
    QDate Date;
    QString Source;
    Documents();
    Documents(QString num, QString name, QString key, QString sum, QString Date);
};

class Author
{
public:
    QString Name, Gender, Unit, Email, Field;
    QList<Documents*> docs;

    Author();
    Author(QString N, QString G, QString U, QString E, QString F);
};

class Bibliography
{
private:
    QString Number;
    QString Name;
    int Level;
    QString Explain;
    Bibliography* Next;
    std::vector<Documents> doc;
public:
    Bibliography();
    Bibliography(QString, QString, int, QString, Bibliography*);
};

class Conference
{
public:
    QString Number;
    QString Abbreviation;
    QString Name;
    QString Field;
    QString Location;
    QString PublishingUnit;
    QString UnitLocation;
    QString SearchType;
    QString Remarks;
    Conference();
    Conference(QString , QString , QString , QString , QString , QString , QString , QString , QString );
};

class Enclosure
{

public:
    QString Number;
    QString Name;
    QString whichDocuments;
    QString Content;

    Enclosure();
    Enclosure(QString, QString, QString, QString);
};

class Journals
{
public:
    QString Number;
    QString Name; //简称
    QString Field;
    QString PublishingUnit;
    QString UnitLocation;
    QString SearchType;
    double InfluenceFactor;
    QString Remarks;
    Journals();
    Journals(QString, QString, QString, QString, QString, QString, double, QString);
};


#endif // OBJECTS_H
