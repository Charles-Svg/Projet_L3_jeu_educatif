#include "filewindow.h"

FileWindow::FileWindow(Directory * Dir)
    :QWidget(nullptr),rootDir(Dir),layout(new QHBoxLayout())
{

    setWindowTitle("Explorateur de Fichiers");
    setWindowIcon(QIcon(":/folder"));
    setMinimumSize(800,600);

    //organise les sous-fichiers de Dir dans un layout (QGridLayout)
    setLayout(layout);
    layout->setAlignment(Qt::AlignTop);
    layout->addStretch(1);

    for(auto i=0;i<rootDir->filelist().size();++i)
    {

        auto fl= rootDir->filelist();
        auto a =fl.at(i);
        a->show();
        layout->addWidget(a);
        layout->addStretch(1);
        qDebug()<<Dir->filelist().at(i)->nom();

    }


}


FileWindow::~FileWindow()
{
    for (auto i = 0;i<rootDir->filelist().size();i++)
    {
        layout->removeWidget(rootDir->filelist().at(i));
        qDebug()<<"remove : "<<rootDir->filelist().at(i)->nom();
        rootDir->filelist().at(i)->setParent(0);

    }
}

void FileWindow::moveEvent(QMoveEvent *)
{

}

