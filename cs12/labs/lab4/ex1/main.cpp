#include <iostream>
#include <string>
#include "person.h"
#include "dog.h"

using namespace std;

int main()
{
    Person s,t,b;
    Dog dog1 = Dog("Fido","idk");
    Dog dog2 = Dog();
    Dog* d1 = &dog1;
    Dog* d2 = &dog2;
    
    s = Person("Sally", d1);
    t = Person("Tron", d2);
    b = Person("Bob", d1);
    
    cout << "\033c";
    
    cout << "Sally's info: " << endl;
    s.print();
    cout << "\nTron's info: " << endl;
    t.print();
    cout << "\nBob's info: " << endl;
    b.print();
    cout << endl;
    
    dog1.change_name("puppy");
    
    cout << "\nSally's info: " << endl;
    s.print();
    cout << "\nTron's info: " << endl;
    t.print();
    cout << "\nBob's info: " << endl;
    b.print();
    cout << endl;
    
    return 0;
}
