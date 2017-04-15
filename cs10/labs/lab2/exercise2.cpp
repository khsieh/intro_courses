#include <iostream>
using namespace std;

int main(){
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    
    cin >> a >> b >> c >> d >> e >> f;
    cout << "Sum of " << a << " + " << b << " + " << c << " + " << d << " + "
         << e << " + " << f
         << " = " << a + b + c + d + e + f << endl;
         
    cout << "Average = " << (a + b + c + d + e + f) / 6;
    return 0;
}
