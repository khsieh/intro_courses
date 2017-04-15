//lecturer implementation file

#include "Lecturer.h"

#include <iostream>
#include <iomanip>
using namespace std;

//Lecturer::Lecturer( ) : course_rate(0.0), empl_perc(0.0) { }

Lecturer::Lecturer( const string &name,
                    const string &addr,
                    const string &email,
                    const string &eid,
                    double course_rate, 
                    double empl_perc )
  : Employee(name, addr, email, eid), 
    course_rate(course_rate), 
    empl_perc(empl_perc)
{ }

double Lecturer::get_course_rate( ) const
{
  return course_rate;
}

double Lecturer::get_empl_perc( ) const
{
  return empl_perc;
}

void Lecturer::set_course_rate( double course_rate )
{
  this->course_rate = course_rate;
}

void Lecturer::set_empl_perc( double empl_perc )
{
  this->empl_perc = empl_perc;
}

void Lecturer::display( ) const
{
  Employee::display();

  cout << fixed;
  cout << setprecision(2) << "Course Rate: $" << course_rate << endl
       << setprecision(0) << "Employment%: " << empl_perc << "%" << endl;
}

double Lecturer::paycheck_amt( ) const
{
  return course_rate * FULL_LOAD * empl_perc / 100 / 12;
}
