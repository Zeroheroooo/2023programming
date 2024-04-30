#include <iostream>
#include <vector>
using namespace std;

class F{
    int x,y;
public:
    F(){x = 0; y = 0;}

    void setXY(int x_, int y_){
        x = x_;
        y = y_;
    }

    long long getDistance(int s,int a){return abs(s-x) + abs(a-y);}
};

int main(){
    unsigned int T,street,avenue,friends,x,y,S=1,A=1;
    unsigned long long distance, counts;//max 9,223,372,036,854,775,807.
    F f[50000];
    
    cin >> T;
    for(int z=0;z<T;z++){
        cin >> street >> avenue >> friends;
        for(int i=0;i<friends;i++){
            cin >> x >> y;
            f[i].setXY(x,y);
        }

        //count distance
        distance = 1000000000000000;
        for(int i=1;i<=street;i++){
            for(int j=1;j<=avenue;j++){
                counts = 0;
                for(int k=0;k<friends;k++){
                    counts += f[k].getDistance(i,j);
                }
                if(counts < distance){
                    distance = counts;
                    S = i;
                    A = j;
                }
            }
        }

        cout << "(Street: " << S << ", Avenue: " << A << ")" << endl;
    }
    
}