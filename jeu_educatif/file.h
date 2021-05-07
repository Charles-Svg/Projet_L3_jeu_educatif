#ifndef FILE_H
#define FILE_H

#include "abstractfile.h"

enum FileType {Txt,PDF,PY};

class File : public Abstractfile
{

public:
    explicit File(QString const & nom,bool ouvrable=1);
    ~File()=default;

};


class PyFile : public Abstractfile
{
public:
    PyFile(QString const & nom,bool ouvrable=1);
};


class PdfFile : public Abstractfile
{
public:
    PdfFile(QString const & nom,bool ouvrable=1);
};





#endif // FILE_H
