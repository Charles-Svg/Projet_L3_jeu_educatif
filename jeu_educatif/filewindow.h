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
    explicit FileWindow(Directory *); // parent=nullptr pour que ce soit une fenetre
    void moveEvent(QMoveEvent *event) override;
    ~FileWindow();


private:
    Directory * rootDir;

signals:


};

#endif // FILEWINDOW_H
