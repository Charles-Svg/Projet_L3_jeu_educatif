#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "abstractfile.h"
#include "filewindow.h"
#include "QVector"

class Directory : public Abstractfile
{
     Q_OBJECT
public:
    explicit Directory(QString const & nom,QWidget *parent = nullptr);

protected slots:
    void OpenEvent() override;

private:
    FileWindow * _explorer;

signals:
   void DirOpenned(FileWindow *);

protected:
    QVector<Abstractfile *> liste;

};

#endif // DIRECTORY_H
