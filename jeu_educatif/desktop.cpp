#include "desktop.h"
#include "ui_desktop.h"

Desktop::Desktop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Desktop)
{
    ui->setupUi(this);
    //setWallpaper(wallpaperType::professeur);


    setStyleSheet("border : 1px solid black;");
    Abstractfile * fichier = new File("File 1",this);
    ui->FileLayout->addWidget(fichier,0,0);

    Abstractfile * fichier2 = new File("File 2",this);
    ui->FileLayout->addWidget(fichier2,0,1);

    ui->FileLayout->setRowMinimumHeight(1,this->height());



}

Desktop::~Desktop()
{
    delete ui;
}

void Desktop::setWallpaper(wallpaperType type)
{
    if(type==wallpaperType::professeur)
    {
        ui->centralwidget->setStyleSheet("background-image: url(:/wallpaper_prof);");
    }
}
