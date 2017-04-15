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


    //inclusion guard
#ifndef _USER_H_
#define _USER_H_

    //includes
#include <string>

using namespace std;

class User {
private:
        //private member variables
    string username;
    string password;
public:
        //constructors
    User(); //default constructors
    User(const string& uname, const string& pass);
    
        //public member functions
    string get_username() const;
    bool check(const string& uname, const string& pass) const;
    void set_password(const string& newpass);
};

#endif //_USER_CLASS_


