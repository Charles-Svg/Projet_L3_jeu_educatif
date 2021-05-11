#ifndef EVENEMENTS_H
#define EVENEMENTS_H

#include <QEvent>
#include "directory.h"

//evenement personnalisé pour l'ouverture d'un dossier
class OpenDirEvent : public QEvent
{
public:
    OpenDirEvent(Directory *);

    static QEvent::Type type();
    Directory* sender();


private:
    static QEvent::Type MyType;
    Directory * _sender;
};


class ChangeFileWindowEvent : public QEvent
{
public :
    ChangeFileWindowEvent(Directory *);
    static QEvent::Type type();
    Directory* sender();

private:
    static QEvent::Type MyType;
    Directory * _sender;

};

class goPreviousEvent : public QEvent
{
public:
    goPreviousEvent(Directory*);
    static QEvent::Type type(){return MyType;}
    Directory* previousDir(){return _previousDir;}

private:
    static QEvent::Type MyType;
    Directory * _previousDir;
};


class OpenPyFileEvent : public QEvent
{
public:
    OpenPyFileEvent(PyFile*);
    static QEvent::Type type(){return MyType;}
    PyFile* sender(){return _sender;}
private:
    static QEvent::Type MyType;
    PyFile * _sender;
};


class OpenPdfFileEvent : public QEvent
{
public:
    OpenPdfFileEvent(PdfFile*);
    static QEvent::Type type(){return MyType;}
    PdfFile* sender(){return _sender;}
private:
    static QEvent::Type MyType;
    PdfFile * _sender;
};


#endif // EVENEMENTS_H
