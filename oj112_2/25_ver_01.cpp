#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int T,s,a,f,x,y;
    int X[50000];
    int Y[50000];
    scanf("%d",&T);
    for(int z=0;z<T;z++){

        scanf("%d %d %d",&s,&a,&f);

        for(int i=0;i<f;i++)
            scanf("%d %d",&X[i],&Y[i]);


        sort(X,X+f);
        sort(Y,Y+f);

        cout << "(Street: " << X[(f-1)/2] << ", Avenue: " << Y[(f-1)/2] << ")" << endl;
    }
    
}