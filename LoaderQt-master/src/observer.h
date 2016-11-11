#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>
#include "file.h"

using namespace std;

class Observer {

protected:
    Observer() { }

public:

    virtual void update(File file) = 0;

    virtual ~Observer()=0;
};




#endif // OBSERVER_H
