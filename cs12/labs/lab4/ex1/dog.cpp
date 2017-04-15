#include <iostream>
#include <string>
#include "dog.h"

using namespace std;

Dog::Dog()
:name(),breed()
{
}

Dog::Dog(string n, string b)
:name(n),breed(b)
{
}

void Dog::change_name(string n)
{
    this -> name = n;
}

void Dog::print_name()
{
    if(name == "" && breed == "")
        cout << "this person doesn't have a dog.";
    else
        cout << this -> name << " : " << this -> breed << ".";
    
}
