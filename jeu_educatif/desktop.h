#ifndef DESKTOP_H
#define DESKTOP_H


#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>

#include "file.h"
#include "filewindow.h"


class Desktop : public QMainWindow
{
    Q_OBJECT
public:
    explicit Desktop(QWidget *parent = nullptr);
    ~Desktop();
    bool event(QEvent* event) override;

public slots:
    void addSubWindow(Directory*);

signals:


private:
QMdiArea* _zone;


};

#endif // DESKTOP_H
