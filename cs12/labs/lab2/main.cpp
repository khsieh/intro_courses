#include <iostream>
#include <string>
#include <cmath>
#include "rational.h"

using namespace std;

int main()
{
    int option;
    Rational a(1,2), b(3,4), answer;
    
    //answer = r.divide(r1);
    //answer.display();
    
    /** ask user for math option to operate on the Rational A and B*/
    cout << "A: 1/2" << endl << "B: 3/4" << endl
         << "1: Addition (A + B)" << endl
         << "2: Subtraction (A - B)" << endl
         << "3: Division (A / B)" << endl
         << "4: Multiplication (A * B)" << endl
         << "Please select (1-4) from the menu: " << endl;
         
    /**check for option number and use function accordingly*/
    do
    {
        cin  >> option;
        switch(option)
        {
            case 1:
                //add
                answer = a.add(b);
                answer.display();
                break;
            case 2:
                //sub
                answer = a.subtract(b);
                answer.display();
                break;
            case 3:
                //div
                answer = a.divide(b);
                answer.display();
                break;
            case 4:
                //mul
                answer = a.multiply(b);
                answer.display();
                break;
            default:
                //??
                cout << "invalid option, please enter another: ";
        }
    }
    while(option != 1 && option != 2  && option != 3 && option != 4);
    return 0;
}
