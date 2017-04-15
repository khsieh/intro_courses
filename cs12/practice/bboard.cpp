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
#include "bboard.h"
#include "topic.h"
#include "reply.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/* ------------------------     constructors       ------------------------ */
    //default constructor
Bboard::Bboard()
:title("Amanda's Amazing Bulletin Board"), current_user(NULL) {
}

    //parameterized constructor
Bboard::Bboard( const string &ttl)
:title(ttl), current_user(NULL) {
}

    //destructor (only needs to delete the message_list)
Bboard::~Bboard() {
    for ( unsigned i = 0; i < message_list.size(); ++i )
        delete message_list.at(i);
}

/* -------------------  public member functions    ------------------- */

    //add all of the valid usernames and passwords (from text file) into vector
bool Bboard::load_users(const string& userfile) {
    ifstream input( userfile.c_str() );
    
        //check if the file opened successfully
    if ( !input.is_open() )
        return false;
    
    string user, pass;  //temporarily store user and pass
    
        //keep inputting user and pass until it inputs "end"
    while ( user != "end" ) {
        input >> user;
        
        if ( user != "end" ) {
            input >> pass;
            
            add_user(user, pass);
        }
    }
    
    input.close();  //close file stream
    
    return true;
}

    //This function gets a name/path (datafile) of a file that stores the
    //messages (from previous sessions) in the given format.
    //It opens and reads a file and fills the message_list vector.
    //If an error occurs when opening the file, it returns false.
    //Returns true otherwise.
bool Bboard::load_messages(const string& datafile) {
    ifstream messageInput( datafile.c_str() );
    
        //check if the file opened successfully
    if ( messageInput.fail() )
        return false;
    
        //declare all variables needed
    unsigned messageNum;    //store how many messages there are
    string messageType, idString, subject, author, children, body;  //store
                                                                    //message
                                                                    //info
    string input, newLine;
    unsigned id, child;
    
    messageInput >> messageNum;
    getline( messageInput, newLine );
    
    vector< vector<int> > childrenVector( messageNum ); //to store all children
                                                        //info 
    
        //loop for the number of
        //messages there are
    for ( unsigned i = 0; i < messageNum; ++i ) {
        getline( messageInput, messageType );   //read in the message type
        
            //read in the id
        getline( messageInput, idString );
        idString = idString.substr(5); 
        istringstream ( idString ) >> id;
        
            //read in the subject
        getline( messageInput, subject );
        subject = subject.substr(10);
        
            //read in the author
        getline( messageInput, author );
        author = author.substr(7);
        
            //read in the next label
        messageInput >> input;
        
            //check if there are children
        if ( input == ":children:" ) {
            getline( messageInput, children );
            children = children.substr( 1 );
            
            stringstream stream( children );
            while ( stream >> child ) {
                childrenVector.at(id-1).push_back( child );
            }
            
            messageInput >> input; //get rid of ":body:"
        }
        
        body = "";  //reset body to empty
        
            //read in the body (multiple lines)
        while ( true ) {
            getline( messageInput, input );
            
            if ( input == "<end>" )
                break;
            
            body = body + input + '\n';
        }
        
        body = body.substr( 1, body.size()-1 ); //chop off space at beginning
                                                //and the last new line
        
            //add message into message_list
        if ( messageType == "<begin_topic>" ) {
            message_list.push_back( new Topic( author, subject, body, id ) );
        } else if ( messageType == "<begin_reply>" ) {
            message_list.push_back( new Reply( author, subject, body, id ) );
        }
        
    }
    messageInput.close();   //close file stream
    
        //add children to all messages
    for ( unsigned i = 0; i < message_list.size(); ++i ) {
        for ( unsigned j = 0; j < childrenVector.at(i).size(); ++j )
            message_list.at(i) ->
            add_child( message_list.at( childrenVector.at(i).at(j) - 1 ) );
    }
    
    return true;
}

    //This function gets a name/path (datafile) of a file that will store
    //all of the the messages, and after opening the file writes the messages
    //into it with the same format. If an error occurs when opening the file,
    //it returns false. Returns true otherwise.
bool Bboard::save_messages(const string& datafile) {
    ofstream messageOutput( datafile.c_str() );
    
        //check if the file opened successfully
    if ( messageOutput.fail() )
        return false;
    
    messageOutput << message_list.size() << '\n';
    
    for ( unsigned i = 0; i < message_list.size(); ++i ) {
        messageOutput << message_list.at(i) -> to_formatted_string();
    }
    
    messageOutput.close();  //close file stream
    return true;
}


    //asks for and validates current user/password
