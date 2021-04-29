#ifndef DESKTOP_H
#define DESKTOP_H


#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>

#include "fileview.h"
#include "directoryview.h"
#include "filewindow.h"
#include <QVector>

class Desktop : public QMainWindow
{
    Q_OBJECT
public:
    explicit Desktop(QWidget *parent = nullptr);
    ~Desktop();
    bool event(QEvent* event) override;

public slots:
    void addSubWindow(Directory*);
    void changeSubWindow(Directory*);


private:
QMdiArea* _zone;
QVector<Abstractfile*> contenu;


};

#endif // DESKTOP_H
