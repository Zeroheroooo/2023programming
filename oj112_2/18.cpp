#include <iostream>
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

  void display(){
      if (denominator != 1)
        cout << "(" << numerator << "/" << denominator << ")" << endl;
      else
        cout << numerator << endl;
  }

  friend std::ostream& operator << (std::ostream& out, const Fraction &f) {
    if (f.denominator != 1)
    	out << "(" << f.numerator << "/" << f.denominator << ")";
    else
        out << f.numerator;
    return out;
  }

  Fraction operator! ()
  {
      return Fraction(denominator, numerator);
  }

private:
  int numerator, denominator;
};

Fraction irreducible(Fraction f){
    int n,maxi=1,i,tmp=1;

    if(f.getNumerator() < 0){
        f.setNumerator(f.getNumerator() * -1);
        tmp *= -1;
    }
    if(f.getDenominator() < 0){
        f.setDenominator(f.getDenominator() * -1);
        tmp *= -1;
    }

    n = (f.getNumerator() < f.getDenominator()) ? f.getNumerator() : f.getDenominator();
    for(i=1;i<=n;i++){
        if(f.getNumerator() % i == 0 && f.getDenominator() % i == 0)
            maxi = i;
    }
    f.setNumerator(f.getNumerator() / maxi * tmp);
    f.setDenominator(f.getDenominator() / maxi);
    if(f.getNumerator() == 0) f.setDenominator(1);
    return f;
}

Fraction operator+(Fraction f1, Fraction f2){
    Fraction f3;
    f3.setNumerator(f1.getNumerator() * f2.getDenominator() + f2.getNumerator() * f1.getDenominator());
    f3.setDenominator(f1.getDenominator() * f2.getDenominator());
    f3 = irreducible(f3);
    return f3;
}

Fraction operator-(Fraction f1, Fraction f2){
    Fraction f3;
    f3.setNumerator((f1.getNumerator() * f2.getDenominator()) - (f2.getNumerator() * f1.getDenominator()));
    f3.setDenominator(f1.getDenominator() * f2.getDenominator());
    f3 = irreducible(f3);
    return f3;
}

Fraction operator*(Fraction f1, Fraction f2){
    Fraction f3;
    f3.setNumerator(f1.getNumerator() * f2.getNumerator());
    f3.setDenominator(f1.getDenominator() * f2.getDenominator());
    f3 = irreducible(f3);
    return f3;
}

Fraction operator/(Fraction f1, Fraction f2){
    Fraction f3;
    f3.setNumerator(f1.getNumerator() * f2.getDenominator());
    f3.setDenominator(f1.getDenominator() * f2.getNumerator());
    f3 = irreducible(f3);
    return f3;
}

int main()
{
  int n1, n2, m1, m2;
  cin >> n1 >> m1 >> n2 >> m2;
  Fraction f1(n1, m1), f2(n2, m2);
  cout << (f1 + f2) << endl;
  cout << (f1 - f2) << endl;
  //cout << (f1 == f2) << endl;
}

