#ifndef FILELOADER_H
#define FILELOADER_H



#include <list>
#include <vector>
#include "subject.h"
#include "observer.h"
#include "file.h"

class FileLoader : public Subject {

public:
    FileLoader();

    ~FileLoader();

    void putFiles(std::string myFilePath);


  //questa funzione conta il numero dei file caricati
    int getFileCounter();

//display() viene usato solo per fare il debug del programma  si puo anche togliere
    //void display();

    File getLastFile();

    //questa funzione calcola la memoria che occupano in totale tutti file selezionati
    int getTotalFileSize();


    File getFileInPosition(int position);


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
    vector<File> fileList;


};


#endif // FILELOADER_H
