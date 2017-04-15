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
// Assignment: assn3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ================================================================

#include <iostream>
#include <string>
#include <vector>
#include "message.h"

using namespace std;

//default constructor
Message::Message()
:author(),subject(),body()
{
}

//Constructor with parameters
Message::Message(const string& athr, const string& sbjct, const string& body)
:author(athr),subject(sbjct),body(body)
{
}

//displays the message in the given format. See output specs.
void Message::display() const
{
    cout << subject << endl
         << "from " << author << ": " 
         << body << endl
         << "-----------------------------------------------"
         << endl;
}
