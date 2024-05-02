#include <iostream>
#include <cstdio>
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
    int T,St,Ave,Frd,x,y,S,A;
    unsigned long long min, counts;//max 9,223,372,036,854,775,807.
    F f[50000];
    
    scanf("%d",&T);
    for(int z=0;z<T;z++){
        scanf("%d %d %d",&St,&Ave,&Frd);;
        for(int i=0;i<Frd;i++){
            scanf("%d %d",&x,&y);
            f[i].setXY(x,y);
        }

        //count distance
        min = 1000000000000000;
        for(int i=1;i<=St;i++){
            for(int j=1;j<=Ave;j++){
                counts = 0;
                for(int k=0;k<Frd;k++){
                    counts += f[k].getDistance(i,j);
                }
                if(counts < min){
                    min = counts;
                    S = i;
                    A = j;
                }
            }
        }
        printf("(Street: %d, Avenue: %d)\n",S,A);
    }
}