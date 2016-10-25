#include "progressbar.h"



ProgressBar::ProgressBar(FileLoader *s) : subject(s),actualCounter(0){

    subject->subscribe(this);

    //progressBar->setMaximum(100);
    //progressBar->setMinimum(0);

    //layout->addWidget(textBrowser);
    //layout->addWidget(progressBar);
    //layout->addWidget(textLabel);

    //wrapper->setLayout(layout);
    //wrapper->setFixedWidth(450);
    //wrapper->setFixedHeight(350);
    //wrapper->setWindowTitle(QString::fromStdString("Progressive File Loader"));

// if we want to show the load window before all the files are loaded
//  we should uncoment the function call below
    //wrapper->hide();
    //wrapper->show();

}


ProgressBar::~ProgressBar() {
    subject->unsubscribe(this);

}

// this is just for testin the list and printing the objects inside it , for debugging
void ProgressBar::display(){
    for (auto itr = progressFiles.begin(); itr != progressFiles.end(); itr++)
        cout << "path : " << (*itr).getPath() << " - size : " << (*itr).getFileSize() << endl;
}

// this function gets the size in bytes of all the files saved on the list in a certain time
int ProgressBar::getTotalSize(){
    int totalSize = 0;
    for (auto it = progressFiles.begin(); it != progressFiles.end(); it++)
        totalSize += (*it).getFileSize();
    return totalSize;
}

// this function will be called when the upload button is clicked ,
// and will copy all the files from the FileLoader,
// updating a progress bar and the file list
void ProgressBar::updateProgressValue(){

    SplashWindow splashWindow;
    splashWindow.splashShow();


    float fileCounter= subject->getFileCounter();
    float percentProgress= (float)100/subject->getFileCounter();
    actualCounter=percentProgress;

    for (int i=0; i<fileCounter;i++){
        update(subject->getFileInPosition(i));//this updates the observer list
        //std::cout<<"loaded path : "<<subject->getFileInPosition(i).getPath();
        //std::cout<<" - size : "<<subject->getFileInPosition(i).getFileSize()<<std::endl;
        splashWindow.updateProgressScreen(actualCounter,this->getTotalSize(),subject->getFileInPosition(i).getPath());



// this displays the paths that will be loaded
        //textBrowser->append(QString::fromStdString(subject->getFileInPosition(i).getPath()));

// this diplays the progress bar
        //progressBar->setValue(actualCounter);

//this displays the text label with info about memory size loaded
        //textLabel->setText("Total loaded files : "+QString::number(this->getTotalSize())+" bytes");

        actualCounter+=percentProgress;

    }

// if we want that this window to be closed after all files are loaded , uncoment below.
//    wrapper->close();

}

// this function is the same as updateProgressValue ,
// it will be used only for testing with google framework
//void ProgressBar::updateProgressTest(){
//
//        float fileCounter= subject->getFileCounter();
//        float percentProgress= (float)100/subject->getFileCounter();
//        for (int i=0; i<fileCounter;i++){
//            update(subject->getFileInPosition(i));//this updates the observer list
//            std::cout<<"loaded path : "<<subject->getFileInPosition(i).getPath();
//            std::cout<<" - size : "<<subject->getFileInPosition(i).getFileSize()<<std::endl;
//            actualCounter+=percentProgress;
//            std::cout<<"\tLoad : "<<i+1<<"/"<<subject->getFileCounter();
//            std::cout<<" files , memory load : "<<this->getTotalSize()<<"/"<<subject->getTotalFileSize()<<" bytes" <<std::endl;
//
//        }
//
//    }

// this function is used to update the list with objects of type: Files
void ProgressBar::addFiles(Files file) {
    progressFiles.push_back(file);

}

