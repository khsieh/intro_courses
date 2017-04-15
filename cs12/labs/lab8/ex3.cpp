#include <iostream>
#include <vector>

using namespace std;

vector <string> generate_subset(string set)
{
    
}

vector <string> append_to_start(const vector<string>& v, const string & c, vector<string>& v2)
{
    /*
    vector <string> newV;
    for(unsigned i = 0; i < v.size(); ++i)
        newV[i] = c + v[i];
    */
    if(v.size() == 1)
    {
        v2.push_back( c + v.at(0) );
    }
    else
    {
        return append_to_start(v, c, v2);
    }
}

void merge(vector <string>& A, const vector <string>& B)
{
    //A.push_back()
}

int main()
{
    //exercise 3
    cout << "===========Ex.3 =============" << endl;
    vector <string> subset;
    string set = "bc";
    //subset = generate_subset(set);
    subset = append_to_start(subset,"a");
    for(unsigned i = 0; i < subset.size(); ++i)
    {
        cout << subset[i];
    }
    return 0;
}
