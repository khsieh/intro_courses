#ifndef __LECTURER_H__
#define __LECTURER_H__

#include "Employee.h"

const unsigned FULL_LOAD = 9;

class Lecturer : public Employee
{
 private:
  double course_rate;
  double empl_perc;

 public:
  //Lecturer( );
  Lecturer( const string &,
            const string &,
            const string &,
            const string &,
            double, 
            double );

  double get_course_rate( ) const;
  double get_empl_perc( ) const;
  void set_course_rate( double );
  void set_empl_perc( double );
  void display( ) const;
  double paycheck_amt( ) const;
};

#endif //__LECTURER_H__
