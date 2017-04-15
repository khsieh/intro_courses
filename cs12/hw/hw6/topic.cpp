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
#include <sstream>
#include <string>
#include <vector>

#include "topic.h"
#include "reply.h"
#include "message.h"

using namespace std;

Topic::Topic()
:Message::Message()
{
}

Topic::Topic(const string& athr, const string& sbjct, const string& body, unsigned id)
:Message::Message(athr, sbjct, body, id)
{
}

/* this function will print the Topic as in the previous assignment.
 * Then it invokes print_subtree(1) on each of the messages in child_list 
 * (which are all "first-level" Reply objects).
 */
void Topic::print() const
{
    cout << "Message#" << this -> get_id() << ": " 
         << this -> get_subject() << endl
         << "from " << author << ": " 
         << body << endl
         << endl;
         
    if(child_list.size() > 0)
    {
        cout << "Hello??" << endl;
        for(unsigned i = 0; i < child_list.size();++i)
        {
            cout << "is there child???" << endl;
            (dynamic_cast<Reply*> (child_list.at(i))) -> print_subtree(1); // print_subtree(1)?????
        }
    }
    cout << "\n-----------------------------------------------\n";
}

bool Topic::is_reply() const
{
    return false;
}

/* to_formatted_string writes the contents of the Topic to a string in the following format:
    <begin_topic>
    :id: 4
    :subject: single line
    :from: author
    :children: 5 6 [this line should not be printed if there are no children.]
    :body: multiple lines - line 1
    line 2
    line 3
    <end>
 * line starting with :children: has the id's of all children (See file specs. for details)
 */
string Topic::to_formatted_string() const
{
    stringstream formatted_string;
    
    formatted_string << "<begin_topic>\n:id: "
                     << this -> get_id()
                     << "\n:subject: "
                     << this -> get_subject()
                     << "\n:from: "
                     << author;
    if(child_list.size() > 0)
    {
        formatted_string << ":children: ";
        for(unsigned i = 0; i < child_list.size(); ++i)
        {
            formatted_string << child_list[i] -> get_id()
                             << " ";
        }
    }
    
    formatted_string << body
                     <<"\n<end>\n";
    return formatted_string.str();
}
