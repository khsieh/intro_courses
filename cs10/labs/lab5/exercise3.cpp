#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    int r = 0;
    int a = 1;
    int b = 100;
    string answer;
    string x;
    
    do
    {
        cout << "do you wish to flip a coin?\n";
        cin >> answer;
        r = a + rand() % (b - a +1);
        if(answer != "no")
        { 
            if (r >=1 && r <= 50) x = "head";
            if (r >=51 && r <= 100) x= "tail";
            cout << x << endl << endl;
        }
        
     }

    while(answer != "no");
    
    return 0;
}
