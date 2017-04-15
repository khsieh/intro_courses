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

#ifndef REPLY_H_
#define REPLY_H_

#include <string>
#include "message.h"

class Reply: public Message
{
    // no new member variables

    public:
        //default constructor
        Reply();

        Reply(const string& athr, const string& sbjct, const string& body, unsigned id);

        virtual void print() const;

        virtual void print_subtree(unsigned indentation) const; // New !!

        virtual bool is_reply() const; //return trueeeeeeeeee;

        virtual string to_formatted_string() const; // New !!

};
  
#endif
