#ifndef FILE_H
#define FILE_H

#include "abstractfile.h"
#include "idewindow.h"


enum Icon{python,xls,pdf,file};

//modele des fichiers "simple" , va servir pour le chap 3 ou comme fichier de déco (non ouvrable)
class File : public Abstractfile
{

public:
    explicit File(QString const & nom,bool ouvrable=false);
    ~File()=default;
    void setRemplacable(bool t){_remplacable=t;}
    bool remplacable(){return _remplacable;}
    void setEcriture(bool t){_ecriture=t;}
    bool ecriture(){return _ecriture;}


private:
    bool _remplacable;
    bool _ecriture;

};

//modele des fichiers python
class PyFile : public Abstractfile
{
public:
    PyFile(QString const & nom,Enigme enig,Icon i=python,bool ouvrable=true);
    Enigme enigmeType(){return _enigmeType;}
    Icon icone;

private:
    Enigme _enigmeType;

};

enum Cours {Cesar, Vigenere, Substitution, frequentielle, Autre}; //type pour initialiser les images du FakePdfViewer

//modele des fichiers Pdf
class PdfFile : public Abstractfile
{
public:
    PdfFile(QString const & nom,Cours course,bool ouvrable=true);
    Cours cours(){return _cours;}

private:
        Cours _cours;
};





#endif // FILE_H
