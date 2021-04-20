#ifndef DIRCONTROLLER_H
#define DIRCONTROLLER_H

#include "directory.h"
#include "filewindow.h"


//classe qui s'occupera d'instancier une Vue (filewindow) pour le directory)
class DirController
{
public:
    DirController(Directory *model);

private:
    Directory * _model;
    FileWindow * _vue;

};

#endif // DIRCONTROLLER_H
