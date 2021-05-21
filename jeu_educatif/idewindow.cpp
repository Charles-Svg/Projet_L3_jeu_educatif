#include "idewindow.h"
#include "codeeditor.h"

#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QObject>
#include <QTextCodec>
#include <QBoxLayout>
#include <QShortcut>

IDEWindow::IDEWindow(Enigme e, QWidget *parent) :
    QWidget(parent),_statusbar(new QStatusBar(this)),enigme(e)

{

    setWindowTitle("Enigme");
    setWindowIcon(QIcon(":/pieThonLogo"));

    this->_codeEditor = new CodeEditor;

    setMinimumSize(800,600);
    QVBoxLayout* verticalLayout= new QVBoxLayout(this);

    //Ajout de l'éditeur de code sur l'interface
    verticalLayout->addWidget(this->_codeEditor);
    this->_highlighter = new PythonHighlighter(this->_codeEditor->document());



    //Ajout de la barre d'onglets sur l'interface
    this->_consoleTab = new QTabWidget;
    this->_consoleTab->setMaximumHeight(250);
    verticalLayout->addWidget(this->_consoleTab);

    //Ajout de la barre de statut sur l'interface
    verticalLayout->addWidget(_statusbar);

    this->_consoleOutput = new QPlainTextEdit;
    this->_consoleOutput->setReadOnly(true);
    QFont f;
    f.setFamily("Courier");
    f.setPointSize(11);
    this->_consoleOutput->setFont(f);


    //Ajout de l'onglet sortie console sur l'interface
    this->_consoleTab->insertTab(1,this->_consoleOutput,"Sortie Console");



    this->_startProgram = new QToolButton;
    this->_stopProgram = new QToolButton;

    this->_startProgram->setIcon(QIcon(":/playIcon"));
    this->_startProgram->setMinimumSize(QSize(16, 16));
    this->_stopProgram->setIcon(QIcon(":/stopIcon"));
    this->_stopProgram->setMinimumSize(QSize(16, 16));
    this->_stopProgram->setEnabled(false);

    QWidget* tabCornerWidget = new QWidget(this->_consoleTab);
    QHBoxLayout* pHLayout = new QHBoxLayout(tabCornerWidget);
    pHLayout->setMargin(0);
    pHLayout->addWidget(this->_startProgram);
    pHLayout->addWidget(this->_stopProgram);


    //Ajout des boutons d'exécution et d'arrêt de programme sur l'interface
    this->_consoleTab->setCornerWidget(tabCornerWidget);



    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_R), this);
    connect(shortcut, &QShortcut::activated, this, &IDEWindow::runProgram);

    connect(this->_codeEditor,&QPlainTextEdit::cursorPositionChanged, this, &IDEWindow::cursorPosition_changed);
    connect(this->_consoleOutput,&QPlainTextEdit::textChanged, this->_consoleOutput, &QPlainTextEdit::ensureCursorVisible);
    connect(&this->_executor, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &IDEWindow::codeExecution_finished);
    connect(&this->_executor, &QProcess::readyReadStandardOutput, this, &IDEWindow::displayStandard_output);
    connect(&this->_executor, &QProcess::readyReadStandardError, this, &IDEWindow::displayStandard_error);
    connect(this->_startProgram, &QToolButton::clicked, this, &IDEWindow::runProgram);
    connect(this->_stopProgram, &QToolButton::clicked, this, &IDEWindow::stopProgram);

    /*
     * Section "Fin"
     *
     */
    if(e == Enigme::Final){
        QShortcut *finalShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_E,Qt::CTRL+Qt::Key_T,Qt::CTRL+Qt::Key_G), this);

        connect(finalShortcut, &QShortcut::activated, this, &IDEWindow::EndGame);

    }

    /*
     * Chargement de l'énigme correspondante au contexte courant
     * Des fichiers sont crées afin de pouvoir plus tard être exécutés au lancement de l'exécution du script
     */
    switch(e){
    case Enigme::Copie:{
        QFile file(":/python/c_copy.py");
        file.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content;
        while(!file.atEnd())
            content.append(file.readLine());
        this->_codeEditor->setPlainText(content);
        file.close();

        QFile file2(":/python/test_copy.py");
        file2.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content2;
        while(!file2.atEnd())
            content2.append(file2.readLine());
        this->writeInFile("test_copy.py", content2);
        file2.close();
        this->_testFilename = "test_copy.py";

        QFile file3(":/python/files.py");
        file3.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content3;
        while(!file3.atEnd())
            content3.append(file3.readLine());
        this->writeInFile("files.py", content3);
        file3.close();
        break;
    }
    case Enigme::Cesar:{
        QFile file(":/python/c_cesar.py");
        file.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content;
        while(!file.atEnd())
            content.append(file.readLine());
        this->_codeEditor->setPlainText(content);
        file.close();

        QFile file2(":/python/test_cesar.py");
        file2.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content2;
        while(!file2.atEnd())
            content2.append(file2.readLine());
        this->writeInFile("test_cesar.py", content2);
        file2.close();
        this->_testFilename = "test_cesar.py";
        break;
    }
    case Enigme::Vigenere:{
        QFile file(":/python/c_vigenere.py");
        file.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content;
        while(!file.atEnd())
            content.append(file.readLine());
        this->_codeEditor->setPlainText(content);
        file.close();

        QFile file2(":/python/test_vigenere.py");
        file2.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content2;
        while(!file2.atEnd())
            content2.append(file2.readLine());
        this->writeInFile("test_vigenere.py", content2);
        file2.close();
        this->_testFilename = "test_vigenere.py";
        break;
    }
    case Enigme::Substitution:{
        QFile file(":/python/c_substitution.py");
        file.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content;
        while(!file.atEnd())
            content.append(file.readLine());
        this->_codeEditor->setPlainText(content);
        file.close();

        QFile file2(":/python/test_substitution.py");
        file2.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content2;
        while(!file2.atEnd())
            content2.append(file2.readLine());
        this->writeInFile("test_substitution.py", content2);
        file2.close();
        this->_testFilename = "test_substitution.py";
        break;
    }
    case Enigme::Notes:{
        QFile file(":/python/c_change_notes.py");
        file.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content;
        while(!file.atEnd())
            content.append(file.readLine());
        this->_codeEditor->setPlainText(content);
        file.close();

        QFile file2(":/python/test_notes.py");
        file2.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content2;
        while(!file2.atEnd())
            content2.append(file2.readLine());
        this->writeInFile("test_notes.py", content2);
        file2.close();
        this->_testFilename = "test_notes.py";

        QFile file3(":/python/notes.py");
        file3.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content3;
        while(!file3.atEnd())
            content3.append(file3.readLine());
        this->writeInFile("notes.py", content3);
        file3.close();
        break;
    }
    case Enigme::Final:{
        QFile file(":/python/c_fin.py");
        file.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content;
        while(!file.atEnd())
            content.append(file.readLine());
        this->_codeEditor->setPlainText(content);
        file.close();
        break;
    }
    }

    if(!QFileInfo::exists("save.py")){
        QFile file(":/python/save.py");
        file.open(QIODevice::Text | QIODevice::ReadOnly);
        QString content;
        while(!file.atEnd())
            content.append(file.readLine());
        this->writeInFile("save.py", content);
        file.close();
    }


}

