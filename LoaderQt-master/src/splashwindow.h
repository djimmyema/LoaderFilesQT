#ifndef SPLASHWINDOW_H
#define SPLASHWINDOW_H
#include <QObject>
#include <QWidget>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QLabel>
#include <QString>
#include <iostream>

using namespace std;

class SplashWindow
{
public:
  SplashWindow():wrapper(new QWidget()),actualCounter(0),
    progressBar(new QProgressBar()),layout(new QVBoxLayout()), textBrowser(new QTextBrowser),
    textLabel(new QLabel()) {

    progressBar->setMaximum(100);
    progressBar->setMinimum(0);
    layout->addWidget(textBrowser);
    layout->addWidget(progressBar);
    layout->addWidget(textLabel);
    wrapper->setLayout(layout);
    wrapper->setFixedWidth(450);
    wrapper->setFixedHeight(350);
    wrapper->setWindowTitle(QString::fromStdString("Progressive File Loader"));

// if we want to show the load window before all the files are loaded
//  we should uncoment the function call below
//    wrapper->hide();
    //wrapper->show();
  }

  void updateProgressScreen(int fileCount,float totalFileSize, string filePath){
    //float percentProgress= (float)100/fileCount;
    //actualCounter=percentProgress;

    textBrowser->append(QString::fromStdString(filePath));
    progressBar->setValue(fileCount);
    textLabel->setText("Total loaded files : "+QString::number(totalFileSize)+" bytes");
    //actualCounter+=percentProgress;

  }

  void splashShow(){
    wrapper->show();
  }

private:
  QWidget* wrapper;
  float actualCounter;
  QProgressBar* progressBar;
  QVBoxLayout* layout;
  QTextBrowser* textBrowser;
  QLabel* textLabel;
};

#endif // SPLASHWINDOW_H
