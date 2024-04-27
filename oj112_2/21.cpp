#include <iostream>
#include <string>
using namespace std;

class Time{
public:
    string time;

    Time(){time = "00:00:00";}

    Time(string &hms):time(hms){}

    string toString() const{
        return time;
    }
    int operator-(const Time &t2) const{
        cout << t2.time << endl;
        int flag = -1;
        for(int i=0;i<8;i++){
            if(this->time[i] >t2.time[i]){flag = 1; break;}
            if(this->time[i] <t2.time[i]){flag = 2; break;}
        }

        int multi=360000,counts=0;
        switch(flag){
            case 1:
                for(int i=0;i<=7;i++){
                    if(i != 2 || i != 5){
                        cout << "1111i=" << i << " counts=" << counts << " multi =" << multi << endl;
                        counts += (this->time[i] - t2.time[i] - '0') * multi;
                        if(i % 2) multi /= 60;
                        else multi /= 10;
                    }
                }
                return counts;
            case 2:
                for(int i=0;i<=7;i++){
                    if(i != 2 && i != 5){
                        cout << "2222i=" << i << " counts=" << counts << " multi =" << multi << endl;
                        printf("t2.time[i] = %d\n",t2.time[i]- this->time[i]);
                        //counts += (t2.time[i]  -'0') * multi;
                        if(i % 3) multi /= 10;
                        else multi /= 60;
                    }
                }
                return counts;
            default:
                return 0;
        }

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
    return 0;
}
