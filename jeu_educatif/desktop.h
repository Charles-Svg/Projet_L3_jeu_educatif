#ifndef DESKTOP_H
#define DESKTOP_H


#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QVector>

#include "fileview.h"
#include "directoryview.h"
#include "filewindow.h"
#include "idewindow.h"
#include "fakepdfviewer.h"
#include "JsonHelper.h"

enum Chapitre {chap1,chap2,chap3};

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
    void ajoutePyFileWindow(Enigme);
    void ajoutePdfFileWindow(PdfFile*);
    void verifyCopy();
    void verifyNotesChange();
    void EndChap1(QAbstractButton *){emit endChap1();}
    void EndChap2(QAbstractButton *){emit endChap2();}
    void EndGame();

private:
QVector<Abstractfile*> contenu;

//methodes pour séparer le code
void addFilesProf(); //ajout des fichiers chap1
void addFilesEleve(); //ajout des fichiers chap2
void addFilesProf2(); //ajout des fichiers chap3

signals:
void endChap1();
void endChap2();
void endGame();

};


#endif // DESKTOP_H
