#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int change;
    double purchase, received;
    cout << "Purchase amount: ";
    cin >> purchase;
    cout << "Enter amount recieved: ";
    cin >> received;
    cout << "\n Total Change: $" << received - purchase << endl;
    
    change = static_cast<int> ((received - purchase)*100 + 0.5);
     
    int dollar, quarter, dimes, nickels, pennies;
    dollar = change / 100;
    change = change % 100; 
    quarter = change / 25;
    change = change % 25;
    dimes = change / 10;
    change = change % 10;
    nickels = change / 5;
    change = change % 5;
    pennies = change / 1;
    
    cout << "dollars " << dollar << endl
         << "quarters " << quarter << endl
         << "dimes " << dimes << endl
         << "nickels " << nickels << endl 
         << "pennies " << pennies << endl << endl;
         
    return 0;
}
