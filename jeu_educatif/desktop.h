#ifndef DESKTOP_H
#define DESKTOP_H


#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>

#include "fileview.h"
#include "directoryview.h"
#include "filewindow.h"
#include <QVector>

enum User {Prof,Eleve};

class Desktop : public QMainWindow
{
    Q_OBJECT
public:
    explicit Desktop(User u,QWidget *parent = nullptr);
    ~Desktop();
    bool event(QEvent* event) override;

public slots:
    void addSubWindow(Directory*);
    void changeSubWindow(Directory*);


private:
QMdiArea* _zone;
QVector<Abstractfile*> contenu;

//methode pour séparer le code
void addFilesProf();
void addFilesEleve();


};


#endif // DESKTOP_H
