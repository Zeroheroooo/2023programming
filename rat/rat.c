#include <stdio.h>
#include <stdlib.h>
#include "Here.h"

int maze[MAX_N][MAX_N] ={{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                        { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
                        { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
                        { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
                        { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
                        { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
                        { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
                        { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
                        { 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
                        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
                        };
int mark[MAX_N][MAX_N];

int main(){

    //copy maze to mark
    for(int i=0;i < MAX_N;i++){
        for(int j=0;j < MAX_N;j++){
            mark[i][j] = maze[i][j];
        }
    }
    
    stack_ pocket;
    pocket.top = -1;

    //set entrance & exit
    XY_ exit={1,0},origin={6,9},newdir={-1,-1};
    printf("entrance:(%d,%d)  exit:(%d,%d)\n",origin.x,origin.y,exit.x,exit.y);

    //put in first (x,y)
    push(&pocket,origin);
    mark[origin.x][origin.y] = 1;
    int x,y;

    //////////////////////////////////   use stack    /////////////////////////////////////
    while(mark[exit.x][exit.y] != 1){
        origin = pop(&pocket);

        if(origin.x-1 < MAX_N && origin.y < MAX_N){
            x=origin.x-1;
            y=origin.y;
            if(maze[x][y] == 0 && mark[x][y] == 0){//up
                mark[x][y] = 1;
                push(&pocket,origin);
                newdir.x=x;
                newdir.y=y;
                push(&pocket,newdir);
                continue;
            }
        }

        if(origin.x < MAX_N && origin.y+1 < MAX_N){
            x=origin.x;
            y=origin.y+1;
            if(maze[x][y] == 0 && mark[x][y] == 0){//right
                mark[x][y] = 1;
                push(&pocket,origin);
                newdir.x=x;
                newdir.y=y;
                push(&pocket,newdir);
                continue;
            }
        }

        if(origin.x+1 < MAX_N && origin.y < MAX_N){
            x=origin.x+1;
            y=origin.y;
            if(maze[x][y] == 0 && mark[x][y] == 0 && inside(x,y)){//down
                mark[x][y] = 1;
                push(&pocket,origin);
                newdir.x=x;
                newdir.y=y;
                push(&pocket,newdir);
                continue;
            }
        }

        if(origin.x < MAX_N && origin.y-1 < MAX_N){
            x=origin.x;
            y=origin.y-1;
            if(maze[x][y] == 0 && mark[x][y] == 0 && inside(x,y)){//left
                mark[x][y] = 1;
                push(&pocket,origin);
                newdir.x=x;
                newdir.y=y;
                push(&pocket,newdir);
                continue;
            }
        }

        if(is_empty(&pocket)){
            printf("no way out!\n");
            return 0;
        }

    }
    //////////////////////////////////////////////////////////////////////////

    //output route
    stack_ route;
    route.top = -1;

    while(!is_empty(&pocket)){
        push(&route,pop(&pocket));
    }

    while(!is_empty(&route)){
        newdir = pop(&route);
        printf("route-> (%d, %d)\n",newdir.x,newdir.y);
    }
    
    return 0;
}