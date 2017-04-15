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
// ================================================================

#ifndef TOPIC_H_
#define TOPIC_H_

#include <string>
#include "message.h"

using namespace std;

class Topic: public Message
{   
    // no new member variables
    public:

        //default constructor
        Topic();

        //Parameterized constructor
        Topic(const string& athr, const string& sbjct, const string& body, unsigned id);

        virtual void print() const; // Major Change!!

        virtual bool is_reply() const;

        virtual string to_formatted_string() const;  // New !!

};

#endif //TOPIC_H_
