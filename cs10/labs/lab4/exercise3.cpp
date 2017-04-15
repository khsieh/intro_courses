#include <iostream>
using namespace std;

int main()
{
    string word;
    int sum=0;
    while (cin >> word)
    {
        cout << word.size() << endl;
        sum = sum + word.size();
    }
    cout << sum;
    
    
    return 0;
}
