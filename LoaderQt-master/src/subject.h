#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include "observer.h"

using namespace std;

class Subject {
protected:
    Subject() { }

public:
    virtual void subscribe(Observer *obs) = 0;

    virtual void unsubscribe(Observer* obs) = 0;

    virtual void notify() = 0;

    virtual ~Subject()=0;

};


#endif // SUBJECT_H
