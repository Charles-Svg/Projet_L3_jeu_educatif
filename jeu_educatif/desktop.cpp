#include "desktop.h"
#include "ui_desktop.h"

Desktop::Desktop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Desktop)
{
    ui->setupUi(this);
    setWallpaper(wallpaperType::professeur);
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
