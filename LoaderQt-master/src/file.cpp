
#include "file.h"

File::File(string p) : filePath(p), size(0) {

    setFileSize(filePath);

}

int File::getFileSize() {
    return size;
}

string File::getPath() {
    return filePath;
}

void File::setFileSize(string filePath){
    //questo prende le dimensioni del file che verranno usate sulla progress bar
    ifstream file(filePath, ios::binary | ios::ate);
    size = file.tellg();
}
