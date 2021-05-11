#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QFile>
#include <iostream>
#include "JsonHelper.h"



bool enigmasFullyCompleted(){
    QFile inFile("save.json");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();
    inFile.close();
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
        return false;
    }
    QJsonObject rootObj(doc.object());
    QJsonObject chapter1(rootObj.value("Chapitre 1").toObject());
    QJsonObject chapter2(rootObj.value("Chapitre 2").toObject());

    foreach(const QString& key, chapter1.keys()) {
        QJsonValue value = chapter1.value(key);
        if(!value.toBool())
            return false;
    }

    foreach(const QString& key, chapter2.keys()) {
        QJsonValue value = chapter2.value(key);
        if(!value.toBool())
            return false;
    }
    return true;
}
