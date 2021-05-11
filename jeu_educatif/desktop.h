#ifndef DESKTOP_H
#define DESKTOP_H


#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>

#include "fileview.h"
#include "directoryview.h"
#include "filewindow.h"
#include "idewindow.h"
#include "fakepdfviewer.h"
#include <QVector>

enum User {Prof,Eleve};

class Desktop : public QMdiArea
{
    Q_OBJECT
public:
    explicit Desktop(User u,QWidget *parent = nullptr);
    ~Desktop();
    bool event(QEvent* event) override;

public slots:
    void ajouteSubWindow(Directory*);
    void changeSubWindow(Directory*);
    void ajoutePyFileWindow(PyFile*);
    void ajoutePdfFileWindow(PdfFile*);

private:
QVector<Abstractfile*> contenu;

//methode pour séparer le code
void addFilesProf();
void addFilesEleve();

};


#endif // DESKTOP_H
