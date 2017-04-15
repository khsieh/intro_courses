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

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

#include "Bboard.h"
#include "user.h"
#include "message.h"
#include "topic.h"
#include "reply.h"

using namespace std;

/**CONSTRUCTORS AND DESTRUCTOR**/
Bboard::Bboard()
:title(""), user_list(), current_user(NULL), message_list()
{
}

Bboard::Bboard( const string & ttl)
:title(ttl), user_list(), current_user(NULL), message_list()
{
}

Bboard::~Bboard()
{
    if(!message_list.empty())
    {
        for(unsigned i = 0; i < message_list.size(); ++i)
        {
            delete message_list[i];
        }
    }
}

/**PUBLIC MEMBER FUNCTIONS**/
bool Bboard::load_users(const string& userfile)
{
    ifstream input(userfile.c_str());
    if(!input)
    {
        return false;
        //exit(1);
    }
    
    else
    {
        string username, pass;
        while(input >> username >> pass)
        {
            add_user(username, pass);
        }
        
    return true;
    }
}

bool Bboard::load_messages( const string& datafile)
{
    ifstream input(datafile.c_str());
    if(!input.is_open())
    {
        return false;
    }
    
    unsigned msg_id = 0;
    int num_of_msg = 0;//, children_id = 0;
    string subj = "",
           athr = "",
           body = "",
           header = "",
           junk = "", 
           hold = "", 
           child_id = "", 
           hold_id = "";
    
    vector <string> children_id_list;
    input >> num_of_msg;
    
    for(int i = 0; i < num_of_msg; ++i)
    {
        input >> header;
        
        //TOPICS
        if(header == "<begin_topic>")
        {
            while(input >> junk)
            {
                //id
                if(junk == ":id:")
                {
                    input >> msg_id;
                    //cout << msg_id << endl;
                }
                    
                //subject
                else if(junk == ":subject:")
                {
                    getline(input, subj);
                    //cout << subj<< endl;
                }
                
                //author
                else if(junk == ":from:")
                {
                    input >> athr;
                    //cout << athr << endl;
                }
                //children
                else if(junk == ":children:")
                {
                    //child_id += msg_id;
                    getline(input, hold_id);
                    child_id += hold_id;
                    children_id_list.push_back(child_id);
                    //cout << child_id << endl;
                    child_id = "";
                }
                
                //body
                else if (junk == ":body:")
                {
                    getline(input, hold);
                    //cout << hold << endl;
                    while (hold != "<end>")
                    {
                        //cout << hold << endl;
                        body += hold;
                        body += "\n";
                        getline(input, hold);   
                    }
                    if(hold == "<end>")
                    {
                        Message* newTopic = new Topic(athr,subj,body,msg_id);
                        message_list.push_back(newTopic);
                        //newTopic -> print();
                        body = "";
                        hold = "";
                        break;
                    }
                }
                
            }
        }
        
        //REPLIES
        else
        {
            while(input >> junk)
            {
                //id
                if(junk == ":id:")
                {
                    input >> msg_id;
                    //cout << msg_id << endl;
                }
                    
                //subject
                else if(junk == ":subject:")
                {
                    getline(input, subj);
                    //cout << subj<< endl;
                }
                
                //author
                else if(junk == ":from:")
                {
                    input >> athr;
                    //cout << athr << endl;
                }
                //children
                else if(junk == ":children:")
                {
                    //child_id += msg_id;
                    getline(input, hold_id);
                    child_id += hold_id;
                    children_id_list.push_back(child_id);
                    //cout << child_id << endl;
                    child_id = "";
                }
                
                //body
                else if (junk == ":body:")
                {
                    getline(input, hold);
                    //cout << hold << endl;
                    while (hold != "<end>")
                    {
                        //cout << hold << endl;
                        body += hold;
                        body += "\n";
                        getline(input, hold);   
                    }
                    if(hold == "<end>")
                    {
                        Message* newReply = new Reply(athr,subj,body,msg_id);
                        message_list.push_back(newReply);
                        //newTopic -> print();
                        body = "";
                        hold = "";
                        break;
                    }
                }
                
            }
        }
    }
    
    //children!!
    for(unsigned i = 0; i < children_id_list.size(); ++i)
    {
        if (children_id_list.at(i) != "")
        {
            string cl_id = children_id_list.at(i);
            int c_id;
            stringstream idint(cl_id);
            while(idint >> c_id)
            {
                for (unsigned i = 0; i < message_list.size(); i++)
                {
                    if(message_list.at(i) -> get_id() == i)
                    {
                        message_list.at(i) -> add_child(message_list.at(c_id));
                    }
                }
            }
        }
        
    }
    
    input.close();
    return true;
}

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
        
        if(get_user(user,pwd) != NULL)
        {
            current_user = get_user(user,pwd);
            cout << "Welcome back " << current_user -> get_username() 
                 << "!" << endl;
        }
        
        else
        {
            cout << "Invalid Username or Password!" << endl << endl;
        }
    }
    while(get_user(user,pwd) == NULL);
}

void Bboard::run()
{
    char action;
    
    while(true)
    {
        cout << endl << "Menu" << endl
             << " - Display Messages ('D' or 'd')" << endl
             << " - Add New Topic ('N' or 'n')" << endl
             << " - Add Reply to a Topic ('R' or 'r')" << endl
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
                display();
            }
        }
        
        //Add New Topic option
        else if(action == 'N' || action == 'n')
        {
            add_topic();
        }
        
        //Add Reply to Topic option
        else if(action == 'R' || action == 'r')
        {
            add_reply();
        }
        
        //Quit option
        else if(action == 'Q' || action == 'q')
        {
            cout << "\nBye!" << endl;
            return;
            
        }
    }
    
}

bool Bboard::save_messages( const string& datafile)
{
    ofstream output(datafile.c_str());
    if(!output)
        return false;
    else
    {
        for(unsigned p=0; p < message_list.size(); ++p)
        {
            output << message_list[p] -> to_formatted_string();
        }
        return true;
    }
}

/**PRIVATE HELPER FUNCTIONS**/

void Bboard::add_user( const string& name, const string& pw)
{
    User temp_user(name,pw);
    user_list.push_back(temp_user);
}


const User* Bboard::get_user(const string& name, const string& pw) const
{
    for(unsigned int y = 0; y < user_list.size(); ++y)
    {
        if(user_list.at(y).check(name,pw))
            return &user_list.at(y);
    }
    
    return NULL;
}

void Bboard::display() const
{
    for(unsigned i = 0; i < message_list.size(); ++i)
    {
        if(!(message_list.at(i) -> is_reply()))
        {
            message_list.at(i) -> print();
        }
    }
}

void Bboard::add_topic()
{
    string subj, body;
    cout << "Enter Subject: ";
    cin  >> subj;
    cout << "Enter body: ";
    cin.ignore();
    getline(cin,body);
    
    Topic* newTopic = new Topic( current_user -> get_username(), 
                                 subj,body, message_list.size() + 1);
    message_list.push_back(newTopic);
}

void Bboard::add_reply()
{
    string subj, body;
    unsigned msg_id;
    cout << "Enter message id you wish to reply: ";
    cin  >> msg_id;
    if(msg_id <= 0)
        return;
    
    subj += "Re: ";
    subj += message_list[msg_id] -> get_subject();
    cout << "Enter body: ";
    cin.ignore();
    getline(cin,body);
    
    Reply* newReply = new Reply( current_user -> get_username(), 
                                 subj,body, message_list.size() + 1);
    message_list.push_back(newReply);
    message_list.at(msg_id) -> add_child(newReply);
}
