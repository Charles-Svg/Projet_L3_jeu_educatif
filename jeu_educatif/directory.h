#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "abstractfile.h"
#include "file.h"
#include <QVector>

class Directory : public Abstractfile
{
     Q_OBJECT
public:
    explicit Directory(QString const & nom,QWidget *parent = nullptr);
    void addDir(QString const & nom);
    void addfile(QString const & nom);
    QVector<Abstractfile *> filelist(){return FileList;}

protected slots:
    void OpenEvent() override;

//faire en sorte que le Dir sache dans quoi il est
signals:

   void FileListUpdated();

protected:
    QVector<Abstractfile *> FileList;


};

//evenement personnalisé pour l'ouverture d'un dossier
class OpenDirEvent : public QEvent
{
public:
    OpenDirEvent(Directory *);

    static QEvent::Type type();
    Directory* sender();


private:
    static QEvent::Type MyType;
    Directory * _sender;
};

#endif // DIRECTORY_H
