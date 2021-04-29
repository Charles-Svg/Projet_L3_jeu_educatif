#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include <QWidget>
#include <QIcon>
#include <QDebug>
#include <QGridLayout>
#include <QHBoxLayout>
#include "directory.h"
#include "directoryview.h"
#include "fileview.h"

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
    QVector<AbstractfileView*> contenu;

signals:
    void goPrevious(Directory* parentDir);


};


#endif // FILEWINDOW_H
