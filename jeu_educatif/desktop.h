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
    void EndGame(){emit endGame(); }

private:
QVector<Abstractfile*> contenu;

//methode pour séparer le code
void addFilesProf();
void addFilesEleve();
void addFilesProf2();

signals:
void endChap1();
void endChap2();
void endGame();

};


#endif // DESKTOP_H
