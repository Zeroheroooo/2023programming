#include <iostream>
#include <array>
#include <algorithm>
#include <cstdio>
using namespace std;

char maze[2*39+1][2*39+1];
array<int,1600> Listx;
array<int,1600> Listy;

int alive(int now,int m,int n){//has at least a blank
    int counts = 0;
    if(Listx[now]-2 > 0 && maze[Listx[now]-2][Listy[now]] == ' ') counts++;//up
    if(Listx[now]+2 < 2*m && maze[Listx[now]+2][Listy[now]] == ' ') counts++;//down
    if(Listy[now]-2 > 0 && maze[Listx[now]][Listy[now]-2] == ' ') counts++;//left
    if(Listy[now]+2 < 2*n && maze[Listx[now]][Listy[now]+2] == ' ') counts++;//right
    return counts;
}

int main(){
    int cases,m,n,startx,starty,now,N,popx,popy;
    char instr;

    cin >> cases;
    while(cases--){
        cin >> m >> n;
        for(int i=0;i<2*m+1;i++){
            for(int j=0;j<2*n+1;j++){
                if(i%2){
                    if(!(j%2)) maze[i][j] = '|';
                    else maze[i][j] = ' ';
                }
                else{
                    if(j%2) maze[i][j] = '_';
                    else maze[i][j] = ' ';
                }
            }
        }
        ////////////////////////////////////////////////////////
        cin >> startx >> starty;
        now = 1;
        Listx[now] = 2*(m-startx)+1;
        Listy[now] = 2*starty-1;

        maze[Listx[now]][Listy[now]] = '*';
        ////////////////////////////////////////////////////////

        while(now != 0){
            if(alive(now,m,n)){//is not empty
                cin >> instr;
                switch(instr){
                    case 'F':
                        cin >> N;
                        reverse(&Listx.at(N),&Listx.at(now+1));
                        reverse(&Listy.at(N),&Listy.at(now+1));
                        break;

                    case 'U':
                        maze[Listx[now]-1][Listy[now]] = ' ';//wall

                        popx = Listx[now];
                        popy = Listy[now];

                        now++;//new
                        Listx[now] = popx - 2;
                        Listy[now] = popy;
                        maze[Listx[now]][Listy[now]] = '*';
                        break;

                    case 'D':
                        maze[Listx[now]+1][Listy[now]] = ' ';//wall

                        popx = Listx[now];
                        popy = Listy[now];

                        now++;//new
                        Listx[now] = popx + 2;
                        Listy[now] = popy;
                        maze[Listx[now]][Listy[now]] = '*';
                        break;

                    case 'L':
                        maze[Listx[now]][Listy[now]-1] = ' ';//wall

                        popx = Listx[now];
                        popy = Listy[now];

                        now++;//new
                        Listx[now] = popx;
                        Listy[now] = popy - 2;
                        maze[Listx[now]][Listy[now]] = '*';
                        break;

                    case 'R':
                        maze[Listx[now]][Listy[now]+1] = ' ';//wall

                        popx = Listx[now];
                        popy = Listy[now];

                        now++;//new
                        Listx[now] = popx;
                        Listy[now] = popy + 2;
                        maze[Listx[now]][Listy[now]] = '*';
                        break;

                    default:
                        break;
                }

            }
            else now--;
        }

        for(int i=0;i<2*m+1;i++){
            for(int j=0;j<2*n+1;j++){
                if(maze[i][j] == '*') printf(" ");
                else printf("%c",maze[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
