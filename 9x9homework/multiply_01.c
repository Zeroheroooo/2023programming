#include <stdio.h>

int main(){
    int i,j;
    for(i=1;i<=9;i++){
        for(j=1;j<=9;j++){
            printf("%2d*%2d=%2d ",j,i,i*j);
        }
        printf("\n");
    }
}