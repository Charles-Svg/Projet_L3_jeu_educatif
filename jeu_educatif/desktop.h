#ifndef DESKTOP_H
#define DESKTOP_H


#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>

#include "filewindow.h"
#include "file.h"
#include "directory.h"

class Desktop : public QMainWindow
{
    Q_OBJECT
public:
    explicit Desktop(QWidget *parent = nullptr);
    ~Desktop();

public slots:
    void addSubWindow(FileWindow *);

signals:


private:
QMdiArea* _zone;


};

#endif // DESKTOP_H
