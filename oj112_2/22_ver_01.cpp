#include <iostream>
#include <string>
#include <cmath>//abs
using namespace std;

class Date{
public:
    string date;
    int days = 0;

    Date(){date = "1900/01/01";}

    Date(string &ymd):date(ymd){

        string y=date.substr(0,4),m=date.substr(5,2),d=date.substr(8,2);
        //day
        days += stoi(d);

        //month
        int symbol[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int i=1;
        while(i < stoi(m))
            days += symbol[i++];

        //year
        int count = 0;
        for(i=1900;i<stoi(y);i++)
            if( (!(i%4) && i%100 ) || !(i%400))
                count++;
        if(stoi(m) > 2 && (!(stoi(y)%4) && stoi(y)%100 || !(stoi(y)%400))) count++;
        days += (stoi(y) - 1900)*365 + count;
    }

    string toString() const{return date;}

    int operator-(const Date &d2) const{return abs(days - d2.days);}
};

int main(){
    string buf;

    getline(cin,buf);
    Date d1(buf);
    cout << buf << endl;

    getline(cin,buf);
    Date d2(buf);
    cout << buf << endl;

    cout << (d1-d2) << endl;
}