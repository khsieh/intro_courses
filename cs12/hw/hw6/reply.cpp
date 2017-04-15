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
#include "reply.h"

using namespace std;

Reply::Reply()
:Message::Message()
{
}

/* Parameterized constructor - similar to Message's constructor except:
 * The subject should be initialized to "Re: <sbjct>" not <sbjct>.
 */
Reply::Reply(const string& athr, const string& sbjct, const string& body, unsigned id)
:Message::Message(athr, sbjct, body, id)
{
}

/* print the reply to screen in the given format - see output specs for details
 * Then it invokes print_subtree(n) on each of the messages in child_list 
 * (we leave it to you to figure out what n is!)
 */
void Reply::print() const
{
    if(child_list.size() > 0)
    {
        for(unsigned i = 0; i < child_list.size();++i)
        {
            (dynamic_cast<Reply*> (child_list[i])) -> print_subtree(1);
        }
    }
}

/* This function is responsible for printing the selected Reply and all of its subtree recursively
 * After printing the Reply with the given indentation and format (see output details).
 * it calls the print_subtree function of all of the Replies in its child_list(see message)
 * with incremented indentation value.  
 *
 * Note: Each indentation value represent 2 spaces. e.g. if indentation=1 the reply should be indented
 * 2 spaces, if it's 2, indent by 4 spaces. 
 */ 
void Reply::print_subtree(unsigned indentation) const
{
    string spaces;
    for (unsigned i = 0;i < indentation; i++)
    {
        spaces += "  ";
    }
    
    cout << this -> get_subject() << endl << spaces
         << "from " << author << ": " 
         << body << endl
         << endl;
    
    for(unsigned x = 0; 0 < this -> child_list.size(); ++x)
    {
        (dynamic_cast<Reply*> (child_list.at(x))) -> print_subtree(indentation + 1);
    }
}

bool Reply::is_reply() const
{
    return true;
}

/* to_formatted_string writes the contents of the Reply to a string in the following format:
        <begin_reply>
        :id: 4
        :subject: single line
        :from: author
        :children: 5 6 [this line should not be printed if there are no children.]
        :body: multiple lines
        2nd line
        <end>
 * the line starting with :children: has the list of id's of all children (See file specs. for details)
 */
string Reply::to_formatted_string() const
{
    /**
    string formatted_string;
    
    formatted_string += "<begin_reply>\n:id: ";
    formatted_string += this -> get_id(); 
    formatted_string += "\n:subject: ";
    formatted_string += this -> get_subject();
    formatted_string += "\n:from: ";
    formatted_string += author;
    if(child_list.size() > 0)
    {
        formatted_string += ":children: ";
        for(unsigned i = 0; i < child_list.size(); ++i)
        {
            formatted_string += child_list[i] -> get_id();
            formatted_string += " ";
        }
    }
    
    formatted_string += body;
    formatted_string += "\n<end>\n";
    return formatted_string;
    */
    
    stringstream formatted_string;
    
    formatted_string << "<begin_reply>\n:id: "
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
