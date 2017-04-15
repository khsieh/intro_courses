#ifndef _MUSIC_H_
#define _MUSIC_H_

#include <iostream>
#include <fstream>
#include "tune.h"

using namespace std;

class Music_collection
{
    private: 
        int number;   // the number of tunes actually in the collection 
        int max;      // the number of tunes the collection will ever be able to hold 
        Tune* collection;    // a dynamic array of Tunes: "Music_collection has-many Tunes"

    public:
        Music_collection();  // default value of max is a conservative 100
        Music_collection( int n );  // sets max to n
        Music_collection( const Music_collection& m);  // overloaded copy constructor

        bool add_tune( const Tune& t ); // returns true if add was successful, false if not enough room to add

        bool set_tune( int index, const Tune& t ); // sets the Tune at position index in collection to t, returns true if index<number    

        Music_collection& operator=( const Music_collection& m );   // overloaded assignment operator

        ~Music_collection();   // Destructor

        friend ostream& operator << (ostream& out, const Music_collection& m ); // overloaded stream insertion operator
};

#endif
