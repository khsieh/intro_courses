#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

#include "Employee.h"
#include "Lecturer.h"
#include "StudentEmpl.h"


using namespace std;


vector<Lecturer> readin()
{
    vector <Lecturer> leclist;
    ifstream fin("lecturers.txt");
    
    string first_name, last_name, addr_num, addr_name, addr_type, email, eid;
    double load, rate;
    
    while(fin >> first_name >> last_name
              >> addr_num >> addr_name >> addr_type
              >> email >> eid >> load >> rate)
    {
        string temp_name = "";
        string temp_addr = "";
        temp_name += first_name;
        temp_name += " ";
        temp_name += last_name;
        temp_addr += addr_num;
        temp_addr += " ";
        temp_addr += addr_name;
        temp_addr += " "; 
        temp_addr += addr_type;
        
        leclist.push_back(Lecturer(temp_name,temp_addr,email,eid,load,rate));
    }
    
    fin.close();
    
    return leclist;
}

int main()
{
    /*
    Lecturer l1 = Lecturer("Jane Doe",
                           "123 Silver Lane",
                           "jdoe001@ucr.edu",
                           "111111111",
                           5025.0,
                           66.67);
    * Jane Doe 123 Silver Lane jdoe001@ucr.edu 111111111 5025.0 66.67
    */
    
//Declare one more lecturer and 2 student employees here
    /*
    Lecturer l2 = Lecturer("Jimmy Lin",
                           "244 Golden Drive",
                           "jlin024@ucr.edu",
                           "123456789",
                           4158.0,
                           70.50);
    */
    
    
    StudentEmpl se1 = StudentEmpl("Chieh Li",
                                   "157 somewhere Ave",
                                   "cli004@ucr.edu",
                                   "444555666",
                                   12.50,
                                   18);

    StudentEmpl se2 = StudentEmpl("Kevin Hsieh",
                                   "222 not here",
                                   "khsie003@ucr.edu",
                                   "987654321",
                                   10.25,
                                   12);
    //=================================//
    vector <Lecturer> leclist = readin();
    //=================================//
//Employees information before the raise
    cout << "\033c";
    cout << endl;
    for(unsigned int i = 0; i < leclist.size(); ++i)
    {
        leclist.at(i).display();
        cout << endl;
    }
    //cout << endl;
    //leclist.at(0).display();
    //cout << endl;
    //leclist.at(1).display();
    //cout << endl;
    se1.display();
    cout << endl;
    se2.display();
    cout << endl;
    cout << "============Raise!!===============" << endl;

//Give a 5% raise to all employees here:
// (increase rate or hourly rate by 10% for each employee)
    for(unsigned int i = 0; i < leclist.size(); ++i)
    {
        leclist.at(i).set_course_rate(leclist.at(i).get_course_rate() *1.05);
    }
    se1.set_hourly_rate(se1.get_hourly_rate() * 1.10);
    se2.set_hourly_rate(se2.get_hourly_rate() * 1.10);

//Display all employees information here:
    cout << endl;
    for(unsigned int i = 0; i < leclist.size(); ++i)
    {
        leclist.at(i).display();
        cout << endl;
    }
    cout << endl;
    se1.display();
    cout << endl;
    se2.display();
    cout << endl;

//Tabulate the total payout this month 
// (the total payout to all 4 employees declared above.
    double total_payout = 0;
    for(unsigned int i = 0; i < leclist.size(); ++i)
    {
        total_payout = leclist.at(i).paycheck_amt();
    }
    total_payout += se1.paycheck_amt();
    total_payout += se2.paycheck_amt();


//Ouput the total payout this month 
    cout << fixed << setprecision(2);
    cout << endl
    << "Total payout to employees this month: $"
    << total_payout 
    << endl << endl;
        
    return 0;
}
