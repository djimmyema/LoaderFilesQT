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
#include "files.h"
#include "fileloader.h"


class ProgressBar : public Observer  {


public:
    ProgressBar(FileLoader *s);

    ~ProgressBar();

    void display() ;

    int getTotalSize() ;

    void updateProgressValue();

    void updateProgressTest();



// overrided functions from the Observer class

    void update(Files file)override{
        addFiles(file);
    }

private:
    void addFiles(Files file);

private:
    FileLoader* subject;
    QWidget* wrapper;
    float actualCounter;
    QProgressBar* progressBar;
    QVBoxLayout* layout;
    QTextBrowser* textBrowser;
    QLabel* textLabel;
    list <Files> progressFiles;

};

#endif // PROGRESSBAR_H
