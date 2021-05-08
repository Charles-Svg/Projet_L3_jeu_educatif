#ifndef FILE_H
#define FILE_H

#include "abstractfile.h"
#include "idewindow.h"

enum FileType {Txt,PDF,PY};

class File : public Abstractfile
{

public:
    explicit File(QString const & nom,bool ouvrable=false);
    ~File()=default;

};




class PyFile : public Abstractfile
{
public:
    PyFile(QString const & nom,Enigme enig=Enigme::Cesar,bool ouvrable=true);
    Enigme enigmeType(){return _enigmeType;}

private:
    Enigme _enigmeType;

};


class PdfFile : public Abstractfile
{
public:
    PdfFile(QString const & nom,bool ouvrable=true);
};





#endif // FILE_H
