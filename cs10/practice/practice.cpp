#include <iostream>
//~ #include <vector>
//~ #include <ctime>
//~ #include <cstddef>
//~ #include <cstdlib>

using namespace std;

int main ()
{
    int a = 100;
    int b = 10;
    cout << "BEFORE::" << endl;
    cout << "a: " << a  << endl;
    cout << "b: " << b  << endl;
    a <<= 5;
    b >>= 3;
    cout << "AFTER::" << endl;
    cout << "a: " << a  << endl;
    cout << "b: " << b  << endl;
    
    return 0;
}
