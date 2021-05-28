#ifndef IDEWINDOW_H
#define IDEWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QToolButton>
#include <QStatusBar>

#include "codeeditor.h"
#include "pythonhighlighter.h"

//Enumeration permettant de savoir dans quel contexte on ouvre la fenêtre IDE (quelle énigme à charger)
enum class Enigme{Copie, Cesar, Vigenere, Substitution, Notes, Final};


class IDEWindow : public QWidget
{
    Q_OBJECT

public:
    explicit IDEWindow(Enigme e = Enigme::Cesar, QWidget *parent = nullptr);
    ~IDEWindow();

    void writeInFile(QString filename, QString data);
    void executeFile(QString filename);
    void runProgram();
    void stopProgram();

private slots:
    void cursorPosition_changed();
    void codeExecution_finished(int exitCode);
    void displayStandard_output();
    void displayStandard_error();
    void EndGame();

private:
    QStatusBar* _statusbar;
    CodeEditor* _codeEditor;
    PythonHighlighter* _highlighter;
    QTabWidget* _consoleTab;
    QPlainTextEdit* _consoleOutput;
    QProcess _executor;
    QToolButton* _startProgram;
    QToolButton* _stopProgram;
    QString _testFilename;
    Enigme enigme;

signals:
    void copyExec();
    void notesExec();
    void endGame();

};

#endif // IDEWINDOW_H
