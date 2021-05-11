#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QtDebug>

int main(int argc, char *argv[])
{
    //Chargement de la sauvegarde (création du fichier s'il n'existe pas)
    QFile save("save.json");
    if(QFileInfo::exists("save.json")){
        //Chargement du bon chapitre
    } else {
        QString data("{ \"Chapitre 1\": { \"Copie\": 0, \"Fin\": 0 }, \"Chapitre 2\": { \"Cesar\": 0, \"Vigenere\": 0, \"Substitution\": 0, \"Fin\": 0 } }");
        if(save.open(QIODevice::WriteOnly | QIODevice::Text)) {
             QTextStream out(&save);
             out.setCodec("UTF-8");
             out << data;
        }

        save.close();
    }

    QApplication a(argc, argv);

    MainWindow w;

    w.show();
    w.setWindowState(Qt::WindowMaximized);

    return a.exec();
}
