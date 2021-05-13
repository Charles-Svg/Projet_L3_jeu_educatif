#ifndef FILE_H
#define FILE_H

#include "abstractfile.h"
#include "idewindow.h"


class File : public Abstractfile
{

public:
    explicit File(QString const & nom,bool ouvrable=false);
    ~File()=default;

};



class PyFile : public Abstractfile
{
public:
    PyFile(QString const & nom,Enigme enig,bool ouvrable=true);
    Enigme enigmeType(){return _enigmeType;}

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
