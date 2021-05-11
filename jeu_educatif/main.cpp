#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QtDebug>
#include "JsonHelper.h"



int main(int argc, char *argv[])
{
    //Chargement de la sauvegarde (création du fichier s'il n'existe pas)
    QFile save("save.json");

    QString data("{ \"Chapitre 1\": { \"Copie\": true }, \"Chapitre 2\": { \"Cesar\": true, \"Vigenere\": false, \"Substitution\": true } }");
    if(save.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&save);
        out.setCodec("UTF-8");
        out << data;
        save.close();
    }

    QApplication a(argc, argv);

    MainWindow w;

     //w.showFullScreen(); //solution temporaire
    w.show();
    w.setWindowState(Qt::WindowMaximized);

    return a.exec();
}
