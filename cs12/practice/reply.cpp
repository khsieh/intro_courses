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
#include "reply.h"
#include <sstream>

using namespace std;

Reply::Reply()
:Message() {
}

/* Parameterized constructor - similar to Message's constructor except:
 *  The subject should be initialized to "Re: <sbjct>" not <sbjct>.
 */
Reply::Reply(const string& athr, const string& sbjct, const string& body, unsigned id)
:Message(athr, sbjct, body, id) {
}

/* print the reply to screen in the given format - see output specs for details
 * Then it invokes print_subtree(n) on each of the messages in child_list
 * (we leave it to you to figure out what n is!)
 */
void Reply::print() const {
    cout << "Message #" << id << ": " << subject << endl;
    cout << "from " << author << ": " << body << endl;
}

/* This function is responsible for printing the selected Reply and all of its subtree recursively
 * After printing the Reply with the given indentation and format (see output details).
 * it calls the print_subtree function of all of the Replies in its child_list(see message)
 * with incremented indentation value.
 *
 * Note: Each indentation value represent 2 spaces. e.g. if indentation=1 the reply should be indented
 * 2 spaces, if it's 2, indent by 4 spaces.
 */
void Reply::print_subtree(unsigned indentation) const {
    
    cout << endl;
    for ( unsigned i = 0; i < indentation; ++i )
        cout << "  ";
    cout << "Message #" << id << ": " << subject << endl;
    
    for ( unsigned i = 0; i < indentation; ++i )
        cout << "  ";
    cout << "from " << author << ": ";
    
    for ( unsigned i = 0; i < body.size(); ++i ) {
        if ( body.at(i) == '\n' ) {
            cout << endl;
            for ( unsigned i = 0; i < indentation; ++i )
                cout << "  ";
        }
        else
            cout << body.at(i);
    }
    
    cout << endl;
    
    for ( unsigned i = 0; i < child_list.size(); ++i ) {
        ( dynamic_cast<Reply*>(child_list.at(i)) ) -> print_subtree(indentation + 1);
    }
}

    //returns if message is a reply or not
bool Reply::is_reply() const {
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
string Reply::to_formatted_string() const {
    string formattedString;
    
    formattedString =   "<begin_reply>\n:id: " + convertInt(id) +
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

    //helper function to convert int to string
string Reply::convertInt(const unsigned& number) const {
    stringstream ss;//create a stringstream
    ss << number;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}

