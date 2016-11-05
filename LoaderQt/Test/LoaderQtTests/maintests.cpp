#include<gtest/gtest.h>
#include "../../src/subject.h"
#include "../../src/observer.h"
#include "../../src/files.h"
#include "../../src/fileloader.h"
#include "../../src/progressbar.h"
#include <iostream>


using namespace std;

//---------------------------------testing the files class----------------------

TEST(testFilesClass, testGetPath){

    File* actual= new File("/home/salomon/Bureau/googletestfiles/DownloadItems.cpp");

    ASSERT_EQ("/home/salomon/Bureau/googletestfiles/DownloadItems.cpp",actual->getPath());

}

TEST(testFilesClass,testGetSize){

    File* actual= new File("/home/salomon/Bureau/googletestfiles/DownloadItems.cpp");

    ASSERT_EQ(990,actual->getFileSize());

}

//------------------------------------testing the fileloader class ---------------------

TEST(testFileLoaderClass, testFileCounter){

    FileLoader* fileLoader= new FileLoader();
    //ProgressBar* progress=new ProgressBar(fileLoader);


    File actual("/home/salomon/Bureau/googletestfiles/DownloadItems.cpp");
    File actual1("/home/salomon/Bureau/googletestfiles/DownloadItems.cpp");
    File actual2("/home/salomon/Bureau/googletestfiles/DownloadItems.cpp");

    fileLoader->putFiles(actual);
    fileLoader->putFiles(actual1);
    fileLoader->putFiles(actual2);

    ASSERT_EQ(3,fileLoader->getFileCounter());

}

TEST(testFileLoaderClass,testGetTotalFileSize){

    FileLoader* fileLoader= new FileLoader();
    //ProgressBar* progress=new ProgressBar(fileLoader);


    File* actual= new File("/home/salomon/Bureau/googletestfiles/DownloadItems.cpp");
    File* actual1= new File("/home/salomon/Bureau/googletestfiles/DownloadItems.cpp");
    File* actual2= new File("/home/salomon/Bureau/googletestfiles/DownloadItems.cpp");

    fileLoader->putFiles(*actual);
    fileLoader->putFiles(*actual1);
    fileLoader->putFiles(*actual2);

    ASSERT_EQ(2970,fileLoader->getTotalFileSize());

}

//--------------------------------testing the progressbar class ------------------------

TEST(testProgressBarClass, testProgressiveLoad){

    FileLoader* fileLoader= new FileLoader();



    File* actual= new File("/home/salomon/Bureau/googletestfiles/DownloadItems.cpp");
    File* actual1= new File("/home/salomon/Bureau/googletestfiles/eventibottoni.cpp");
    File* actual2= new File("/home/salomon/Bureau/googletestfiles/GuiNotifier.cpp");


    fileLoader->putFiles(*actual);
    fileLoader->putFiles(*actual1);
    fileLoader->putFiles(*actual2);


    ProgressBar* myProgress=new ProgressBar(fileLoader);

    cout<<"\t\nTesting the upload progress of files :\n"<<endl;

    myProgress->updateProgressTest();
    ASSERT_EQ(1559,myProgress->getTotalSize());
}


int main(int argc,char* argv[]){

    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();

}
