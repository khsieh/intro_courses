class Rational
{
    private:
        int numerator;
        int denominator;
    public:
        /**constructors*/
        Rational();
        Rational(int n, int d);
        /**math functions*/
        Rational add(const Rational& r2) const;
        Rational subtract(const Rational& r2) const;
        Rational multiply(const Rational& r2) const;
        Rational divide(const Rational& r2) const;
        /**print function*/
        void display() const;
};
