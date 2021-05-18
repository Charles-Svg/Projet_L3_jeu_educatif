#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "desktop.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void loadChap1();
    void loadFondu2();
    void loadChap2();
    void loadFondu3();
    void loadChap3();
    void loadEndScreen();
    void thanks();
};

#endif // MAINWINDOW_H
