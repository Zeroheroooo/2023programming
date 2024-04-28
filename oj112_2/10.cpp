#include <iostream>
#include <cmath>

using namespace std;

class Lplate{
public:
    int counts=0;

    Lplate(char plate[5]){
        for(int i=0;i<4;i++){
            if(plate[i] == '4') counts++;
        }
        if(counts == 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
};

int main(){
    char plate[5];
    cin >> plate;
    Lplate check4(plate);
    return 0;
}

