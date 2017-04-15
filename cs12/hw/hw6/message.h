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

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
#include <vector>

using namespace std;

class Message  // abstract base class
{
    protected:  // allow access to these members by objects of derived classes
        string author;
        string subject;
        string body;
        unsigned id;  // New !!
        
        // This will be the size of the message_list vector to which the
        // newly constructed Message* is being pushed_back
        vector <Message*> child_list; // New !!
        // This is how a Message is able to keep track of its Replies

    public:

        //default constructor
        Message();

        //Parameterized onstructor; id will be the size of current Bboard message_list
        Message(const string& athr, const string& sbjct, const string& body, unsigned id);

        //be careful here, you must invoke delete on pointers to objects
        //How many Message/Reply/Topic objects do you have in your program?
        virtual ~Message();

        virtual void print() const = 0; 

        // returns true if the object is reply.
        virtual bool is_reply() const = 0;

        //returns the subject string.
        string get_subject() const;

        // returns the id.
        unsigned get_id() const; // New !!    

        virtual string to_formatted_string() const = 0;  // New !!

        // Adds a pointer to the child to child_list. 
        void add_child(Message* child); // New !! 

};

#endif //MESSAGE_H_
