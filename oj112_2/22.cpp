#include <iostream>
#include <string>
using namespace std;

class Date{
public:
    string date;
    int days = 0;

    Date(){date = "1900/01/01";}

    Date(string &ymd):date(ymd){

        int i;
        string y="",m="",d="";
        for(i=0;i<4;i++)//year
                y = y + date[i];
        for(i=5;i<7;i++)//month
                m = m + date[i];
        for(i=8;i<=9;i++)//day
                d = d + date[i];
        //day
        days += stoi(d);

        //month
        int symbol[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        i=1;
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

    int operator-(const Date &d2) const{
        if(days > d2.days) return days - d2.days;
        return d2.days - days;
    }
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