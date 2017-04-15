//Student Employee implementation file

#include "StudentEmpl.h"

#include <iostream>
#include <iomanip>

using namespace std;

StudentEmpl::StudentEmpl()
:Employee(),hourly_rate(0),num_hours(0)
{}

StudentEmpl::StudentEmpl( const string &name,
                          const string &addr,
                          const string &email,
                          const string &eid,
                          double hourly_rate,
                          double num_hours)
    :Employee(name,addr,email,eid),
     hourly_rate(hourly_rate),
     num_hours(num_hours)
{}

double StudentEmpl::get_hourly_rate() const
{
    return hourly_rate;
}

double StudentEmpl::get_num_hours() const
{
    return num_hours;
}

void StudentEmpl::set_hourly_rate(double hourly_rate)
{
    this -> hourly_rate = hourly_rate;
}

void StudentEmpl::set_num_hours(double num_hours)
{
    this -> num_hours = num_hours;
}

void StudentEmpl::display()
{
    Employee::display();
    cout << setprecision(2) << "Hourly Rate: $" << hourly_rate << endl
         << setprecision(0) << "Hours/Week:  " << num_hours << endl;
}

double StudentEmpl::paycheck_amt() const
{
    return num_hours * hourly_rate;
}
