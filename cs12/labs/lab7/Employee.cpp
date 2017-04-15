#include "Employee.h"
#include <iostream>

using namespace std;


Employee::Employee()
:name("default name"), addr("000 deafult addr"), email("deafult@ucr.edu"), eid("000000000")
{ }

Employee::Employee( const string &name, 
                    const string &addr,
                    const string &email,
                    const string &eid )
  : name(name), addr(addr), email(email), eid(eid)
{ }

//Employee::~Employee() { } //will discuss in Thu lecture

const string & Employee::get_name( ) const
{
  return name;
}

const string & Employee::get_addr( ) const
{
  return addr;
}

const string & Employee::get_email( ) const
{
  return email;
}

const string & Employee::get_eid( ) const
{
  return eid;
}

void Employee::set_name( const string &name )
{
  this->name = name;
}

void Employee::set_addr( const string &addr )
{
  this->addr = addr;
}

void Employee::set_email( const string &email )
{
  this->email = email;
}

void Employee::display( ) const
{
  cout << "Name:        " << name << endl
       << "Address:     " << addr << endl
       << "Email:       " << email << endl
       << "Employee ID: " << eid << endl;
}
