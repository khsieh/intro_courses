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

#ifndef BBOARD_H_
#define BBOARD_H_

#include <vector>
#include <string>

#include "user.h"
#include "message.h"
#include "topic.h"
#include "reply.h"

using namespace std;

class Bboard
{
    private:
        string title;
        vector <User> user_list;
        const User* current_user;
        vector <Message*> message_list;
    
    //interface functions
    public:
        Bboard();
        Bboard( const string & ttl);
        ~Bboard();
        bool load_users(const string& userfile);
        bool load_messages( const string& datafile);
        bool save_messages( const string& datafile);
        void login();
        void run();
        
    //private member functions
    private:
        void add_user( const string& name, const string& pw);
        const User* get_user ( const string& name, const string& pw) const;
        void display() const;
        void add_topic();
        void add_reply();
        
};

#endif //BBOARD_H_
