#ifndef DIRECTORYVIEW_H
#define DIRECTORYVIEW_H

#include <QCoreApplication>

#include "abstractfileview.h"
#include "directory.h"
#include "evenements.h"

enum typeDir {classic,usb};

class DirectoryView : public AbstractfileView
{
      Q_OBJECT
public:
    DirectoryView(Directory*modeldir,QWidget* desktop ,typeDir=classic,QWidget *parent = nullptr);
    ~DirectoryView()=default;


private:
    Directory* _model;
    QWidget* _desktop;
    void emitCopied();

protected:
void OpenEvent() override;

public slots:
void OpenMenu(QPoint const &point);

signals:
void copied();

};

#endif // DIRECTORYVIEW_H
