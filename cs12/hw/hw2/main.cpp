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

using namespace std;

class Date
{
    /**all variable declarations*/
    private:
        unsigned day;
        unsigned month;
        string month_name;
        unsigned year;
        
    public:
        /**Construstor */
        Date();
        Date(unsigned m, unsigned d, unsigned y);
        Date(const string& mn, unsigned d, unsigned y);
        
        /**Print functions, print the date in mm/dd/yy */
        void print_numeric()const;
        void print_alpha()const;
        
    /**Private member functions */
    private:
    //assigned helper functions
        //check if it is a leap year
        bool is_leap(unsigned) const;
        //check for the days of a month
        unsigned days_per_month( unsigned m, unsigned y ) const;
        //convert name of a month from numeric to alpha
        string name(unsigned m) const;
        //convert name of an alpha from numeric to numeric
        unsigned number(const string& mn)const;
        
    //my helper functions
        //print individual part of date
        unsigned print_month()const;
        string print_month_name()const;
        unsigned print_day()const;
        unsigned print_year()const;        
        //check for validation of individual part of date
        bool is_valid_month_name(const string& mn) const;
        bool is_valid_month(unsigned m) const;
        bool is_valid_day(unsigned d) const;
        //bool is_valid_day_mn(unsigned d) const;
        bool is_valid_year(unsigned y) const;
        //check if all part of date is valid
        bool is_all_valid() const;
};


/**Test harness functions*/
//test default c'tor
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
//test date(unsigned,unsigned,unsigned) c'tor 
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
//test date(string,unsigned,unsigned) c'tor
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
//test correct leap year date
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
//test invalid num month
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
//test invalid alpha month
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
//test invalid day
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
//test invalid year
void test8()
{
	cout << "8. Invalid Numeric year: October 31, 0" << endl;
	Date x = Date(10,31, 0);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}
//test both invalid num month and day
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
//test both invalid alpha month and day
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
//test not leap year with num month
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
//test not leap year with alpha month
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

/**Test harness*/
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
    
    return 0;
}

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
