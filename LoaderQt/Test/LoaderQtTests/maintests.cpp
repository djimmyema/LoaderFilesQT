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

    Files* actual= new Files("/home/astimanuka/Desktop/main.cpp");

    ASSERT_EQ("/home/astimanuka/Desktop/main.cpp",actual->getPath());

}

TEST(testFilesClass,testGetSize){

    Files* actual= new Files("/home/astimanuka/Desktop/main.cpp");

    ASSERT_EQ(12346,actual->getFileSize());

}

//------------------------------------testing the fileloader class ---------------------

TEST(testFileLoaderClass, testFileCounter){

    FileLoader* fileLoader= new FileLoader();
    //ProgressBar* progress=new ProgressBar(fileLoader);


    Files actual("/home/astimanuka/Desktop/main.cpp");
    Files actual1("/home/astimanuka/Desktop/main.cpp");
    Files actual2("/home/astimanuka/Desktop/main.cpp");

    fileLoader->putFiles(actual);
    fileLoader->putFiles(actual1);
    fileLoader->putFiles(actual2);

    ASSERT_EQ(3,fileLoader->getFileCounter());

}

TEST(testFileLoaderClass,testGetTotalFileSize){

    FileLoader* fileLoader= new FileLoader();
    //ProgressBar* progress=new ProgressBar(fileLoader);


    Files* actual= new Files("/home/astimanuka/Desktop/main.cpp");
    Files* actual1= new Files("/home/astimanuka/Desktop/main.cpp");
    Files* actual2= new Files("/home/astimanuka/Desktop/main.cpp");

    fileLoader->putFiles(*actual);
    fileLoader->putFiles(*actual1);
    fileLoader->putFiles(*actual2);

    ASSERT_EQ(37038,fileLoader->getTotalFileSize());

}

//--------------------------------testing the progressbar class ------------------------

TEST(testProgressBarClass, testProgressiveLoad){

    FileLoader* fileLoader= new FileLoader();



    Files* actual= new Files("/home/astimanuka/Desktop/test_uploader/Derived1.cpp");
    Files* actual1= new Files("/home/astimanuka/Desktop/test_uploader/Derived2.cpp");
    Files* actual2= new Files("/home/astimanuka/Desktop/test_uploader/DerivedAbstractClass.cpp");
    Files* actual3= new Files("/home/astimanuka/Desktop/test_uploader/IntMaxFunctor.cpp");
    Files* actual4= new Files("/home/astimanuka/Desktop/test_uploader/main.cpp");

    fileLoader->putFiles(*actual);
    fileLoader->putFiles(*actual1);
    fileLoader->putFiles(*actual2);
    fileLoader->putFiles(*actual3);
    fileLoader->putFiles(*actual4);

    ProgressBar* myProgress=new ProgressBar(fileLoader);

    cout<<"\t\nTesting the upload progress of files :\n"<<endl;

    myProgress->updateProgressTest();
    ASSERT_EQ(146659,myProgress->getTotalSize());
}


int main(int argc,char* argv[]){

    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();

}
