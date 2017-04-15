// Course: CS 12 <winter,13>
//
// First Name: Kevin
// Last Name:  Hsieh
// Login id: khsie003
// email address: khsie003@ucr.edu
//
// Lecture Section: 001
// Lab Section: 023
// TA:Mike Izbicki
//
// Assignment: assn5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ================================================================

#include <iostream>
#include "intlist.h"

using namespace std;

int main()
{
    IntList list;
    
    list.print(); //print out nothing
    
    list.push_front(5);
    list.push_front(5);
    
    list.print(); //print out 5 5
    
    list.push_back(4); 
    
    list.print(); //print out 5 5 4
    
    list.pop_front();
    
    list.print(); //print out 5 4
    
    return 0;
}
