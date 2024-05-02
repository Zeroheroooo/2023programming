#include <iostream>
#include <array>
#include <algorithm>
#include <cstdio>
using namespace std;

char maze[2*39+1][2*39+1];
array<int,1600> Listx;
array<int,1600> Listy;
//initiall

bool dead(int now,int m,int n){// !at least a blank
    int counts = 0;
    if(Listx[now] == 1 || maze[Listx[now]-1][Listy[now]] == ' ') counts++;//up
    if(Listx[now] == m || maze[Listx[now]+1][Listy[now]] == ' ' || maze[Listx[now]+1][Listy[now]] == '*') counts++;//down
    if(Listy[now] == 1 || maze[Listx[now]][Listy[now]-2] == ' ' || maze[Listx[now]][Listy[now]-2] == '*') counts++;//left
    if(Listy[now] ==2*n-1 || maze[Listx[now]][Listy[now]+2] == ' ' || maze[Listx[now]][Listy[now]+2] == '*') counts++;//right
    if(counts == 4) return true;
    return false;
}

void print(int m,int n){
    for(int i=0;i<m+1;i++){
        for(int j=0;j<2*n+1;j++)
            if(!(i==0 && j==2*n)){
                if(maze[i][j] == '*' && i==m) printf("_");
                else if(maze[i][j] == '*' && i!=m) printf(" ");
                else printf("%c",maze[i][j]);
            }

        //if(i!=m) printf("\n");
        printf("\n");
    }
}

int main(){
    int cases,m,n,startx,starty,now,N,popx,popy;
    char instr;

    cin >> cases;
    while(cases--){
        cin >> m >> n;
        for(int i=0;i<m+1;i++){
            for(int j=0;j<2*n+1;j++){
                if(i==0){
                    if(j%2) maze[i][j] = '_';
                    else if(j!=2*n)maze[i][j] = ' ';
                }
                else{
                    if(j%2) maze[i][j] = '_';
                    else maze[i][j] = '|';
                }
            }
        }
        //////////////////////////////////////////////////////
            now = 1;
            cin >> startx >> starty;
            Listx[now] = m-startx+1;
            Listy[now] = 2*starty-1;

            if(Listx[now] == m) maze[Listx[now]][Listy[now]] = '*';
            else maze[Listx[now]][Listy[now]] = ' ';

        ////////////////////////////////////////////////////////
        while(now != 0){
            if(!dead(now,m,n)){
                cin >> instr;
                switch(instr){
                    case 'F':
                        cin >> N;
                        reverse(&Listx.at(N),&Listx.at(now+1));
                        reverse(&Listy.at(N),&Listy.at(now+1));
                        for(int i=0;i<=now;i++) printf("x=%d y=%d\n",Listx[i],Listy[i]);
                        break;

                    case 'U':
                        popx = Listx[now];
                        popy = Listy[now];

                        now++;//new
                        Listx[now] = popx - 1;
                        Listy[now] = popy;
                        maze[Listx[now]][Listy[now]] = ' ';
                        print(m,n);
                        break;

                    case 'D':
                        popx = Listx[now];
                        popy = Listy[now];

                        now++;//new
                        Listx[now] = popx + 1;
                        Listy[now] = popy;
                        if(Listx[now] == m) maze[Listx[now]][Listy[now]] = '*';
                        else maze[Listx[now]][Listy[now]] = ' ';
                        print(m,n);
                        break;

                    case 'L':
                        popx = Listx[now];
                        popy = Listy[now];

                        now++;//new
                        Listx[now] = popx;
                        Listy[now] = popy - 2;
                        maze[Listx[now]][Listy[now]+1] = ' ';
                        maze[Listx[now]][Listy[now]] = '*';
                        //else maze[Listx[now]][Listy[now]] = ' ';
                        print(m,n);
                        break;

                    case 'R':
                        popx = Listx[now];
                        popy = Listy[now];

                        now++;//new
                        Listx[now] = popx;
                        Listy[now] = popy + 2;
                        maze[Listx[now]][Listy[now]-1] = ' ';
                        maze[Listx[now]][Listy[now]] = '*';
                        //else maze[Listx[now]][Listy[now]] = ' ';
                        print(m,n);
                        break;

                    default:
                        break;
                }

            }
            else now--;
        }
        print(m,n);

        if(cases) printf("\n");
    }
}

