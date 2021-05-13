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

enum Chapitre {chap1,chap2};

class Desktop : public QMdiArea
{
    Q_OBJECT
public:
    explicit Desktop(Chapitre u,QWidget *parent = nullptr);
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


signals:
void endChap1();
void endChap2();

};


#endif // DESKTOP_H
