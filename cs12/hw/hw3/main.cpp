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
#include <cstdlib>
#include <vector>
#include "bboard.h"
#include "user.h"
#include "message.h"

using namespace std;

int main()
{
    //set my Bboard title and construct the Bboard with the title;
    string user_bb_title = "Kevin's Bulletin board";
    Bboard Bulletin(user_bb_title);
    
    //implement the setup() function to set up user_list
    Bulletin.setup();
    
    //implement login() function to let user login to the Bboard
    cout << "\033c";
    Bulletin.login();
    
    //implement run() funcition to let user access the Bboard
    Bulletin.run();
    
        
    return 0;
}
