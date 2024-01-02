#include <stdio.h>
#define MAX_N 10

int maze[MAX_N][MAX_N] ={
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
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

int find_path(int i,int j,int n,int outx,int outy){
    if(i==outx && j==outy){//stop
        printf("route->(%d,%d)\n",i,j);
        return 1;
    }
    //searching exit
    else if(maze[i][j] == 0 && (i>=0 && i<n && j>=0 && j<n)){//not visited && inside maze
        maze[i][j] = 2;
        printf("route->(%d,%d)\n",i,j);
        return (find_path(i+1,j,n,outx,outy) || find_path(i-1,j,n,outx,outy) || find_path(i,j+1,n,outx,outy) || find_path(i,j-1,n,outx,outy));
    }
    return 0;
}


int main(){
    //set entrance (x,y)
    int x=1,y=0;

    //set exit (6,9)
    int outx=6,outy=9;

    if(find_path(x,y,MAX_N,outx,outy)){
        printf("succeed\n");
    }
    else printf("No way out!!\n");

    return 0;

}
