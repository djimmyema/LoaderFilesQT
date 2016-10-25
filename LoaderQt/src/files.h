#ifndef FILES_H
#define FILES_H
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

class Files {

public:
    Files(string p);

    virtual int getFileSize();


    virtual string getPath();

private:
    virtual void setFileSize(string filePath) ;

private:

    string filePath;
    int size;


};

#endif // FILES_H
