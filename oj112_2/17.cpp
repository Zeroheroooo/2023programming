#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class Fraction {

public:
  Fraction() : numerator(0), denominator(1) {}

  Fraction(int n, int m) : numerator(n) {
    if(m == 0)
      throw "divided by zero";
    denominator = m;
  }

  int getNumerator() const {
    return numerator;
  }

  int getDenominator() const {
    return denominator;
  }

  void setNumerator(int n) {
    numerator = n;
  }

  void setDenominator(int m) {
    if(m == 0)
      throw "divided by zero";
    denominator = m;
  }

  friend std::ostream& operator << (std::ostream& out, const Fraction &f) {
    if (f.denominator != 1)
    	out << "[" << f.numerator << "/" << f.denominator << "]";
    else
        out << f.numerator;
    return out;
  }

private:
  int numerator, denominator;
};

Fraction irreducible(Fraction f){
    int n,maxi=1,i,tmp=1;

    n = (abs(f.getNumerator()) < abs(f.getDenominator())) ? abs(f.getNumerator()) : abs(f.getDenominator());
    for(i=1;i<=n;i++){
        if(f.getNumerator() % i == 0 && f.getDenominator() % i == 0)
            maxi = i;
    }
    f.setNumerator(f.getNumerator() / maxi);
    f.setDenominator(f.getDenominator() / maxi);
    return f;
}

bool operator==(Fraction f1, Fraction f2){
    f1 = irreducible(f1);
    f2 = irreducible(f2);

    if(f1.getNumerator() == f2.getNumerator() && f1.getDenominator() == f2.getDenominator())
        return 1;
    return 0;
}

Fraction operator+(Fraction f1, Fraction f2){
    Fraction f3;
    f3.setNumerator(f1.getNumerator() * f2.getDenominator() + f2.getNumerator() * f1.getDenominator());
    f3.setDenominator(f1.getDenominator() * f2.getDenominator());
    f3 = irreducible(f3);

    if(f3.getNumerator() == 0) f3.setDenominator(1);

    return f3;
}

Fraction operator-(Fraction f1, Fraction f2){
    Fraction f3;
    f3.setNumerator((f1.getNumerator() * f2.getDenominator()) - (f2.getNumerator() * f1.getDenominator()));
    f3.setDenominator(f1.getDenominator() * f2.getDenominator());
    f3 = irreducible(f3);
    if(f3.getNumerator() == 0) f3.setDenominator(1);

    return f3;
}

int main()
{
  int n1, n2, m1, m2;
  cin >> n1 >> m1 >> n2 >> m2;
  Fraction f1(n1, m1), f2(n2, m2);
  cout << (f1 + f2) << endl;
  cout << (f1 - f2) << endl;
  cout << (f1 == f2) << endl;
}
