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
// Assignment: assn6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===============================================================

#include <iostream>
#include "message.h"
#include <string>
#include <vector>

using namespace std;

//default constructor
Message::Message()
:author(),subject(),body(),id()
{
}

//Constructor with parameters
Message::Message(const string& athr, const string& sbjct, const string& body, unsigned id)
:author(athr),subject(sbjct),body(body), id(id)
{
}

//Destructor 
//WRONG DON'T DO THIS PLS FOR THE LOVE OF CODEGOD
//PLSS PLS S DON'T DO BAD CODE
/** DO THE FOLLOWING INSTEAD
 *  WHILE(!CHILD_LIST.EMPTY()){
 *      CHILD_LIST.POP_BACK(); 
 *  }
 **/
Message::~Message()
{
    if(!child_list.empty())
    {
        for(unsigned i = 0; i < child_list.size(); ++i)
        {
            delete child_list[i];
        }
    }
}

//Accessors
string Message::get_subject() const
{
    return this -> subject;
}

unsigned Message::get_id() const
{
    return this -> id;
}

void Message::add_child(Message* child)
{
    this -> child_list.push_back(child);
}
