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

#ifndef INTLIST_H
#define INTLIST_H

struct IntNode
{
   int data;
   IntNode* next;
   IntNode( int data ) : data( data ), next( 0 ) {}
   IntNode( ) : data( 0 ), next( 0 ) {}
};

class IntList
{
    private:
        IntNode* head;
        IntNode* tail;
        unsigned int sz;
        
    public:
        IntList();
        ~IntList();
        unsigned int size() const;
        void print() const;
        void push_front(int value);
        void push_back(int value);
        void pop_front();
        void select_sort();
        void insert_sorted(int value);
        void remove_duplicates();
};


#endif
