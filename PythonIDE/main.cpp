#include "idewindow.h"
#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IDEWindow w(Enigme::Vigenere);
    w.show();
    return a.exec();
}
