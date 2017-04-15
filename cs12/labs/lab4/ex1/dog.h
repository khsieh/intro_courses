#ifndef DOG_H
#define DOG_H

#include <iostream>

using namespace std;

class Dog
{
    private:
        string name;
        string breed;
    public:
        Dog();
        Dog(string n, string b);
        void print_name();
        void change_name(string n);
};

#endif
