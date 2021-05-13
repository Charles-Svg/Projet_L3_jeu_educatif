#include "fondu.h"
#include <QDebug>

QString Fondu::str1="\n\n\n\t\t\t\tLorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet\n"
            "\n\t\t\t\tadipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod\n "
            "\n\t\t\t\tnon, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper\n"
            "\n\t\t\t\tDuis arcu massa, scelerisque vitae, consequat in, pretium a, enim. Pellentesque congue. Ut in risus volutpat libero pharetra\n "
            "\n\t\t\t\ttempor. Cras vestibulum bibendum augue. Praesent egestas leo in pede. Praesent blandit odio eu enim. Pellentesque sed dui \n"
            "\n\t\t\t\tut augue blandit sodales. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh.\n"
            "\n\t\t\t\tMauris ac mauris sed pede pellentesque fermentum. Maecenas adipiscing ante non diam sodales hendrerit.";

Fondu::Fondu(typeFondu f)
    :QPlainTextEdit()
{
    switch (f) {

        case fondu1:
            setPlainText(str1);
        break;

        case fondu2:
        break;

        case fondu3:
        break;

        case fin:
        break;

    }

    setReadOnly(true);
    QFont font;
    font.setPointSize(16);

    setFont(font);
    setStyleSheet("background-color:black ;color:white;");
    setBackgroundRole(QPalette::Shadow);
}

void Fondu::keyPressEvent(QKeyEvent* ev)
{
    if(ev->key()==Qt::Key_Space)
    {
        qDebug()<<"end of the program";
        emit end();
    }
}
