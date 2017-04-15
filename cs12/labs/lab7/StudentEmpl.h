#ifndef __STUDENTEMPL_H__
#define __STUDENTEMPL_H__

#include "Employee.h"

class StudentEmpl : public Employee
{
    private:
        double hourly_rate;
        double num_hours;

    public:
        StudentEmpl();
        StudentEmpl( const string &,
                     const string &,
                     const string &,
                     const string &,
                     double, 
                     double );
        double get_hourly_rate() const;
        double get_num_hours() const;
        void set_hourly_rate(double);
        void set_num_hours(double);
        void display();
        double paycheck_amt() const;
};

#endif //__STUDENTEMPL_H__
