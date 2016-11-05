#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myFileLoader=new FileLoader();
    myprogress=new ProgressBar(myFileLoader);
    checkedUpload=false;
    checkedBrowse=false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete myFileLoader;
    delete myprogress;
}



void MainWindow::browseButtonClick(){                    //Procedura di selezione del File
    QStringList filePath=QFileDialog::getOpenFileNames(this,tr("Choose a File"),"$HOME/Desktop","Source Files(*.cpp)");      //inserisco all' interno della stringa
    std::string myFilePath;                                                                                                  //l'indirizzo del file che apro con una QFileDialog

    for(QStringList::iterator it=filePath.begin();it!=filePath.end();it++){
        myFilePath=(*it).toUtf8().constData(); //Converte una QString in una String

// Salva tutti i files in una lista dentro la classe fileloader
        myFileLoader->putFiles(myFilePath);

// Visualizza le cartelle dei file Aperti
        ui->textBrowser->append(*it);

        // Solo per il Debug//
        std::cout<<"added paths : "<<myFilePath<<std::endl;

    }

// Visualizza una label con le dimensioni dei file scelti che verrannno caricati
    ui->totalFileSize->setText("Total files size : "+QString::number(myFileLoader->getTotalFileSize())+" bytes");

// Il bottone browse è stato cliccato una volta
    checkedBrowse=true;


}


void MainWindow::uploadButtonClick(){

// Questa è una funzione membro della classe progress bar che carica una nuova finestra con un caricamento progressivo dei files.
    myprogress->updateProgressValue();

// il bottone upload e' cliccabile solo una volta , altrimenti fa visualizzare un message box .
    checkedUpload=true;

}





void MainWindow::on_menuBrowse_triggered()
{
    std::cout<<"\nBrowse Files Loading ..."<<std::endl;
    if(!checkedBrowse)                                  //se non è stato ancora cliccato
        browseButtonClick();                            //avvia la procedura per selezionare il file
    else                                                //nel caso sia gia' stato aperto un file
        QMessageBox::information(this,tr("Information"),"You have already browsed , please restart the program !",QMessageBox::Ok);


}

void MainWindow::on_menuUpload_triggered()
{
    std::cout<<"\nProgress Bar Loading ..."<<std::endl;// Solo per il Debug//
    if(myFileLoader->getFileCounter()){
        if(!checkedUpload){
            uploadButtonClick();
        }else
            QMessageBox::information(this,tr("Information"),"You have already loaded those files !",QMessageBox::Ok);
    }else
        QMessageBox::information(this,QString::fromStdString("Information"),QString::fromStdString("List is empty !"), QMessageBox::Ok);
}

void MainWindow::on_menuQuit_triggered()
{
    this->close();
}

