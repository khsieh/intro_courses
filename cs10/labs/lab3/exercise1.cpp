#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    double magnitude, energy;
    
    cout << "Enter Richter scale magnitude: ";
    cin >> magnitude;
    cout << "The energy that is release in a " << magnitude
         << " magnitude earthquake is "
         << pow (10,(1.5*magnitude - 4.6));
    cout << " GigaJoules.\n\n";
    
    cout << "Enter Energy in GigaJoules: ";
    cin >> energy;
    cout << "Earthquake that releases " << energy << " GigaJoules of energy"
         << " have a "
         << (log10(energy) + 4.6)/1.5
         << " magnitude on the Ritcher scale.\n";
    
    return 0;
}
