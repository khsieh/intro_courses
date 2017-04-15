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

#ifndef BBOARD_H
#define BBOARD_H

#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "message.h"

using namespace std;

class Bboard
{
    /**private member variables**/
    private:
        string title;                   //title of board, initialize via c'tor
        vector<User> user_list;         //list of members, empty, populate via setup()
        User current_user;              //current log-in user, default by c'tor, set via login()
        vector<Message> message_list;   //list of message, initially empty
    /**public interface functoins**/
    public:
        //default c'tor: default title, empty user list, empty message list, & default user
        Bboard();
        
        //same as default c'tor, but set the title of board
        Bboard(const string& ttl);
        
        /* setup()
         * import authorized user from input file, storing as User in user_list
         * read list of members from file using stdin
         */
        void setup();
        
        /* login()
         * ask current user for username and password
         * check for validation:
            * set current_user to user input if true
            * repeat to ask for new username/password if false
            * terminate program [eixt(0)] if input is 'q' / 'Q'
         */
        void login();
        
        /* run()
         * contains main loop of board
         * does not execute if no valid user from login()
         * Display Message (D or d) || Add New Message (N or n) || Quit (Q or q)
         * execute private functions accordingly, 
         * if not valid option, repeat to ask for valid
         * upon reciving Quit option terminate program by exit(0)
         */
        void run();
        
    /**private helper functions**/ 
    private:
        /* add_user
         * called from setup()
         * add users to user_list
         */
        void add_user(const string& name, const string& pass);
        
        /* user_exists
         * check if username/password combination fits User in user_list
         * return true if found
         * false otherwise
         */ 
        bool user_exists(const string& name, const string& pass) const;
        
        /* get_user
         * return the User with given name, use in login to set current_user
            * only when user_exist is true
         * only way to set current_user   
         */
        User get_user(const string& name) const;
        
        /* display
         * use in the interface run()
         * outputs all messages in message_list
         */
        void display() const;
        
        /* add_message
         * use in the interface run()
         * ask user to input message
            * include subject line and message line
            * current_user is store as author 
         */
        void add_message();
        
};

#endif //BBOARD_H
