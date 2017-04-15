#include <iostream>
#include <fstream>
#include "music.h"
#include "tune.h"

using namespace std;

Music_collection::Music_collection()
:number(0), max(100), collection( new Tune[100] )
{}

Music_collection::Music_collection(int n)
:number(0), max(n), collection( new Tune [n] )
{}

Music_collection::Music_collection( const Music_collection& m)
:number(m.number), max(m.max)
{
    this -> collection = new Tune [max];
    for(int i = 0; i < m.number; ++i)
    {
        this -> collection[i] = m.collection[i];
    }
}

bool Music_collection::add_tune(const Tune& t)
{
    if(number >= max)
        return false;
        
    else if(number < max)
    {
        this -> collection[this -> number] = t;
        number++;
    }
    return true;
}

bool Music_collection::set_tune(int index, const Tune& t)//overwirte current index
{
    if(index > number)
        return false;
        
    else if(index <= number)
    {
        this -> collection[index] = t;
    }
    return true;
}

Music_collection& Music_collection::operator=( const Music_collection& m )
{
    if (&m != this)
    {
        delete [] this -> collection;
        
        this -> number = m.number;
        this -> max = m.max;
        this -> collection = new Tune [max];
        for(int i = 0; i < m.number; ++i)
        {
            this -> collection[i] = m.collection[i];
        }
    }
    return *this;
}

Music_collection::~Music_collection()
{
    delete [] collection;
}

ostream& operator << (ostream& out, const Music_collection& m )
{
    for (int i = 0; i < m.number; i++)
    {
        out << (m.collection[i]).get_title() << endl;
    }
    return out;
}
