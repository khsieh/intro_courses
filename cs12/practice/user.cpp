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
#include "user.h"
#include <iostream>

using namespace std;

/* ------------------------     constructors       ------------------------ */
User::User()
:username(""), password("") {
}

User::User(const string& uname, const string& pass)
:username(uname), password(pass) {
}

/* -------------------  public member functions    ------------------- */
    //returns the username
string User::get_username() const {
    return username;
}

    //returns true if the stored username/password matches with the parameters
bool User::check(const string& uname, const string& pass) const {
    return ( username == uname && password == pass );
}

    // sets a new password
void User::set_password(const string& newpass) {
    password = newpass;
}


