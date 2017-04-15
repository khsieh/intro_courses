#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num = 2;
    
    int * p_num1;
    int * p_num2 = NULL;
    int * p_num3 = &num;
    int * p_num4 = new int();
    int * p_num5 = p_num4;
    
    /**
    int something = 22;
    int * p_to_sth;
    p_to_sth = &something;
    
    //cout << & something << endl;
    cout << p_to_sth << endl;
    cout << * p_to_sth << endl;
    */
    
    cout << "\033c";
    
    cout << "Locations of what each pointer points to: " << endl
         << p_num1 << endl
         << p_num2 << endl
         << p_num3 << endl
         << p_num4 << endl
         << p_num5 << endl << endl;
    
    cout << "Location of each pointer itself: " << endl
         << &p_num1 << endl
         << &p_num2 << endl
         << &p_num3 << endl
         << &p_num4 << endl
         << &p_num5 << endl << endl;
    
    cout << "Value of each pointer location: " << endl
         << *p_num1 << endl
         //<< *p_num2 << endl //pointer location is NULL (or 0)
                              //not a valid memory location
         << *p_num3 << endl
         << *p_num4 << endl;
         //<< *p_num5 << endl << endl; //pointer location is NULL (or 0)
                                       //not a valid memory location
    
    //delete p_num1; //point location was not reserved, so could not be deleted.
    delete p_num2;   //point location is NULL, works but shouldn't be deleted.
    //delete p_num3; //point location is in stack so can not be deleted.
    delete p_num4;
    delete p_num5;   //same as p_num2, special case of NULL
    
    cout << "Locations of what each pointer points to: " << endl
         << p_num1 << endl
         << p_num2 << endl
         << p_num3 << endl
         << p_num4 << endl
         << p_num5 << endl << endl;

    return 0;
}
