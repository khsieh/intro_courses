#include <iostream>


using namespace std;

#include "lab6.h"
#include "dayConvert.h"
#include "yearConvert.h"

int main ()
{
    string monthNumber;
    string dayNumber;
    string yearNum;
    string date;
    string s = ",";
    
    //cin >> monthNumber;
    //cout << monthConvert(monthNumber) << endl;
    //input.txt
    
    //cin >> dayNumber;
    //cout << dayNumber << dayConvert(dayNumber) << endl;
    //input2.txt
    
    //cin >> yearNum;
    //cout << yearConvert(yearNum) << endl;
    
    cin >> date;
    monthNumber = date.substr(0,date.find('/'));
    string subdate = date.substr(date.find('/') + 1);
    
    dayNumber = subdate.substr(0,subdate.find('/'));
    
    string subdate2 = subdate.substr(subdate.find('/'));
    yearNum = subdate2.substr(1);
    
    string newDate = monthConvert(monthNumber) + s + dayNumber + dayConvert(dayNumber) + s + yearConvert(yearNum);
    cout << newDate;
    
    return 0;
}