void Bboard::login() {
    string user, pass;
    
    cout << endl << endl << "Welcome to " << title << endl;
    
    cout << "Enter your username ('Q' or 'q' to exit): ";
    cin >> user;
    
    if ( user != "Q" && user != "q" ) {
        cout << "Enter your password: ";
        cin >> pass;
    }
    
        //keep asking for username and password until given a valid combo
        //or 'Q' or 'q' are entered
    while( get_user(user, pass) == NULL && user != "Q" && user != "q" ) {
        cout << "Invalid Username or Password!" << endl << endl;
        cout << "Enter your username ('Q' or 'q' to exit): ";
        cin >> user;
        
        if ( user != "Q" && user != "q" ) {
            cout << "Enter your password: ";
            cin >> pass;
        } 
    }
    
        //greet/say goodbye to user
    if ( get_user(user, pass) != NULL ) {
        current_user = get_user(user, pass);
        cout << "Welcome back " << user << '!' << endl << endl;
    } else {
        cout << "Bye!" << endl;
        exit(0);
    }
}

    //contains the main loop of the bboard
void Bboard::run() {
    
    if ( current_user == NULL )
        exit(1);
    
    char action;
    
        //prompt user for input
    while ( action != 'Q' && action != 'q' ) {
        cout << "Menu" << endl;
        cout << "  - Display Messages ('D' or 'd')" << endl;
        cout << "  - Add New Topic ('N' or 'n')" << endl;
        cout << "  - Quit ('Q' or 'q')" << endl;
        cout << "  - Add Reply to a Topic ('R' or 'r')" << endl;
        cout << "Choose an action: ";
        cin >> action;
        cout << endl;
        
            //select what action to take
        switch (action) {
            case 'D':
            case 'd':
                display();
                break;
            case 'N':
            case 'n':
                add_topic();
                break;
            case 'R':
            case 'r':
                add_reply();
                break;
            case 'Q':
            case 'q':
                cout << "Bye!" << endl;
                return;
                
            default:
                break;
        }
    }
}


/* -------------------  private helper functions    ------------------- */
    //add user to users vector
void Bboard::add_user(const string& user, const string& pass) {
    user_list.push_back( User(user, pass) );
}

    //returns User of given username
const User* Bboard::get_user(const string& user, const string& pass) const {
    
    for ( unsigned i = 0; i < user_list.size(); i++ ) {
        if ( user_list.at(i).check(user, pass) )
            return &user_list.at(i);
    }
    
    return NULL;
}

    //displays all messages in message_list
void Bboard::display() const {
    
    if ( message_list.size() == 0 )
        cout << "Nothing to Display." << endl << endl;
    else {
        for ( unsigned i = 0; i < message_list.size(); i++ ) {
            if ( !(message_list.at(i) -> is_reply()) ) {
                cout << "-----------------------------------------------" << endl;
                ( dynamic_cast<Topic*>(message_list.at(i)) ) -> print();
            }
            
        }
        cout << "-----------------------------------------------"
             << endl << endl;
    }
}

    //add new topic to board
void Bboard::add_topic() {
    string subject, body, input = " ";
    unsigned newID = message_list.size() + 1;
    
    cin.ignore(1000, '\n');
    
    cout << "Subject: ";
    getline(cin, subject);
    
    cout << "Body: ";
    while ( input != "" ) {
        getline(cin, input);
        if ( input != "" )
            body = body + input + '\n';
    }
    body = body.substr(0, body.size() - 1);
    
    message_list.push_back( new Topic( current_user->get_username(), subject,
                                       body, newID ) );
    
    cout << "Message Recorded!" << endl << endl;
    
}

    //add new reply to a topic (or reply)
void Bboard::add_reply() {
    string subject, body, input = " ";
    int messageNumber = 0;
    unsigned newID = message_list.size() + 1;
    
    do {
        cout << "Enter Message ID (-1 for Menu): ";
        cin >> messageNumber;
        if ( messageNumber > static_cast<int>(message_list.size()) ||
             messageNumber == 0 )
            cout << "Invalid Message ID!!" << endl << endl;
        else if ( messageNumber < 0 )
            return;
    } while( messageNumber > static_cast<int>(message_list.size()) ||
             messageNumber < 1 );
    
    cin.ignore(1000, '\n');
    
    subject = "Re: " + message_list.at(messageNumber-1) -> get_subject();
    
    cout << "Body: ";
    while ( input != "" ) {
        getline(cin, input);
        if ( input != "" )
            body = body + input + '\n';
    }
    body = body.substr(0, body.size() - 1);
    
    message_list.push_back( new Reply( current_user->get_username(), subject,
                                       body, newID ) );
    
    message_list.at(messageNumber-1) ->
    add_child( message_list.at( message_list.size()-1 ) );
}

