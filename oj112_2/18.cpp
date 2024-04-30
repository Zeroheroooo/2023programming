#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
public:
  Fraction() : numerator(0), denominator(1) {}

  Fraction(int n, int m) : numerator(n) {
    if(m == 0)
      throw "divided by zero";
    denominator = m;
  }

  int getNumerator() const {return numerator;}

  int getDenominator() const {return denominator;}

  void setNumerator(int n) {numerator = n;}

  void setDenominator(int m) {
    if(m == 0)
      throw "divided by zero";
    denominator = m;
  }
  ///////////////////////////////////////////////////////////////////////////////////////////

  void display(){
      cout << *this;
  }

  friend ostream& operator << (ostream& out, Fraction f) {
    f.irreducible();
    if (f.denominator != 1)
    	out << "(" << f.numerator << "/" << f.denominator << ")";
    else
        out << "(" << f.numerator << ")";
    return out;
  }

  ////////////////////////////////////////////////////////////////////////////////////////////

  void irreducible(){
    int n,maxi=1,i;

    n = (getNumerator() < getDenominator()) ? abs(getNumerator()) : abs(getDenominator());
    for(i=1;i<=n;i++){
      if(getNumerator() % i == 0 && getDenominator() % i == 0)
        maxi = i;
    }
    setNumerator(getNumerator() / maxi);
    setDenominator(getDenominator() / maxi);
    if(getNumerator() == 0) setDenominator(1);
  }

  Fraction operator+(Fraction f2){
    Fraction f3;
    f3.setNumerator(getNumerator() * f2.getDenominator() + f2.getNumerator() * getDenominator());
    f3.setDenominator(getDenominator() * f2.getDenominator());
    return f3;
  }

  Fraction operator-(Fraction f2){
    Fraction f3;
    f3.setNumerator((getNumerator() * f2.getDenominator()) - (f2.getNumerator() * getDenominator()));
    f3.setDenominator(getDenominator() * f2.getDenominator());
    //cout << "***" << getNumerator() << " " << getDenominator() << " " << f2.getNumerator() << " " <<  f2.getDenominator() << endl;
    return f3;
  }

  Fraction operator*(Fraction f2){
    Fraction f3;
    f3.setNumerator(getNumerator() * f2.getNumerator());
    f3.setDenominator(getDenominator() * f2.getDenominator());
    return f3;
  }

  Fraction operator/(Fraction f2){
    Fraction f3;
    f3.setNumerator(getNumerator() * f2.getDenominator());
    f3.setDenominator(getDenominator() * f2.getNumerator());
    return f3;
  }

  Fraction operator=(Fraction f2){
    setNumerator(f2.getNumerator());
    setDenominator(f2.getDenominator());
    return *this;
  }

private:
  int numerator, denominator;
};

int main()
{
  int n1, n2, m1, m2;
  cin >> n1 >> m1 >> n2 >> m2;
  Fraction f1(n1, m1), f2(n2, m2);
  cout << (f1 + f2) << endl;
  cout << (f1 - f2) << endl;
  f1.display();
  //cout << (f1 == f2) << endl;
}

