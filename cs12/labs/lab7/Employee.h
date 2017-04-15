#ifndef __EMPLOYEE_H_
#define __EMPLOYEE_H_

#include <string>

using namespace std;

class Employee
{
 private:
  string name;
  string addr;
  string email;
  string eid;

 public:
  Employee();
  Employee( const string &, const string &, const string &, const string & );
  //virtual ~Employee(); //will explain Thursday
  const string & get_name( ) const;
  const string & get_addr( ) const;
  const string & get_email( ) const;
  const string & get_eid( ) const;
  void set_name( const string & );
  void set_addr( const string & );
  void set_email( const string & );
  void display( ) const;
  //virtual double paycheck_amt( ) const = 0; //will explain Thursday
};

#endif //__EMPLOYEE_H_
