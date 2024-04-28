#include <iostream>
#include <cmath>

using namespace std;

class Charge{
public:
    int counts=0;

    Charge(int km){
        if(km > 200){
            counts += round((km-200)*1.2*0.75);
            km -= (km-200);
        }

        counts += round(km*1.2);

        cout << counts << endl;
    }
};

int main(){
    int km;
    cin >> km;
    Charge charge(km);
    return 0;

}
