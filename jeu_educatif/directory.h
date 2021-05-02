#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "abstractfile.h"
#include "file.h"
#include <QVector>


class Directory : public Abstractfile
{

public:
    explicit Directory(QString const & nom,bool ouvrable=1);
    ~Directory();


    Directory* addDir(QString const & nom,bool ouvrable=1);
    void addFile(QString const & nom,FileType type,bool ouvrable=1);
    QVector<Abstractfile *> filelist(){return FileList;}

    void setparentDir(Directory* root){_parentDir=root;}
    Directory* parentDir(){return _parentDir;}


protected:
    QVector<Abstractfile *> FileList;

private:
    Directory * _parentDir;

};


#endif // DIRECTORY_H
