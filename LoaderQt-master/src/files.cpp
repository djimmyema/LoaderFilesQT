
#include "files.h"

Files::Files(string p) : filePath(p), size(0) {

    setFileSize(filePath);

}

int Files::getFileSize() {
    return size;
}

string Files::getPath() {
    return filePath;
}

void Files::setFileSize(string filePath){
    //questo prende le dimensioni del file che verranno usate sulla progress bar
    ifstream file(filePath, ios::binary | ios::ate);
    size = file.tellg();
}
