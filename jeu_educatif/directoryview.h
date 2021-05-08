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
    DirectoryView(Directory*modeldir, QWidget *parent = nullptr,typeDir=classic);
    ~DirectoryView()=default;


    Directory* _model;
private:


protected:
void OpenEvent() override;

};

#endif // DIRECTORYVIEW_H
