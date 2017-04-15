#include <iostream>
#include <string>

using namespace std;

int main()
{
    int val = 42;
    int *int_ptr = new int(21);
    int *val_ptr1 = &val;
    int *val_ptr2 = &val;
    
    cout << "\033c";
    
    *val_ptr2 += 100;
    
    cout << "memory diagram: " << endl
         << "what is stroed by each variable: " << endl
         << "val \t\t" << val << endl
         << "int_ptr \t" << int_ptr << endl
         << "val_ptr1 \t" << val_ptr1 << endl
         << "val_ptr2 \t" << val_ptr2 << endl
         << "the location of each variable: " << endl
         << "val \t\t" << &val << endl
         << "int_ptr \t" << &int_ptr << endl
         << "val_ptr1 \t" << &val_ptr1 << endl
         << "val_ptr2 \t" << &val_ptr2 << endl
         << "dereference of each pointer variable: " << endl
         << "int_ptr \t" << *int_ptr << endl
         << "val_ptr1 \t" << *val_ptr1 << endl
         << "val_ptr2 \t" << *val_ptr2 << endl << endl;
    
    val_ptr1 = int_ptr;
    
    cout << "memory diagram: " << endl
         << "what is stroed by each variable: " << endl
         << "val \t\t" << val << endl
         << "int_ptr \t" << int_ptr << endl
         << "val_ptr1 \t" << val_ptr1 << endl
         << "val_ptr2 \t" << val_ptr2 << endl
         << "the location of each variable: " << endl
         << "val \t\t" << &val << endl
         << "int_ptr \t" << &int_ptr << endl
         << "val_ptr1 \t" << &val_ptr1 << endl
         << "val_ptr2 \t" << &val_ptr2 << endl
         << "dereference of each pointer variable: " << endl
         << "int_ptr \t" << *int_ptr << endl
         << "val_ptr1 \t" << *val_ptr1 << endl
         << "val_ptr2 \t" << *val_ptr2 << endl << endl;
         
    delete int_ptr;
    //delete val_ptr1;
    //delete val_ptr2;
    
    cout << "memory diagram: " << endl
         << "what is stroed by each variable: " << endl
         << "val \t\t" << val << endl
         << "int_ptr \t" << int_ptr << endl
         << "val_ptr1 \t" << val_ptr1 << endl
         << "val_ptr2 \t" << val_ptr2 << endl
         << "the location of each variable: " << endl
         << "val \t\t" << &val << endl
         << "int_ptr \t" << &int_ptr << endl
         << "val_ptr1 \t" << &val_ptr1 << endl
         << "val_ptr2 \t" << &val_ptr2 << endl
         << "dereference of each pointer variable: " << endl
         << "int_ptr \t" << *int_ptr << endl
         << "val_ptr1 \t" << *val_ptr1 << endl
         << "val_ptr2 \t" << *val_ptr2 << endl << endl;
    
    return 0;
}
