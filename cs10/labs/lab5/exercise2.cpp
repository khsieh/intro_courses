#include <iostream>

using namespace std;

int main ()
{
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    int score = 0;
//    int sentinel = -1;
    
    while(cin >> score && score <= 100 && score >=0) // score != sential
    {
        if (score <= 100 && score >=90) A++;
        if (score <= 89 && score >= 80) B++;
        if (score <= 79 && score >= 70) C++;
        if (score <= 69 && score >= 60) D++;
        if (score <= 59 && score >= 0) F++;
    }
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
    cout << "D: " << D << endl;
    cout << "F: " << F << endl;
    return 0;
}
