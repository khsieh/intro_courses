#include <iostream>

using namespace std;

bool is_leap(int year)
{
    if(year % 4 == 0)
        {
            if(year % 100 == 0)
            {
                if(year % 400 ==0){ return true;}
                else{ return false;}
            }
            
            else
                return true;
        }
        
    else
        return false;
}

unsigned days_per_month(unsigned m, unsigned y )
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

bool is_valid_day(unsigned d, unsigned month, unsigned year)
{
    if(d >= 1 && 
      (d <= days_per_month(month,year)))// ||
       //d<= days_per_month(number(month_name),year)) )
        return true;
    else
        return false;
}

int main()
{
    cout << "\033c"<< is_leap(1900) << endl;
    cout << is_valid_day(29,2,1900) << endl;
    cout << days_per_month(2,1900) << endl;
    return 0;
}

/*
    if( !is_leap(y))
    {
        if(m == 2) return 28;
        else if(m % 2 == 0 && m < 8) return 30;
        else if(m % 2 != 0 && m < 8) return 31;
        else if(m % 2 == 0 && m >= 8) return 31;
        else return 30;
    }
    
    else if( is_leap(y) ) 
    {
        if(m == 2) return 29;
        else if(m % 2 == 0 && m < 8) return 30;
        else if(m % 2 != 0 && m < 8) return 31;
        else if(m % 2 == 0 && m >= 8) return 31;
        else return 30;
    }
    else return 0;
    */
