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
};

#endif // MAINWINDOW_H
