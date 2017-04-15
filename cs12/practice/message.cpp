    // Course: CS 12 Winter 2013
    //
    // First Name: Amanda
    // Last Name: Berryhill
    // Course username: aberr005
    // email address: aberr005@ucr.edu
    //
    // Lecture Section: 001
    // Lab Section: 023
    // TA: Mike Izbicki
    //
    // Assignment: assn6
    //
    // I hereby certify that the code in this file
    // is ENTIRELY my own original work.
    //
    // =================================================================


    //includes
#include "message.h"
#include <iostream>

using namespace std;

    //default constructor
Message::Message()
:author(""), subject(""), body(""), id(0) {
}

    //Parameterized constructor; id will be the size of current Bboard message_list
Message::Message(const string& athr, const string& sbjct, const string& body, unsigned id)
:author(athr), subject(sbjct), body(body), id(id) {
}

    //be careful here, you must invoke delete on pointers to objects
    //How many Message/Reply/Topic objects do you have in your program?
Message::~Message() {
}

    //returns the subject string.
string Message::get_subject() const {
    return subject;
}

    // returns the id.
unsigned Message::get_id() const {
    return id;
}

    // Adds a pointer to the child to child_list.
void Message::add_child(Message* child) {
    child_list.push_back(child);
}

