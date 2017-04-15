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
#include "topic.h"
#include "reply.h"
#include <iostream>
#include <sstream>

using namespace std;

Topic::Topic()
:Message() {
}

    //Parameterized constructor
Topic::Topic(const string& athr, const string& sbjct, const string& body, unsigned id)
:Message(athr, sbjct, body, id) {
}

/* this function will print the Topic as in the previous assignment.
 * Then it invokes print_subtree(1) on each of the messages in child_list
 * (which are all "first-level" Reply objects).
 */
void Topic::print() const {
    cout << "Message #" << id << ": " << subject << endl;
    cout << "from " << author << ": " << body << endl;
    
    for ( unsigned i = 0; i < child_list.size(); ++i ) {
        ( dynamic_cast<Reply*>(child_list.at(i)) ) -> print_subtree(1);
    }
    
}

    //returns if message is a reply or not
bool Topic::is_reply() const {
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
string Topic::to_formatted_string() const {
    string formattedString;
    
    formattedString =   "<begin_topic>\n:id: " + convertInt(id) +
                        "\n:subject: " + subject +
                        "\n:from: " + author;
    
    if ( !child_list.empty() ) {
        formattedString = formattedString + "\n:children: ";
        for (unsigned i = 0; i < child_list.size(); ++i) {
            formattedString = formattedString + convertInt( child_list.at(i)->get_id() ) + " ";
        }
    }
    
    formattedString =   formattedString +
                        "\n:body: " + body +
                        "\n<end>\n";
    
    return formattedString;
}

string Topic::convertInt(const unsigned& number) const {
    stringstream ss;//create a stringstream
    ss << number;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}

