#include <iostream>
#include <string>
using namespace std;

class Time{
public:
    string time;

    Time(){time = "00:00:00";}

    Time(string &hms):time(hms){}

    string toString() const{return time;}

    int operator-(const Time &t2) const{

        long hms1=0,hms2=0;
        int multi = 36000;
        for(int i=0;i<=7;i++){
            if(i != 2 && i != 5){
                hms1 += (this->time[i]  -'0') * multi;
                hms2 += (t2.time[i]  -'0') * multi;
                if(i % 3) multi /= 6;
                else multi /= 10;
            }
        }

        if(hms1 > hms2) return hms1 - hms2;
        return hms2 - hms1;
    }
};

int main(){
    string buf;

    getline(cin,buf);
    Time t1(buf);
    cout << buf << endl;

    getline(cin,buf);
    Time t2(buf);
    cout << buf << endl;

    cout << (t1-t2) << endl;
}
