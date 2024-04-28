#include <iostream>

using namespace std;

class Velocity{
    public:
    float X;
    float Y;
};

int main(){
    Velocity v;
    cin >> v.X >> v.Y ;
    cout << v.X/v.Y << endl;
    return 0;
}

