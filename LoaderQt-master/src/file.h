#ifndef FILES_H
#define FILES_H
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

class File {

public:
    File(string p);
    // questo ritorna il file size  di un singolo file
    virtual int getFileSize();


    virtual string getPath();

private:
    virtual void setFileSize(string filePath) ;

private:

    string filePath;
    int size;


};

#endif // FILES_H
