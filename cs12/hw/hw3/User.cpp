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
#include <string>
#include <vector>
#include "user.h"

using namespace std;

User::User()
:username(), password()
{
}

User::User(const string& uname, const string& pass)
:username(uname), password(pass)
{
}

string User::get_username() const
{
    return username;
}

/*
 * returns true if the stored username/password matches with the parameters.
 * Otherwise returns false.
 * Note that, even though a User with empty name and password is actually a valid User object
 * (it is the default User), this function must still return false if given a empty uname string.
 */
bool User::check(const string& uname, const string& pass) const
{
    if(uname == username && pass == pass)
        return true;
    else if(uname == "" || pass == "")
        return false;
    else
        return false;
}

//Not use now.
void User::set_password(const string& newpass)
{
    password = newpass;
}
