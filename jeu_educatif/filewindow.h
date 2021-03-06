#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include <QWidget>
#include <QIcon>
#include <QGridLayout>
#include <QHBoxLayout>
#include "directory.h"
#include "directoryview.h"
#include "fileview.h"

class FileWindow : public QWidget
{
    Q_OBJECT
public:
    explicit FileWindow(Directory *,QWidget * desktop);
    ~FileWindow();
    bool event(QEvent*) override;


public slots:
    void goBack(bool); //pour le retour en arrière de l'explorateur
    QWidget* desktop(){return _desktop;}

private:
    Directory * rootDir;
    QHBoxLayout * layout;
    QWidget * _desktop;
    QVector<AbstractfileView*> contenu;
    void PostCopy();
    void PostReplace();

signals:
    void goPrevious(Directory* parentDir);


};


#endif // FILEWINDOW_H
