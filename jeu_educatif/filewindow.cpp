#include "filewindow.h"

FileWindow::FileWindow(Directory * Dir)
    :QWidget(nullptr),rootDir(Dir)
{

    setWindowTitle("Explorateur de Fichiers");
    setWindowIcon(QIcon(":/folder"));
    setMinimumSize(800,600);

    //organise les sous-fichiers de Dir dans un layout (QGridLayout)
    QHBoxLayout * layout= new QHBoxLayout();
    setLayout(layout);
    layout->setAlignment(Qt::AlignTop);
    layout->addStretch(1);

    for(auto i=0;i<Dir->filelist().size();++i)
    {

        auto fl= Dir->filelist();
        auto a =fl.at(i);
        a->show();
        layout->addWidget(Dir->filelist().at(i));
        layout->addStretch(1);
        qDebug()<<Dir->filelist().at(i)->nom();

    }


}

FileWindow::~FileWindow()
{

}

void FileWindow::moveEvent(QMoveEvent *)
{

}

