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
