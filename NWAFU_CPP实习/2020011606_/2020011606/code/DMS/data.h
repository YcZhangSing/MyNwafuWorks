#ifndef DATA_H
#define DATA_H
#include "objects.h"

#include <QMap>

static QList<Author*> author;
static QList<Conference*> conference;
static QList<Documents*> documents;
static QList<Enclosure*> enclosure;
static QList<Journals*> journals;


static QMap<QString, Author*> nameToAuthor;
static QMap<QString, Conference*> nameToConference;
static QMap<QString, Documents*> nameToDocument;
static QMap<QString, Enclosure*> nameToEnclosure;
static QMap<QString, Journals*> nameToJournal;

//Author* a;
#endif // DATA_H
