#include <iostream>
#include <string>
using namespace std;

class Digit{ // class Digit represent a digit in base 10
  int digit;
public:
  void setDigit(int d) { digit = d % 10;}
  int getDigit() const {return digit;}
};



class Integer { //class Integer represent a poistive integer
  Digit value[1000];
public:
    int vlen;
    Integer(string n){
        int len = n.length();
        if(!isdigit(n[0]))
            for(int j=0;j<1000;j++) value[j].setDigit(0);
        else{
            int j=0;
            while(isdigit(n[j])){
                value[j].setDigit(n[j]-'0');
                j++;
            }
            len = j;
        }
        vlen = len;
    }

    void displayInBase(int base) const {
        char symbol[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        int d1=0,i=0,length=vlen,rlen=0,r=0;
        string tmpr="";//dividend,divisor,quotient,remainder;

        do{
            while(d1 < base && length > 0){
                d1 = d1*10 + value[i++].getDigit();
                length--;
            }
            value[r++] = d1 % base;
            tmpr = symbol[d1 % base] + tmpr;
            d1 /= base;
        }while(length > 0);

        while(d1 != 0){
            tmpr = symbol[d1 % base] + tmpr;
            d1 /= base;
        }
        cout << tmpr;
  }

};

int main(){
    string in;
    int j;
    cin >> in;
    Integer i(in);
    for(j = 2;j <= 16;j ++){
        i.displayInBase(j);
        cout << endl;
    }
    return 0;
}
