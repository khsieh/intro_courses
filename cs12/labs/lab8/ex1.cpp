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

int main()
{
    //exercise 1
    cout << "===========Ex.1 =============" << endl;
    vector <int> stuff;
    
    stuff.push_back(5);
    stuff.push_back(6);
    stuff.push_back(3);
    
    cout << max(stuff,stuff.size()-1);
    cout << endl;
    
    return 0;
}
