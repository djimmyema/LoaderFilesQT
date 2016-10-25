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

void MainWindow::on_browseButton_clicked()
{

    std::cout<<"\nBrowse Files Loading ..."<<std::endl;
    if(!checkedBrowse)
        browseButtonClick();
    else
        QMessageBox::information(this,tr("Information"),"You have already browsed , please restart the program !",QMessageBox::Ok);

}

void MainWindow::browseButtonClick(){
    QStringList filePath=QFileDialog::getOpenFileNames(this,tr("Chose a File"),"$HOME/Desktop","Source Files(*.cpp)");
    std::string myFilePath;

    for(QStringList::iterator it=filePath.begin();it!=filePath.end();it++){
        myFilePath=(*it).toUtf8().constData(); //this converts the qstring into a string
        Files files(myFilePath);

// saves all the files on a list on the fileloader class
        myFileLoader->putFiles(files);

// displays the file paths
        ui->textBrowser->append(*it);

        // for debugging only
        std::cout<<"added paths : "<<myFilePath<<std::endl;

    }

// displays a label with the total file size that will be loaded
    ui->totalFileSize->setText("Total files size : "+QString::number(myFileLoader->getTotalFileSize())+" bytes");

// button browse is clicked once
    checkedBrowse=true;

}


void MainWindow::on_uploadButton_clicked()
{
    std::cout<<"\nProgress Bar Loading ..."<<std::endl;// for debugging only
    if(myFileLoader->getFileCounter()){
        if(!checkedUpload){
            uploadButtonClick();
        }else
            QMessageBox::information(this,tr("Information"),"You have already loaded those files !",QMessageBox::Ok);
    }else
        QMessageBox::information(this,QString::fromStdString("Information"),QString::fromStdString("List is empty !"), QMessageBox::Ok);
}

void MainWindow::uploadButtonClick(){

// this is a member function on the progress bar class that loads a new window with progressive load of files.
    myprogress->updateProgressValue();

// the upload button is clickable just once , else diplays a message box .
    checkedUpload=true;

}


