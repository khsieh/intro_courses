#include <iostream>
#include <string>
#include <cmath>
#include "rational.h"

using namespace std;

/**Constructors
 * by user input
 * by default
 */ 
Rational::Rational(int n, int d)
{
    numerator = n;
    denominator = d;
}

Rational::Rational()
{
    numerator = 1;
    denominator = 1;
}

/**math function add
 * add Rational r to r2
 */ 
Rational Rational::add(const Rational& r2) const
{
    Rational answer;
    answer.numerator = (r2.numerator * denominator) + (r2.denominator * numerator);
    answer.denominator = (r2.denominator * denominator);
    
    return answer;
}

/**math function subtract
 * subtract Rational r to r2
 */ 
Rational Rational::subtract(const Rational& r2) const
{
    Rational answer;
    answer.numerator = ((r2.denominator * numerator) - (r2.numerator * denominator));
    answer.denominator = denominator * r2.denominator;
    
    return answer;
}

/**math function multiply
 * multiply Rational r and r2
 */ 
Rational Rational::multiply(const Rational& r2) const
{
    Rational answer;
    answer.numerator = r2.numerator * numerator;
    answer.denominator = r2.denominator * denominator;
    
    return answer;
}

/**math function divide
 * divide Rational r to r2
 */ 
Rational Rational::divide(const Rational& r2) const
{
    Rational answer;
    answer.numerator =  r2.denominator * numerator;
    answer.denominator = r2.numerator * denominator;
    
    return answer;
}

/**display function
 * print the Rational in the form of a/b
 */ 
void Rational::display() const
{
    cout << numerator << " / " << denominator << endl;
}
