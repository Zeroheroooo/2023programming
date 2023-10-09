#include <stdio.h>
int main(){
    int i,j;
    for(i=1;i<=3;i++){
        for(j=1;j<=9;j++){
            printf("%2dx%2d=%2d ",1+3*(i-1),j,(1+3*(i-1))*j);
            printf("%2dx%2d=%2d ",1+3*(i-1)+1,j,(1+3*(i-1)+1)*j);
            printf("%2dx%2d=%2d\n",1+3*(i-1)+2,j,(1+3*(i-1)+2)*j);
        }
        printf("\n");
    }
}