#ifndef FILEVIEW_H
#define FILEVIEW_H

#include "file.h"
#include "abstractfileview.h"

class FileView : public AbstractfileView
{
      Q_OBJECT
public:
    FileView(File*,QWidget *parent = nullptr);

private:
    bool ecriture;

protected:
void OpenEvent() override;

};

#endif // FILEVIEW_H
