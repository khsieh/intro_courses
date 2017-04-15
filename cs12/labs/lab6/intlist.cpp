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

///CONSTRUCTOR AND DESTRUCTOR
/**Initialize an empty list.**/
IntList::IntList()
:head(0), tail(0), sz(0)
{
}

/**This function should deallocate all remaining dynamically allocated memory 
 * (all remaining IntNodes). **/
IntList::~IntList()
{
    IntNode* temp = head;
    while(head != NULL)
    {
        delete head;
        temp = temp -> next;
        head = temp;
    }
    
}

///ACCESSORS
/**This function prints to a single line all of the int values stored in the list, 
 * each separated by a space.**/
void IntList::print() const
{
    IntNode* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

///MUTATORS
/**This function inserts a data value (within a new node) at the front end of the list and 
 * increases size of list by 1.**/
void IntList::push_front(int value) 
{
    IntNode* temp = new IntNode(value);
    if(sz == 0)
    {
        head = temp;
        tail = head;
        sz++;
    }
    else
    {
        temp -> next = head;
        head = temp;
        sz++;
    }
        
}

/**This function inserts a data value (within a new node) at the back end of the list and 
 * increases size of list by 1.**/
void IntList::push_back(int value)
{
    IntNode* temp = new IntNode(value);
    if(sz == 0)
    {
        head = temp;
        tail = head;
        sz++;
    }
    else
    {
        tail -> next = temp;
        tail = temp;
        tail -> next = NULL;
        sz++;
    }
}

/**This function removes the value (actually removes the node that contains the value) 
 * at the front end of the list and decreases size of the list by 1. 
 * Do nothing if the list is already empty.**/
void IntList::pop_front()
{
    if(sz != 0)
    {
        IntNode* temp;
        temp = head;
        head = head -> next;
        delete temp;
        sz--;
    }
}
