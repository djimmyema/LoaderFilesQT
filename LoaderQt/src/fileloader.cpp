#include "fileloader.h"

FileLoader::FileLoader() : totalSize(0), fileCounter(0) { }

FileLoader::~FileLoader(){}

void FileLoader::putFiles(Files files){
    fileList.push_back(files);
    fileCounter++;
    //notify();//disabled , it will be used the upload button
}

int FileLoader::getFileCounter(){
    return fileCounter;
}

void FileLoader::display(){
    for (auto itr = fileList.begin(); itr != fileList.end(); itr++)
        cout << "path : " << (*itr).getPath() << " - size : " << (*itr).getFileSize() << endl;
}

Files FileLoader::getLastFile(){
    return fileList.back();
}

int FileLoader::getTotalFileSize() {
//calls the calculator of file sizes
    totalFilesSize();
    return totalSize;
}

Files FileLoader::getFileInPosition(int position){
    return fileList[position];
}

void FileLoader::subscribe(Observer *obs){
    observer.push_back(obs);
    }

void FileLoader::unsubscribe(Observer *obs) {
    observer.remove(obs);
}

void FileLoader::notify() { // this causes an error
    for(auto it=observer.begin();it!=observer.end();it++){
                (*it)->update(getLastFile());
            }
}

void FileLoader::totalFilesSize(){
    for (auto it = fileList.begin(); it != fileList.end(); it++)
        totalSize += (*it).getFileSize();
}
