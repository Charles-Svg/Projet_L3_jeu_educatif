#ifndef DIRECTORYVIEW_H
#define DIRECTORYVIEW_H

#include <QCoreApplication>

#include "abstractfileview.h"
#include "directory.h"
#include "evenements.h"

class DirectoryView : public AbstractfileView
{
      Q_OBJECT
public:
    DirectoryView(Directory*modeldir, QWidget *parent = nullptr);
    ~DirectoryView();

    //bool event(QEvent* event) override;



    Directory* _model;
private:


protected:
void OpenEvent() override;

};

#endif // DIRECTORYVIEW_H
