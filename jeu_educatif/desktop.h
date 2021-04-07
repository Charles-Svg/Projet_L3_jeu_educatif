#ifndef DESKTOP_H
#define DESKTOP_H

#include <QMainWindow>


enum wallpaperType {professeur,joueur};
namespace Ui {
class Desktop;
}

class Desktop : public QMainWindow
{
    Q_OBJECT

public:
    explicit Desktop(QWidget *parent = nullptr);
    ~Desktop();

private:
    Ui::Desktop *ui;

protected:
    void setWallpaper(wallpaperType type);
};

#endif // DESKTOP_H
