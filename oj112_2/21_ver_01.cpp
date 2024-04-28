#include <iostream>
#include <string>
using namespace std;

class Time{
public:
    string time;
    long hms = 0;

    Time(){time = "00:00:00";}

    Time(string &hms):time(hms){
        int multi = 36000;
        for(int i=0;i<=7;i++){
            if(i != 2 && i != 5){
                this->hms += (this->time[i]  - '0') * multi;
                if(i % 3) multi /= 6;
                else multi /= 10;
            }
        }
    }

    string toString() const{return time;}

    int operator-(const Time &t2) const{return abs(hms - t2.hms);}
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
