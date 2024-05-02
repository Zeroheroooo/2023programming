#include <iostream>
#include <array>
#include <algorithm>
#include <cstdio>
using namespace std;

char maze[2*39+1][2*39+1];
array<int,1600> Listx;
array<int,1600> Listy;

bool dead(int now,int m,int n){//has at least a blank
    int counts = 0;
    if(Listx[now]-2 < 0 || Listx[now]-2 > 0 && maze[Listx[now]-2][Listy[now]] != ' ') counts++;//up
    if(Listx[now]+2 > 2*m || Listx[now]+2 < 2*m && maze[Listx[now]+2][Listy[now]] != ' ') counts++;//down
    if(Listy[now]-2 < 0 || Listy[now]-2 > 0 && maze[Listx[now]][Listy[now]-2] != ' ') counts++;//left
    if(Listy[now]+2 > 2*n || Listy[now]+2 < 2*n && maze[Listx[now]][Listy[now]+2] != ' ') counts++;//right
    if(counts == 4) return true;
    return false;
}

int main(){
    int cases,m,n,startx,starty,now,N,popx,popy;
    char instr;

    cin >> cases;
    while(cases--){
        cin >> m >> n;
        if(m==0) n=0;
        if(n==0) m=0;
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
                //}
            }
        }
        ////////////////////////////////////////////////////////
        now = 0;
        if(!(m==0 || m==1 && n==1)){
            now = 1;
            cin >> startx >> starty;
            Listx[now] = 2*(m-startx)+1;
            Listy[now] = 2*starty-1;

            maze[Listx[now]][Listy[now]] = '*';
        }
        ////////////////////////////////////////////////////////
        while(now != 0){
            if(!dead(now,m,n)){
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
                if(!(i==0 && j==2*n)){
                    if(i%2){//odd row
                        if(!(j%2)) printf("%c",maze[i][j]);
                        else printf("%c",maze[i+1][j]);
                    }
                    else//even row
                        if(i==0) printf("%c",maze[i][j]);
                }
            }
            if(i==0 || (i%2) && i!=2*m-1) printf("\n");
        }
        if(cases) printf("\n\n");
    }
}
