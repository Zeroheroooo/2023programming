#include <stdio.h>

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

    /*int chess[8][8]={{2,1,1,1,1,1,1,0},
                    {2,1,2,1,1,2,1,0},
                    {2,2,1,1,1,2,1,1},
                    {2,1,2,1,1,2,1,0},
                    {2,1,2,2,2,2,1,0},
                    {2,2,2,2,2,2,1,0},
                    {2,2,2,1,1,2,0,0},
                    {0,1,0,0,0,0,0,0}
                    };
    */


    int i,j,color,dx,dy,currentx,currenty;
    int chess[8][8];

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            scanf("%d",&chess[i][j]);
        }
    }


    //print
    /*for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d",chess[i][j]);
        }
        printf("\n");
    }*/

    scanf("%d %d",&i,&j);

    currentx=i;
    currenty=j;
    switch(chess[i][j]){
        case 0:
            printf("(%d,%d) blank\n",i,j);
            break;
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 1:
            printf("(%d,%d)=1 black\n",i,j);
            for(dx=-1;dx<=1;dx++){
                for(dy=-1;dy<=1;dy++){
                    currentx+=dx;
                    currenty+=dy;


                    while(currentx>=0 && currentx<8 && currenty>=0 && currenty<8 && chess[currentx][currenty] ==2){
                        currentx+=dx;
                        currenty+=dy;
                        //printf("+(%d,%d)\n",currentx,currenty);
                        if(currentx>=0 && currentx<8 && currenty>=0 && currenty<8 && chess[currentx][currenty] ==0){
                            printf("=>available(%d,%d)\n",currentx,currenty);
                            break;
                        }
                    }

                    currentx=i;
                    currenty=j;
                }
            }
            break;
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 2:
            printf("(%d,%d)=2 white\n",i,j);
            for(dx=-1;dx<=1;dx++){
                for(dy=-1;dy<=1;dy++){
                    currentx+=dx;
                    currenty+=dy;


                    while(currentx>=0 && currentx<8 && currenty>=0 && currenty<8 && chess[currentx][currenty] ==1){
                        currentx+=dx;
                        currenty+=dy;
                        //printf("+(%d,%d)\n",currentx,currenty);
                        if(currentx>=0 && currentx<8 && currenty>=0 && currenty<8 && chess[currentx][currenty] ==0){
                            printf("=>available(%d,%d)\n",currentx,currenty);
                            break;
                        }
                    }

                    currentx=i;
                    currenty=j;
                }
            }
            break;
        default: break;

    }
}

