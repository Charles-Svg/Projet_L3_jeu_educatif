#ifndef DIRECTORYVIEW_H
#define DIRECTORYVIEW_H

#include <QCoreApplication>

#include "abstractfileview.h"
#include "directory.h"

class DirectoryView : public AbstractfileView
{
      Q_OBJECT
public:
    DirectoryView(Directory*modeldir, QWidget *parent = nullptr);
    ~DirectoryView();

    bool event(QEvent* event) override;



private:
    Directory* _model;


protected:
void OpenEvent() override;

};

#endif // DIRECTORYVIEW_H
