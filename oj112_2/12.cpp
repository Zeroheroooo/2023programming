class Digit { // class Digit represent a digit in base 10
  int digit;
public:
  Digit(int d) : digit(d % 10) {}
  void setDigit(int d) { digit = d % 10; }
  int getDigit() const {return digit;}
};
class Integer { //class Integer represent a integer
  Digit value[1000];
  bool sign;
public:
  //construct an integer in base 10 using a string.
  //This constructor will convert the given string to integer if possible.
  //Otherwise it will convert the digit part in prefix of the given string.
  Integer(string n);
  //default constructor will construct an Integer object with value 0.
  Integer();
  //function addition will add up two integer and return a new Integer object as result.
  Integer addition(const Integer &b) const;
  //function subtraction will minus b from current object and return a new as result.
  Integer subtraction(const Integer &b) const;
}

All you have to do is complete the member function and we will test your code with the main function as below.

int main()
{
  string a, b;
  cin >> a >> b;
  Integer num1(a), num2(b);
  num1.addition(num2).display();
  cout << endl;
  num2.addition(num1).display();
  cout << endl;
  num1.subtraction(num2).display();
  cout << endl;
  num2.subtraction(num1).display();
  cout << endl;
}
