#include <stdio.h>
int main(){
    int i,j;
    for(i=1;i<=3;i++){
        for(j=1;j<=9;j++){
            printf("%2dx%2d=%2d ",i,j,i*j);
            printf("%2dx%2d=%2d ",i+3,j,(i+3)*j);
            printf("%2dx%2d=%2d\n",i+6,j,(i+6)*j);
        }
        printf("\n");
    }
}
