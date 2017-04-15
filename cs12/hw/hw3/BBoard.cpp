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

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "bboard.h"
#include "user.h"
#include "message.h"

using namespace std;

/**=======================Constructors===============================**/
//default c'tor: default title, empty user list, empty message list, & default user
Bboard::Bboard()
:title(),user_list(),current_user(),message_list()
{
}

//same as default c'tor, but set the title of board
Bboard::Bboard(const string& ttl)
:title(ttl)
{
}

/**===================Public Interface Functions===================**/
/* setup()
 * import authorized user from input file, storing as User in user_list
 * read list of members from file using stdin
 */
void Bboard::setup()
{
    string name,pwd;
    
    while(cin >> name)
    {
        if (name == "end")
        {
            break;
        }
        else
        {
            cin >> pwd;
            //ADDUSER
            add_user(name,pwd);
        }
    }
    
}

/* login()
 * ask current user for username and password
 * check for validation:
    * set current_user to user input if true
    * repeat to ask for new username/password if false
    * terminate program [eixt(0)] if input is 'q' / 'Q'
 */
void Bboard::login()
{
    string user,pwd;
    cout << "Welcome to " << title << endl;
    do
    {
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin  >> user;
        
        if(user == "q" || user == "Q") 
        {
            cout << "\nBye!" << endl;
            exit(EXIT_SUCCESS);
        }
        
        cout << "Enter your password: ";
        cin  >> pwd;
        
        if(user_exists(user,pwd))
        {
            current_user = get_user(user);
            cout << "Welcome back " << current_user.get_username() << "!" << endl;
        }
        
        else
        {
            cout << "Invalid Username or Password!" << endl << endl;
        }
    }
    while(!user_exists(user,pwd));
    
    
    
}

/* run()
 * contains main loop of board
 * does not execute if no valid user from login()
 * Display Message (D or d) || Add New Message (N or n) || Quit (Q or q)
 * execute private functions accordingly, 
 * if not valid option, repeat to ask for valid
 * upon reciving Quit option terminate program by exit(0)
 */
void Bboard::run()
{
    char action;
    
    while("TARDIS" == "TARDIS")
    {
        cout << endl << "Menu" << endl
             << " - Display Messages ('D' or 'd')" << endl
             << " - Add New Message ('N' or 'n')" << endl
             << " - Quit ('Q' or 'q')" << endl
             << "Choose an action: ";
        cin  >> action;
        
        //Display option
        if(action == 'D' || action == 'd')
        {
            if(message_list.size() == 0)
            {
                cout << "\nNothing to Display." << endl;
            }
            else
            {
                cout << "\n-----------------------------------------------" 
                     << endl;
                for(unsigned int m = 0; m < message_list.size(); ++m)
                {
                    
                    cout << "Message #" << m + 1 << ": ";
                    message_list.at(m).display();
                }
            }
        }
        
        //Add New Message option
        else if(action == 'N' || action == 'n')
        {
            add_message();
        }
        
        //Quit option
        else if(action == 'Q' || action == 'q')
        {
            cout << "\nBye!" << endl;
            exit(EXIT_SUCCESS);
            
        }
    }
    
}


/**=======================Private Member Functions=======================**/
/* add_user
 * called from setup()
 * add users to user_list
 */
void Bboard::add_user(const string& name, const string& pass)
{
    User temp_user(name,pass);
    user_list.push_back(temp_user);
}


/* user_exists
 * check if username/password combination fits User in user_list
 * return true if found
 * false otherwise
 */ 
bool Bboard::user_exists(const string& name, const string& pass) const
{
    for(unsigned int y = 0; y < user_list.size(); ++y)
    {
        if(user_list.at(y).check(name,pass))
            return true;
    }
    
    return false;
}


/* get_user
 * return the User with given name, use in login to set current_user
    * only when user_exist is true
 * only way to set current_user
 */
User Bboard::get_user(const string& name) const
{
    User temp_user;
    
    for(unsigned int t = 0; t < user_list.size(); ++t)
    {
        if(name == user_list.at(t).get_username())
        {
            temp_user = user_list.at(t);
        }
    }
    return temp_user;
    
}


/* display
 * use in the interface run()
 * outputs all messages in message_list
 */
void Bboard::display() const
{
    for(unsigned int u = 0; u < message_list.size(); ++u)
    {
        message_list.at(u).display();
    }
    
}


/* add_message
 * use in the interface run()
 * ask user to input message
    * include subject line and message line
    * current_user is store as author 
 */

void Bboard::add_message()
{
    string subj,body;
    cin.ignore();
    cout << "\nEnter Subject: ";
    getline(cin,subj);
    
    cout << "Enter Body: ";
    getline(cin,body);
    
    Message msg = Message(current_user.get_username(),subj,body);
    
    message_list.push_back(msg);
    
    cout << "Message Recorded!" << endl;
    
}
