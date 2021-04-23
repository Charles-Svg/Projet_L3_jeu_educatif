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

    void setparentDir(Directory* root){parentDir=root;}
    Directory* getparentDir(){return parentDir;}

    bool event(QEvent* event) override;

protected slots:
    void OpenEvent() override;


signals:

   void FileListUpdated();

protected:
    QVector<Abstractfile *> FileList;

private:
    Directory * parentDir;


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

class ChangeFileWindowEvent : public QEvent
{
public :
    ChangeFileWindowEvent(Directory *);
    static QEvent::Type type();
    Directory* sender();

private:
    static QEvent::Type MyType;
    Directory * _sender;

};
#endif // DIRECTORY_H
