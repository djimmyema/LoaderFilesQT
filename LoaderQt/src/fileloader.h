#ifndef FILELOADER_H
#define FILELOADER_H



#include <list>
#include <vector>
#include "subject.h"
#include "observer.h"
#include "files.h"

class FileLoader : public Subject {

public:
    FileLoader();

    ~FileLoader();

    void putFiles(Files files);

    int getFileCounter();

    void display();

    Files getLastFile();

    int getTotalFileSize();


    Files getFileInPosition(int position);


    //---------- Functions ovverided from the subject class -------------


    virtual void subscribe(Observer* obs) override;

    virtual void unsubscribe(Observer* obs) override;

    virtual void notify() override;

private:

    void totalFilesSize();

private:
    int totalSize;
    int fileCounter;
    list<Observer*> observer;
    vector<Files> fileList;


};


#endif // FILELOADER_H
