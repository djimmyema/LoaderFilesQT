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

    Files* actual= new Files("C:\gtestexample\example1\loadfile.cpp");

    ASSERT_EQ("C:\gtestexample\example1\loadfile.cpp",actual->getPath());

}

TEST(testFilesClass,testGetSize){

    Files* actual= new Files("C:\gtestexample\example1\main.cpp");

    ASSERT_EQ(736,actual->getFileSize());

}

//------------------------------------testing the fileloader class ---------------------

TEST(testFileLoaderClass, testFileCounter){

    FileLoader* fileLoader= new FileLoader();
    //ProgressBar* progress=new ProgressBar(fileLoader);


    Files actual("C:\gtestexample\example1\main.cpp");
    Files actual1("C:\gtestexample\example1\main.cpp");
    Files actual2("C:\gtestexample\example1\main.cpp");

    fileLoader->putFiles(actual);
    fileLoader->putFiles(actual1);
    fileLoader->putFiles(actual2);

    ASSERT_EQ(3,fileLoader->getFileCounter());

}

TEST(testFileLoaderClass,testGetTotalFileSize){

    FileLoader* fileLoader= new FileLoader();
    //ProgressBar* progress=new ProgressBar(fileLoader);


    Files* actual= new Files("C:\gtestexample\example1\main.cpp");
    Files* actual1= new Files("C:\gtestexample\example1\main.cpp");
    Files* actual2= new Files("C:\gtestexample\example1\main.cpp");

    fileLoader->putFiles(*actual);
    fileLoader->putFiles(*actual1);
    fileLoader->putFiles(*actual2);

    ASSERT_EQ(2208,fileLoader->getTotalFileSize());

}

//--------------------------------testing the progressbar class ------------------------

TEST(testProgressBarClass, testProgressiveLoad){

    FileLoader* fileLoader= new FileLoader();



    Files* actual= new Files("C:\gtestexample\example1\loadfile.cpp");
    Files* actual1= new Files("C:\gtestexample\example1\main.cpp");
    Files* actual2= new Files("C:\gtestexample\example1\mainwindow.cpp");


    fileLoader->putFiles(*actual);
    fileLoader->putFiles(*actual1);
    fileLoader->putFiles(*actual2);


    ProgressBar* myProgress=new ProgressBar(fileLoader);

    cout<<"\t\nTesting the upload progress of files :\n"<<endl;

    myProgress->updateProgressTest();
    ASSERT_EQ(2615,myProgress->getTotalSize());
}


int main(int argc,char* argv[]){

    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();

}
