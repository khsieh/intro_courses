#include <iostream>
#include <string>
#include "rational.h"

using namespace std;

int main()
{
    Rational frac1(3,10), frac2(7,1);
    Rational *rp3 = new Rational(5,3);
    Rational *rp4 = new Rational(6,1);
    
    Rational answer_i, answer_ii, answer_iii, answer_iv;
    
    cout << "\033c";
    cout << "fract1: ";
    frac1.display();
    cout << "frac2: ";
    frac2.display();
    cout << endl;
    
    cout << "(i)  frac1 + frac2" << endl;
    answer_i = frac1.add(frac2);
    answer_i.display();
    cout << "\n(ii) frac2 -rp3" << endl;
    answer_ii = frac2.subtract(*rp3);
    answer_ii.display();
    cout << "\n(iii)rp4 * frac1" << endl;
    answer_iii = frac1.multiply(*rp4);
    answer_iii.display();
    cout << "\n(iv) rp3 / rp4 " << endl;
    answer_iv = rp3->divide(*rp4);
    answer_iv.display();
    return 0;
}
