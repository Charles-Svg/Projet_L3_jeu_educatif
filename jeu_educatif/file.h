#ifndef FILE_H
#define FILE_H

#include "abstractfile.h"
#include "idewindow.h"


enum Icon{python,xls,pdf,file};

class File : public Abstractfile
{

public:
    explicit File(QString const & nom,bool ouvrable=false);
    ~File()=default;

};



class PyFile : public Abstractfile
{
public:
    PyFile(QString const & nom,Enigme enig,Icon i=python,bool ouvrable=true);
    Enigme enigmeType(){return _enigmeType;}
    Icon icone;

private:
    Enigme _enigmeType;

};

enum Cours {Cesar, Vigenere, Substitution, frequentielle, Autre};

class PdfFile : public Abstractfile
{
public:
    PdfFile(QString const & nom,Cours course,bool ouvrable=true);
    Cours cours(){return _cours;}

private:
        Cours _cours;
};





#endif // FILE_H
