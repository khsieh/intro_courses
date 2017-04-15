#include <iostream>
#include <string>
#include "dog.h"
#include "person.h"

using namespace std;

Person::Person()
:name(),dog()
{
}


Person::Person(string n, Dog* d)
:name(n),dog(d)
{
}


void Person::print()
{
    cout << this -> name << endl << "\t";
    dog -> print_name();
}
