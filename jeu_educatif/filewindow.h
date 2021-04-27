#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include <QWidget>
#include <QIcon>
#include <QDebug>
#include <QGridLayout>
#include <QHBoxLayout>
#include "directory.h"

class FileWindow : public QWidget
{
    Q_OBJECT
public:
    explicit FileWindow(Directory *,QWidget * desktop); // parent=nullptr pour que ce soit une fenetre
    ~FileWindow();



public slots:
    void goBack(bool);

private:
    Directory * rootDir;
    QHBoxLayout * layout;
    QWidget * desktop;

signals:
    void goPrevious(Directory* parentDir);


};
/*
class goPreviousEvent : public QEvent
{
public:
    goPreviousEvent(Directory*);
    static QEvent::Type type(){return MyType;}
    Directory* previousDir(){return _previousDir;}

private:
    static QEvent::Type MyType;
    Directory * _previousDir;
};*/

#endif // FILEWINDOW_H
