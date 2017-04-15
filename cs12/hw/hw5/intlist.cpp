// Course: CS 12 <winter,13>
/*
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
*///================================================================

#include <iostream>
#include "intlist.h"

using namespace std;

//CONSTRUCTOR AND DESTRUCTOR
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

//ACCESSORS
/**This function returns the current size (number of nodes) of the IntList object.**/
unsigned int IntList::size() const
{
    return this -> sz;
}

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

//MUTATORS
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

/**This function sorts the list into ascending order using the selection sort algorithm.**/
//from Piazza!! :D
void IntList::select_sort()
{
    IntNode* n_min = NULL;
    
    for(IntNode* cur = head; cur != NULL; cur = cur->next)
    {
        n_min = cur;
        
        for(IntNode* f_small = cur; f_small != NULL; f_small = f_small->next) 
        {
            if(n_min->data > f_small->data) 
            {
                n_min = f_small;
            }
        }
        
        int temp = n_min->data;
        n_min->data = cur->data;
        cur -> data = temp;
    }
}

/**This function assumes the values in the list are in sorted (ascending) order 
 * and inserts the data into the appropriate position in the list 
 * (so that the values will still be in ascending order after insertion). 
 * Size of the list is increased by 1.**/
void IntList::insert_sorted(int value)
{
    IntNode* newNode = new IntNode(value);
    IntNode* tracker1 = head;
    IntNode* tracker2 = head -> next;
    
    if(sz == 0)
    {
        push_back(value);
    }
    
    while(tracker1 != tail)
    {
        if(value >= tracker1 -> data &&
           value <= tracker2 -> data)
        {
            
            newNode -> next = tracker2;
            tracker1 -> next = newNode;
            sz++;
            return;
        }
        tracker1 = tracker1 -> next;
        tracker2 = tracker2 -> next;
        
    }
    
    if(value <= head -> data)
    {
        this -> push_front(value);
        return;
    }
    else if(value >= tail -> data)
    {
        this -> push_back(value);
        return;
    }
    
}

/***This function removes all values 
 * (actually removes the nodes that contain the value) 
 * that are duplicates of a value that already exists in the list.**/
void IntList::remove_duplicates()
{
    IntNode* tracker1 = head;
    IntNode* tracker2 = head -> next;
    IntNode* currentNode = head;
    
    while(currentNode != NULL)
    {
        tracker1 = currentNode;
        tracker2 = currentNode -> next;
        
        while(tracker2 != NULL)
        {
            if(currentNode -> data == tracker2 -> data)
            {
                if(tracker2 == tail)
                {
                    tail = tracker1;
                    tail -> next = NULL;
                    delete tracker2;
                    sz--;
                }
                else
                {
                    IntNode* deleteNode = tracker2;
                    while(currentNode -> data == tracker2 -> next -> data)
                    {
                        IntNode* deleteNode2 = tracker2 -> next;
                        tracker2 = tracker2 -> next;
                        delete deleteNode2;
                        sz--;
                    }
                    tracker2 = tracker2 -> next;
                    tracker1 -> next = tracker2;
                    delete deleteNode;
                    sz--;
                }
            }
            tracker1 = tracker1 -> next;
            tracker2 = tracker2 -> next;
        }
        currentNode = currentNode -> next;
    }
    
    
}

/**This function checks if the list is sorted and returns true if it is.**/
bool IntList::is_sorted()
{
    IntNode* temp = head;
    
    if(sz == 0 || sz == 1)
    {
        return true;
    }
    while(temp != tail)
    {
        if(temp -> data > (temp -> next) -> data)
            return false;
        temp = temp -> next;
    }
    
    return true;
}
