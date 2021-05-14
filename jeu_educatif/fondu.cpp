#include "fondu.h"
#include "JsonHelper.h"
#include <QDebug>
#include <QBoxLayout>


QString str1="Vous êtes en cours avec M Legeay, professeur que vous détestez : il vous a mis une sale note à votre dernier devoir !"
             "\nVous profitez qu'il s'absente commissionner afin d'essayer de récupérer le fichier contenant l'ensemble des notes de l'épreuve sur son pc.";
QString str2="Le prof est revenu. Heureusement pour vous, c'était sa grosse commission !"
             "\nDe retour chez vous, pas de temps à perdre : vous DEVEZ changer votre note à cette épreuve.";
QString str3="Bien joué, vous avez réussi."
            "\nTout ce qu'il vous reste à faire maintenant c'est de retourner sur le pc de M Legeay et de remplacer le fichier de notes par le votre.";
QString goodEnding="Un grand bravo ! Grâce à cette petite modification, vous avez réussi à valider votre année en étant major de promotion.\nVous avez continué dans cette lancée jusqu’à obtenir votre master en informatique avec félicitations du jury, vous avez lancé votre boîte et inventé un tout nouveau réseau social révolutionnaire."
                    "\nMaintenant, vous êtes riche, avez une belle famille aimante et êtes à la tête de la plus grosse entreprise au monde, avec des salariés qui vous idolâtrent.";
QString badEnding="Bien joué, vous avez réussi à modifier votre note ! Malheureusement, le prof s’en est très vite rendu compte lorsqu’il a dû vérifier l’ensemble des notes avant de les publier pour faire votre moyenne générale…"
                  "\nVous vous retrouvez exclu de votre formation, votre petite amie du moment vous largue, vos amis changent tous de ville, votre famille vous renie,"
                  "\nvous finissez seul, dans la rue, à n’avoir d’autre choix que de dormir dans ce coin de rue un petit peu plus chaud que la moyenne en attendant de pouvoir réussir à sortir de cette situation."
                  "\nC’est dommage d’en arriver là juste parce qu’on a voulu essayer de trouver le code sans avoir résolu l’ensemble des énigmes.";

Fondu::Fondu(typeFondu f)
    :QWidget()
{
    _label = new LetterByLetterLabel();



    QFont font;
    font.setPointSize(12);

    _label->setFont(font);
    setStyleSheet("background-color:black ;color:white;");
    _label->setAlignment(Qt::AlignCenter);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->setMargin(0);
    layout->addWidget(_label, Qt::AlignCenter);
    this->setLayout(layout);

    setFocusPolicy(Qt::StrongFocus);

    switch (f) {

        case fondu1:
            this->_label->setText(str1);
        break;

        case fondu2:
            this->_label->setText(str2);
        break;

        case fondu3:
            this->_label->setText(str3);
        break;

        case fin:
            if(enigmasFullyCompleted())
                this->_label->setText(goodEnding);
            else
                this->_label->setText(badEnding);

        break;

    }

}

void Fondu::keyPressEvent(QKeyEvent* ev)
{
    if(ev->key()==Qt::Key_Space){
        if(this->_label->isDisplayed())
        {
            emit end();
        } else
        {
            this->_label->skip();
        }
    }
}


