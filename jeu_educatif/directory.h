#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "abstractfile.h"
#include "file.h"
#include <QVector>


class Directory : public Abstractfile
{

public:
    explicit Directory(QString const & nom,bool ouvrable=true);
    ~Directory();


    Directory* addDir(QString const & nom,bool ouvrable=true);
    File* addFile(QString const & nom,bool ouvrable=false);
    PdfFile* addPdfFile(QString const & nom,Cours cours,bool ouvrable=true);
    PyFile* addPyFile(const QString &nom,Enigme type,Icon i=python,bool ouvrable=true);

    QVector<Abstractfile *> filelist(){return FileList;}

    void setparentDir(Directory* root){_parentDir=root;}
    Directory* parentDir(){return _parentDir;}
    bool EstCopiable(){return copiable;}
    void SetCopaiable(bool b){copiable=b;}

protected:
    QVector<Abstractfile *> FileList;

private:
    Directory * _parentDir;
    bool copiable;

};


#endif // DIRECTORY_H