IDEWindow::~IDEWindow()
{
}



/*
 * Permet d'écrire sur un fichier
 *
 */
void IDEWindow::writeInFile(QString filename, QString data){
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
         QTextStream out(&file);
         out.setCodec("UTF-8");
         out << data;
    }

    file.close();
}


void IDEWindow::executeFile(QString filename){
    QStringList arguments {filename};
    //exécution du script par l'interpréteur python
    this->_executor.start("python", arguments);
    this->_consoleOutput->clear();
    this->_consoleOutput->insertPlainText("-->");
}






void IDEWindow::runProgram(){
    //Désactivation du bouton pour lancer le script
    this->_startProgram->setEnabled(false);
    //Création d'un fichier temporaire contenant les données que le joueur a entré
    QString filename("temp.py");
    QString data(this->_codeEditor->toPlainText());
    writeInFile(filename, data);
    //Un fichier de test null équivaut au contexte de fin : il n'y a pas de classe de test à exécuter donc on lance directement le fichier du joueur
    if(this->_testFilename.isNull())
        executeFile(filename);
    else
        executeFile(this->_testFilename);
    //Activation du bouton pour stopper le script
    this->_stopProgram->setEnabled(true);


}

void IDEWindow::stopProgram(){
    this->_executor.kill();
    this->_consoleOutput->appendHtml("<font color=\"Red\"><pre>Program has been shutdown</pre></font>");
}


/*
 *Permet de garder la barre de statut à jour
 *
 */
void IDEWindow::cursorPosition_changed(){
    QTextCursor c = this->_codeEditor->textCursor();
    _statusbar->showMessage(QString("Ln %1, Col %2").arg(c.blockNumber() + 1).arg((c.positionInBlock() + 1)));
}


void IDEWindow::codeExecution_finished(int /*exitCode*/){
    //Désactivation du bouton pour stopper le script
    this->_stopProgram->setEnabled(false);
    //Suppression du fichier temporaire
    QFile file("temp.py");
    file.remove();
    //Activation du bouton pour stopper le script
    this->_startProgram->setEnabled(true);

    //Emission d'un signal permettant de marquer la fin du premier chapitre
    if(enigme==Enigme::Copie)
    {
        emit CopyExec();
    }
    else if(enigme==Enigme::Notes)
    {
        emit NotesExec();
    }

}

void IDEWindow::displayStandard_output()
{
    QString output = QString::fromLocal8Bit(this->_executor.readAllStandardOutput());
    this->_consoleOutput->insertPlainText("\n" + output);
}

void IDEWindow::displayStandard_error()
{
    QString err = QString::fromLocal8Bit(this->_executor.readAllStandardError());
    this->_consoleOutput->appendHtml("<font color=\"Red\"><pre>" + err + "</pre></font>");

}

void IDEWindow::EndGame()
{
    emit endGame();
}
