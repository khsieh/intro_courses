#include <iostream>
using namespace std;

int main(){
    double age;
    
    cout << "What is your age? ";
    cin >> age;
    cout << "Your target heart range is bewteen " 
         << (220 - age) * 0.60
         << " and "
         << (220 - age) * 0.70
         << " bpm.";
       
    return 0;
}
