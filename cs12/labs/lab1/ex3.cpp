#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int search(vector<int>& v, int findNum)
{
    for(int pos = 0; pos < v.size(); ++pos)
    {
        if(v.at(pos) == findNum )
        {
            return pos;
        }
    }
    
    return -1;
}

void remove(vector<int>& v, int findNum)
{
    int foundIndex = search(v,findNum);
        
    if(foundIndex != -1)
    {
        for(unsigned int i = foundIndex; i < v.size() - 1; ++i)
        {
            v.at(i) = v.at(i + 1);
        }
        
        v.pop_back();
    }
    
}

int main()
{
    srand(time(NULL));
    vector<int> v(20);
    int findNum;
    
    for(int i = 0; i < 20; ++i)
    {
        v.at(i) = rand() % (100 + 1);
    }
    
    for(unsigned x = 0; x < v.size(); ++x)
    {
        cout << v.at(x) << endl;
    }
    
    cout << "Enter the number you wish to find: " << endl;
    cin >> findNum;
    
    
    if(search(v,findNum) != -1)
    {
        while(search(v,findNum) != -1) remove(v,findNum);
        cout << "The requested value "
             << findNum
             << " was found and removed." << endl;
    }
    else
    {
        cout << "The requested value "
             << findNum
             << " was not found." << endl;
    }
    
    cout << "modified vector: " << endl;
    
    for(unsigned x = 0; x < v.size(); ++x)
    {
        cout << v.at(x) << endl;
    }
    
    return 0;
}
