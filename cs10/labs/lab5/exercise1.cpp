#include <iostream>

using namespace std;

int main()
{
    int sequence;
        cout << "{";
    for(sequence = 0; sequence < 25; sequence++) 
        {cout << sequence << ", ";}
        cout << "25}" << endl;
    
        cout << "{";
    for(sequence = 1; sequence < 99; sequence += 2) 
        {cout << sequence << ", ";}
        cout << "99}" << endl;
    
        cout << "{";
    for(sequence = 2; sequence <= 32 && sequence > (-64);
        sequence = sequence * (-2)) 
        {cout << sequence << ", ";}
        cout << "-64}" << endl;
    return 0;
}
