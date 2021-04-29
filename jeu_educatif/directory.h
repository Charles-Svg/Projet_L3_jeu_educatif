#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "abstractfile.h"
#include "file.h"
#include <QVector>


class Directory : public Abstractfile
{

public:
    explicit Directory(QString const & nom);
    ~Directory();


    Directory* addDir(QString const & nom);
    void addfile(QString const & nom);
    QVector<Abstractfile *> filelist(){return FileList;}

    void setparentDir(Directory* root){_parentDir=root;}
    Directory* parentDir(){return _parentDir;}


protected:
    QVector<Abstractfile *> FileList;

private:
    Directory * _parentDir;

};


#endif // DIRECTORY_H
