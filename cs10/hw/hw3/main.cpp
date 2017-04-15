//course : CS10 <fall,12>
//
//First name: Kevin
//Last name: Hsieh
//Course username: khsie003
//email address: khsie003@ucr.edu
//
//Lecture section: 001
// Lab section: 021
//TA: Zhe Wu
//
//Assignment: assignment 1
//
//I hereby certify that the code in this file
//is ENTIRELY my own original work
//
//===========================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int ISBN, ISBN1, ISBN2, ISBN3, ISBN4, ISBN5, ISBN6, ISBN7, ISBN8, ISBN9;
    int weightedsum;
    
    cin >> ISBN;
    
    ISBN1 = ISBN / 100000000 * 1;
    
    ISBN = ISBN % 100000000;
    ISBN2 = ISBN / 10000000 * 2;
    
    ISBN = ISBN % 10000000;
    ISBN3 = ISBN / 1000000 * 3;
    
    ISBN = ISBN % 1000000;
    ISBN4 = ISBN / 100000 * 4;
    
    ISBN = ISBN % 100000;
    ISBN5 = ISBN /10000 * 5;
    
    ISBN = ISBN % 10000;
    ISBN6 = ISBN / 1000 * 6;
    
    ISBN = ISBN % 1000;
    ISBN7 = ISBN / 100 * 7;
    
    ISBN = ISBN % 100;
    ISBN8 = ISBN / 10 * 8;
    
    ISBN = ISBN % 10;
    ISBN9 = ISBN / 1 * 9;
    
    weightedsum =ISBN1 + ISBN2 + ISBN3 + ISBN4+ ISBN5 + ISBN6 + ISBN7 + 
    ISBN8 + ISBN9;
    cout << weightedsum%11 << endl;
    
    return 0;
}
