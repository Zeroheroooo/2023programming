#include <stdio.h>
#define inside(x,y) (x>=0 && x<8 && y>=0 && y<8)

int footSteps(int chess[8][8], int i, int j, int dx, int dy){
    int count=1;
    int color=chess[i][j];

        while(i+dx>=0 && i+dx<8 && j+dy>=0 && j+dy<8 && chess[i+dx][j+dy] == 3-color){
            i += dx;
            j += dy;
            count++;
        }
        if(chess[i][j] == 3-color && i+dx>=0 && i+dx<8 && j+dy>=0 && j+dy<8 && chess[i+dx][j+dy] == 0){
            return count;
        }
        else return 0;
}

int direction(int chess[8][8], int next[8][8], int i, int j){
    int steps = 0;
    int canFlip=0;
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            if(!(dx == 0 && dy == 0)){
                steps = footSteps(chess,i,j,dx,dy);
                if(steps != 0){
                    next[i+steps*dx][j+steps*dy] = 1;
                    canFlip += steps-1;
                }
            }    
        }
    }
    return canFlip;
}

void checkAvailablePosition(int color,int next[8][8],int chess[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            next[i][j] = 0;
        }
    }

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(chess[i][j] == color) direction(chess,next,i,j);
        }
    }

    if(color == 1) printf("black available:\n");
    else printf("white available:\n");
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(next[i][j] == 1) printf("(%d,%d) ",i,j);
        }
    }
    printf("\n");
}

void flip(int chess[8][8], int i, int j){
    int steps = 0;
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            if(!(dx == 0 && dy == 0)){
                steps = footSteps(chess,i,j,dx,dy);
                if(steps != 0){
                    for(int k=1;k<=steps;k++){
                        chess[i+k*dx][j+k*dy] = chess[i][j];
                    }
                }
            }  
        }
    }

}

/*int countflip(int chess,int next,int i,int j){
    int canFlip = direction();


}*/
/*
int noMove(int next[8][8]){
    int count=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(next[i][j] != 0) count++;
        }
    }

    return (!count);
}
*/
int main(){
    /*int chess[8][8]={{0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,2,1,0,0,0},
                    {0,0,0,1,2,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0}
                    };
     */

    int chess[8][8]={{2,1,1,1,1,1,1,0},
                    {2,1,2,1,1,2,1,0},
                    {2,2,1,1,1,2,1,1},
                    {2,1,2,1,1,2,1,0},
                    {2,1,2,2,2,2,1,0},
                    {2,2,2,2,2,2,1,0},
                    {2,2,2,1,1,2,0,0},
                    {0,1,0,0,0,0,0,0}
                    };
    

    int next[8][8],i,j;
    /*int chess[8][8];

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            scanf("%d",&chess[i][j]);
        }
    }
    */

    //while(1){
        checkAvailablePosition(1,next,chess);//black
        printf("black your turn : i j\n");
        scanf("%d %d",&i,&j);
        chess[i][j] = 1;
        flip(chess,i,j);

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                printf("%d ",chess[i][j]);
            }
            printf("\n");
        }






        checkAvailablePosition(2,next,chess);//white
   // }
    printf("finish\n");


    
}

