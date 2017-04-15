// Course: CS 12 <winter,13>
//
// First Name: Kevin
// Last Name:  Hsieh
// Login id: khsie003
// email address: khsie003@ucr.edu
//
// Lecture Section: 001
// Lab Section: 023
// TA:
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

/**Constructor Functions*/
//Default to 1/1/2000 or January, 1, 2000
Date::Date()
:day(1), month(1), month_name("January"), year(2000)
{
}

//Construct by user input with numeric values
Date::Date(unsigned m, unsigned d, unsigned y)
:day(d), month(m), year(y)
{
}

//Construct by user input with alpa month and numeric day and year
Date::Date(const string& mn, unsigned d, unsigned y)
:day(d), month_name(mn), year(y)
{
}

/**Print Functions*/
//Print Date in numeric values mm/dd/yy
void Date::print_numeric() const
{
    
    if(is_all_valid())
        cout << print_month()
             << " "  << print_day()
             << ", " << print_year();
    else if(!is_valid_day(day))
        cout << "Invalid Day: the Date was set to 1/1/2000";
    else if(!is_valid_year(year))
        cout << "Invalid Year: the Date was set to 1/1/2000";
    else if(!is_valid_month(number(month_name)) || !is_valid_month(month) )
        cout << "Invalid Month: the Date was set to 1/1/2000";
    else    
        cout << "Invalid Date: the Date was set to 1/1/2000";

}

//Print Date in numeric values excpet for month, print in alpha
void Date::print_alpha() const
{    
    if(is_all_valid() )
        cout << "\t" << print_month_name()
             << " "  << print_day() 
             << ", " << print_year() << endl;
    else if(!is_valid_day(day))
        cout << "\tInvalid Day: the Date was set to 1/1/2000";
    else if(!is_valid_month_name(name(month)) || !is_valid_month_name(month_name))
        cout << "\tInvalid Month name: the Date was set to 1/1/2000";
    else if(!is_valid_year(year))
        cout << "\tInvalid Year: the Date was set to 1/1/2000";
    else
        cout << "\tInvalid Date: the Date was set to 1/1/2000";
}


/**Private Helper Functions*/
//check and return true if it is leap year, false otherwise
bool Date::is_leap(unsigned) const
{
    if( year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) )
        return true;
    else
        return false;
}

//check for the avliable days in a month, return the avliable days
unsigned Date::days_per_month(unsigned m, unsigned y ) const
{
    switch(m)
    {
        case 1:
            return 31;
        case 2:
            if(is_leap(y))
                return 29;
            else
                return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return 1;
        }
}

//returns the name of the month with the respective number given
string Date::name(unsigned m) const
{
    switch(m)
    {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "January";
    }
}

//returns the number of the month with the respective name given
unsigned Date::number(const string& mn) const
{
    if(mn == "January" || mn == "january")
        return 1;
    else if(mn == "February" || mn == "february")
        return 2;
    else if(mn == "March" || mn == "march")
        return 3;
    else if(mn == "April" || mn == "april")
         return 4;
    else if(mn == "May" || mn == "may")
        return 5;
    else if(mn == "June" || mn == "june")
        return 6;
    else if(mn == "July" || mn == "july")
        return 7;
    else if(mn == "August" || mn == "august")
        return 8;
    else if(mn == "September" || mn == "september")
        return 9;
    else if(mn == "October" || mn == "october")
        return 10;
    else if(mn == "November" || mn == "november")
        return 11;
    else if(mn == "December" || mn == "december")
        return 12;
    else
        return 1;
}

/**print individual parts of date**/
//print month in numeric
unsigned Date::print_month()const
{
    if(is_valid_month(month) ) // || is_valid_month(number(month_name)) )
        return this -> month;
    else
        return this -> number(this -> month_name);
}
//print month in alpha
string Date::print_month_name()const
{
    if(is_valid_month_name(month_name) ) //|| is_valid_month_name(name(month)) )
        return this -> month_name;
    else
        return this -> name(this -> month);
}
//print day
unsigned Date::print_day()const
{
    if(is_valid_day(this -> day))// || is_valid_day_mn(this -> day))
        return this -> day;
    else
        return 1;
}
//print year
unsigned Date::print_year()const
{
    if(is_valid_year(year))
        return this -> year;
    else
        return 1;
}


//check if input mothn is a valid month
bool Date::is_valid_month_name(const string& mn) const
{
    if(mn == "January" || mn == "january")
        return true;
    else if(mn == "February" || mn == "february")
        return true;
    else if(mn == "March" || mn == "march")
        return true;
    else if(mn == "April" || mn == "april")
         return true;
    else if(mn == "May" || mn == "may")
        return true;
    else if(mn == "June" || mn == "june")
        return true;
    else if(mn == "July" || mn == "july")
        return true;
    else if(mn == "August" || mn == "august")
        return true;
    else if(mn == "September" || mn == "september")
        return true;
    else if(mn == "October" || mn == "october")
        return true;
    else if(mn == "November" || mn == "november")
        return true;
    else if(mn == "December" || mn == "december")
        return true;
    else
        return false;
}

bool Date::is_valid_month(unsigned m) const
{
    if(m >= 1 && m <= 12)
        return true;
    else
        return false;
}

//check if input day is valid
bool Date::is_valid_day(unsigned d) const
{
    if(month >=1 && month <=12)
    {
        if(d >= 1 && d <= days_per_month(month, year) )
            return true;
    }
    else if(month_name != "")
    {
        if(d >= 1 && d <= days_per_month(number(month_name),year) )
            return true;
    }
    
    else
    {
        return false;
    }
        
    return false;
}

//check if input year is valid
bool Date::is_valid_year(unsigned y) const
{
    if(y > 0)
        return true;
    else
        return false;
}

//check if all three parts of date is valid
bool Date:: is_all_valid() const
{
    if( is_valid_day(this -> day) && 
        is_valid_year(year) &&
      ( is_valid_month(this-> month) || is_valid_month_name(this-> month_name))
      )
        return true;
    else
        return false;
}
