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

#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

using namespace std;

class Message
{
      
    /**private member variables**/
    private:
      string author;
      string subject;
      string body;

    /**public interface functoins**/
    public:
      //default constructor
      Message();

      //Constructor with parameters
      Message(const string& athr, const string& sbjct, const string& body);


      //displays the message in the given format. See output specs.
      void display() const;
};

#endif //MESSAGE_H
