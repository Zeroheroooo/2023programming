#include <stdio.h>

int chess[8][8]={{0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,2,1,0,0,0},
                {0,0,0,1,2,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0}
                };
                

int check_available(int i, int j, int dx, int dy){
    printf("(%d,%d)=%d\n");
}

int main(){
    int i,j,dx,dy;

    i=j=3;
    dx=0;
    dy=1;


    int res = check_available(i, j, dx, dy);


}