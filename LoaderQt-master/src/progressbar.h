#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QObject>
#include <QWidget>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QLabel>
#include <QString>
#include "observer.h"
#include "file.h"
#include "fileloader.h"
#include "splashwindow.h"


class ProgressBar : public Observer  {


public:
    ProgressBar(FileLoader *s);

    ~ProgressBar();


//questa funzione ritorna il valore totale  dei file selezionati 
    int getTotalSize() ;

    void updateProgressValue();

    void updateProgressTest();



// overrided functions from the Observer class

    void update(File file)override{
        addFile(file);//deve tirare fuori dati per ridisegnare la progressbar
    }

private:
    void addFile(File file);

private:
    FileLoader* subject;
    //QWidget* wrapper;
    float actualCounter;
    //QProgressBar* progressBar;
    //QVBoxLayout* layout;
    //QTextBrowser* textBrowser;
    //QLabel* textLabel;
    list <File> progressFiles;

};

#endif // PROGRESSBAR_H
