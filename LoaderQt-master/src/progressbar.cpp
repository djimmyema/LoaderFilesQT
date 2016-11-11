#include "progressbar.h"

//ConcreteObserver

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
    //wrapper->setWindowTitle(QString::fromStdString("Progress Bar"));

// Se vogliamo visualizzare la finestra di caricamento prima che i file vengano caricati
//  bisognerà levare il commento all istruzione sotto
    //wrapper->hide();
    //wrapper->show();

}


ProgressBar::~ProgressBar() {
    subject->unsubscribe(this);

}

//Questa funzione rende le dimensioni in byte di tutti i files salvati nella lista
int ProgressBar::getTotalSize(){
    int totalSize = 0;
    for (auto it = progressFiles.begin(); it != progressFiles.end(); it++)
        totalSize += (*it).getFileSize();
    return totalSize;
}

// Questa funzione verrà eseguita quando il bottone upload verrà cliccato ,
// e copierà tutti i file dal FileLoader,
// aggiornando una progress bar e la lista dei files
void ProgressBar::updateProgressValue(){

// Se vogliamo vedere la nuova finestra quando il bottone di upload verrà premuto la prossima istruzione dovrà essere senza commento
//    wrapper->show();


    SplashWindow splashWindow;

    splashWindow.splashShow();


        float fileCounter= subject->getFileCounter();
        float percentProgress= (float)100/subject->getFileCounter();
        actualCounter=percentProgress;

        for (int i=0; i<fileCounter;i++){
            update(subject->getFileInPosition(i));

            splashWindow.updateProgressScreen(actualCounter,this->getTotalSize(),subject->getFileInPosition(i).getPath());

// questa istruzione visualizzerà la cartella da cui verrà caricato il file
//textBrowser->append(QString::fromStdString(subject->getFileInPosition(i).getPath()));

// questo visualizzerà la progress bar
//progressBar->setValue(actualCounter);

//questo visualizzerà la text label le informazioni inerenti ai byte  di memoria caricati del file
        //textLabel->setText("Total loaded files : "+QString::number(this->getTotalSize())+" bytes");

        actualCounter+=percentProgress;

    }

// if we want that this window to be closed after all files are loaded , uncoment below.
//    wrapper->close();

}

//Questa funzione e' la stessa di updateProgressValue ,
// verrà utilizzata solo per i test con google framework
//void ProgressBar::updateProgressTest(){

//        float fileCounter= subject->getFileCounter();
//        float percentProgress= (float)100/subject->getFileCounter();
//        for (int i=0; i<fileCounter;i++){
//            update(subject->getFileInPosition(i));//Questo aggiorna la lista observer
//            std::cout<<"Cartelle caricate : "<<subject->getFileInPosition(i).getPath();
//            std::cout<<" - dimensione : "<<subject->getFileInPosition(i).getFileSize()<<std::endl;
//            actualCounter+=percentProgress;
//            std::cout<<"\tCaricati : "<<i+1<<"/"<<subject->getFileCounter();
//            std::cout<<" files , Caricamento in memoria : "<<this->getTotalSize()<<"/"<<subject->getTotalFileSize()<<" bytes" <<std::endl;

//        }

//    }

// questa funzione è usata per aggiornare la lista con oggetti di tipo Files
void ProgressBar::addFile(File file) {
    progressFiles.push_back(file);

}

