#include <iostream>
#include <vector>

using namespace std;

int max(vector <int> stuff, int pos)
{
    if(pos == 0) 
        return stuff[0];
    if(stuff[pos] > max(stuff,pos-1) ) 
        return stuff[pos];
    else 
        return max(stuff, pos -1);
}

int organizeMob(int total, int group)
{
    if(group == total)
        return 1;
    if(group == 0)
        return 1;
    else
        return organizeMob(total - 1, group -1) + organizeMob(total -1, group);
}

vector <string> generate_subset(string set)
{
    
}

vector <string> append_to_start(const vector<string>& v, const string & c)
{
    vector <string> newV;
    for(unsigned i = 0; i < v.size(); ++i)
        newV[i] = c + v[i];
}

void merge(vector <string>& A, const vector <string>& B)
{
    //A.push_back()
}

int main()
{
    //exercise 1
    cout << "===========Ex.1 =============" << endl;
    vector <int> stuff;
    
    stuff.push_back(5);
    stuff.push_back(6);
    stuff.push_back(3);
    
    cout << max(stuff,stuff.size()-1);
    //cout << stuff[stuff.size()-1];
    cout << endl;
    
    //exercise 2
    cout << "===========Ex.2 =============" << endl;
    int total = 20, group = 10;
    //cout << "enter the total number of students: ";
    //cin  >> total;
    //cout << "enter how many students in each group: ";
    //cin  >> group;
    cout << organizeMob(total,group) << " of ways to organize the mob" << endl;
    
    //exercise 3
    cout << "===========Ex.3 =============" << endl;
    vector <string> subset;
    string set = "bc";
    subset = generate_subset(set);
    //subset = append_to_start(subset,"a");
    for(unsigned i = 0; i < subset.size(); ++i)
    {
        cout << subset[i];
    }
    return 0;
}
