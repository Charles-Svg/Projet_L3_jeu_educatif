#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include <QMdiArea>
#include <QMdiSubWindow>
#include <QIcon>
#include <QDebug>
#include <QMoveEvent>
#include <QCloseEvent>

class FileWindow : public QWidget
{
    Q_OBJECT
public:
    explicit FileWindow(QWidget * parent=nullptr); // parent=nullptr pour que ce soit une fenetre
    void moveEvent(QMoveEvent *event) override;


signals:


};

#endif // FILEWINDOW_H
