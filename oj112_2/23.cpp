#include <iostream>
#include <string>
using namespace std;

class DateTime{
public:
    string dt;

    DateTime(){dt = "1900/01/01 00:00:00";}

    DateTime(string &datetime):dt(datetime){}

    string toString(){return dt;}
};

int main(){
    string buf;

    getline(cin,buf);
    DateTime t1(buf);
    cout << t1.toString() << endl;
}