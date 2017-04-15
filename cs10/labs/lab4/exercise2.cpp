#include <iostream>
using namespace std;

int main()
{
    int one, two, sum, i;
    one =2;
    two =1;
    
    cout << "Input two intergers\n";
    while(one>=two)
    {
    cout << "first: ";
    cin >> one;
    cout << "second: ";
    cin >> two;
    if(one>=two)
    {cout << "re-enter intergers so that first interger"
          << " is greater than the second\n";}
    if (one<two)
    {cout << one << " < " << two << endl;}
    }
    sum=0;
    for (i=one;i<=two;i++)
    {sum = sum + i;}
    cout << "The sum of all inters from " << one << " to " << two
         << " is " << sum << endl;
    return 0;
}
