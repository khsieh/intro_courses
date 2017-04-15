#ifndef PERSON_H
#define PERSON_H

#include "dog.h"

using namespace std;

class Person 
{
    private:
        string name;
        Dog* dog;
    public:
        Person();
        Person(string name, Dog* d);
        void print();
        
};
#endif
