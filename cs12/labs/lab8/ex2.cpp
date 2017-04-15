#include <iostream>
#include <vector>

using namespace std;

int organizeMob(int total, int group)
{
    if(group == total)
        return 1;
    if(group == 0)
        return 1;
    else
        return organizeMob(total - 1, group -1) + organizeMob(total -1, group);
}

int main()
{
    
    //exercise 2
    cout << "===========Ex.2 =============" << endl;
    int total = 0, group = 0;
    cout << "enter the total number of students: ";
    cin  >> total;
    cout << "enter how many students in each group: ";
    cin  >> group;
    cout << organizeMob(total,group) << " of ways to organize the mob" << endl;
    
    return 0;
}
