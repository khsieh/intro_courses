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
// Assignment: assn4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ================================================================

#ifndef INTVECTOR_H
#define INTVECTOR_H

using namespace std;

class IntVector
{
    /**private data fields*/
    private:
        int* data; //pointer to start of array of integers
        unsigned vcapacity; // how many int is in the array
        unsigned vsize; //how many int does it currently hold
        
    /**public member functions*/
    public:
        /**Constructors and Destructors*/
        IntVector();
        IntVector(unsigned size);
        IntVector(unsigned size, int value);
        ~IntVector();
        
        /**Accessors*/
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & operator[](unsigned index)const;
        const int & front() const;
        const int & back() const;
        
        /**Mutators*/
        void insert(unsigned index, int data);
        void erase(unsigned index);
        void push_back(int data);
        void pop_back();
        void clear();
        void resize(unsigned sz);
        void resize(unsigned sz, int value);
        void reserve(unsigned n);
        void assign(unsigned n, int value);
        int & at( unsigned index);
        int & operator[](unsigned index);
        int & front();
        int & back();
        
    /**private helper functions*/
    private:
        void expand();
        void expand(unsigned amount);
};

#endif
