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
// Assignment: assn2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ================================================================

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

void test1()
{
	cout << "1. Default" << endl;
	Date x = Date();
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test2()
{
	cout << "2. Numeric Date: 7.3.1991" << endl;
	Date x = Date(7,3,1991);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}    

void test3()
{
	cout << "3. Alpha Date: July 31, 1991" << endl; 
	Date x  =  Date("July",31,1991);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
    cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test4()
{
	cout << "4. February 29th 2012 (leap year): 2/29/2012" << endl;
	Date x = Date(2,29,2012);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test5()
{
	cout << "5. Invalid Numeric Month: 0.3.1991 -> 1.3.1991" << endl;
	Date x = Date(0,3,1991);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test6()
{
	cout << "6. Invalid Aplpha Month: haha 5, 1994" << endl;
	Date x = Date("haha",5,1994);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test7()
{
	cout << "7. Invalid Numeric Day: December 32, 1994" << endl;
	Date x = Date(12,32,1994);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test8()
{
	cout << "8. Invalid Numeric year: October 31, 10000" << endl;
	Date x = Date(10,31, 10000);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test9()
{
	cout << "9. Invalid N_month & day: 13 0, 2250" << endl;
	Date x = Date(13,0,2250);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test10()
{
	cout << "10. Invalid A_month & day: 13th month 0, 2250" << endl;
	Date x = Date("13th month",0,2250);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}



void test11()
{
	cout << "11. Not a Leap Year: 2/29/1900" << endl;
	Date x = Date(2,29,1900);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test12()
{
	cout << "12. Not a Leap Year: Feb 29th 1900" << endl;
	Date x = Date("February",29,1900);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}


int main()
{
    cout << "\033c";
	//test1(); //default
	test2(); //numeric
    test3(); //alpha
    test4(); //wrong numeric month
    cout << "====================================" << endl;
    
    test5(); //wrong alpha month
    test6(); //wrong day
	test7(); //wrong year
    test8(); //wrong numeric month & day
    test9(); //wrong alpha month & day
    test10();//Leap year 2,29 2012
    test11();//Not a Leap year 2,29 1900
    test12();//Not a Leap year Feb,29 1900
    //test13();
    
    return 0;
}
