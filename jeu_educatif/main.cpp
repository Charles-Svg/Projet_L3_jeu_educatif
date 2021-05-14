#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include "JsonHelper.h"



int main(int argc, char *argv[])
{
    //Chargement de la sauvegarde (création du fichier s'il n'existe pas)
    QFile save("save.json");

    QString data("{ \"Chapitre 1\": { \"Copie\": false }, \"Chapitre 2\": { \"Cesar\": false, \"Vigenere\": false, \"Substitution\": false, \"Notes\": false } }");
    if(save.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&save);
        out.setCodec("UTF-8");
        out << data;
        save.close();
    }

    QApplication a(argc, argv);

    MainWindow w;

    w.show();
    w.setWindowState(Qt::WindowMaximized);

    return a.exec();
}
