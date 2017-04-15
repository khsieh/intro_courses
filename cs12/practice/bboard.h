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


    //inclusion guard
#ifndef _BBOARD_H_
#define _BBOARD_H_

    //includes
#include "message.h"
#include "user.h"
#include <string>
#include <vector>

using namespace std;

class Bboard {
private:
        //private member variables
    string title;                   //title of the board
    const User* current_user;       //user who is currently logged in
    vector<User> user_list;         //list of members
    vector<Message*> message_list;  //list of messages
    
public:
        //constructors
    Bboard();                   //default constructor
    Bboard( const string & );    //parameterized constructor
    ~Bboard();                  //destructor
    
        //public member functions (mutators)
    bool load_users( const string& );    //read in users from a file
    bool load_messages( const string& ); //read in messages from a file
    bool save_messages( const string& ); //write messages into a file
    void login();   //login to board
    void run();     //run the board
    
private:
        //private helper functions
    void add_user( const string&, const string& );  //add user to user vector
    const User* get_user( const string&, const string&) const; //returns
                                                    //pointer to requested user
    void display() const;   //print out all messages on board
    void add_topic();       //add new topic to board
    void add_reply();       //add new reply to a topic (or reply)
};

#endif //_BBOARD_H_

