#include <iostream>
#include <vector>

using namespace std;

void asciiTable(vector<char> ascii)
{
    int tablemax = ascii.size();
    for(int i = 0; i < tablemax; i++)
    {
        cout << ascii.at(i) << " ";
        if(i == 9 || i == 19 || i == 29 || i == 39 || i == 49 || i == 59 ||
           i == 69 || i == 79 || i == 89)
           cout << endl;
    }
}


int main()
{
    char temp = '!';
    vector<char> ascii(90);
    int tablemax = ascii.size();
    
    for(int i = 0; i < tablemax; i++)
    {
    ascii.at(i) = temp;
    temp++;
    }
    
    asciiTable(ascii);
    
    return 0;
}
