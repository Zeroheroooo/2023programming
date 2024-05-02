#include <iostream>
#include <array>
#include <algorithm>
#include <cstdio>
using namespace std;

class Maze {
    public:
        char maze[2*39+1][2*39+1];
        array<int,1600> Listx;
        array<int,1600> Listy;
        int m,n,now=1,N,popx,popy;

        Maze(int M,int N):m(M),n(N){
            for(int i=0;i<2*m+1;i++){
                for(int j=0;j<2*n+1;j++){
                    if(i%2 && !(j%2)) maze[i][j] = '|';
                    else if(!(i%2) && j%2) maze[i][j] = '_';
                    else maze[i][j] = ' ';
                }
            }
        }

        bool dead(){//delete ?
            int counts = 0;
            if(Listx[now]-2 < 0 || Listx[now]-2 > 0 && maze[Listx[now]-2][Listy[now]] != ' ') counts++;//up
            if(Listx[now]+2 > 2*m || Listx[now]+2 < 2*m && maze[Listx[now]+2][Listy[now]] != ' ') counts++;//down
            if(Listy[now]-2 < 0 || Listy[now]-2 > 0 && maze[Listx[now]][Listy[now]-2] != ' ') counts++;//left
            if(Listy[now]+2 > 2*n || Listy[now]+2 < 2*n && maze[Listx[now]][Listy[now]+2] != ' ') counts++;//right
            if(counts == 4) return true;
            return false;
        }

        void print(){
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
        }

        void push_start(int startx,int starty){
            now=1;
            Listx[now] = 2*(m-startx)+1;
            Listy[now] = 2*starty-1;
            maze[Listx[now]][Listy[now]] = '*';
        }

        int continue_(){return now;}

        void F(){
            cin >> N;
            reverse(&Listx.at(N),&Listx.at(now+1));
            reverse(&Listy.at(N),&Listy.at(now+1));
        }

        void U(){
            maze[Listx[now]-1][Listy[now]] = ' ';//wall

            now++;//new
            Listx[now] = Listx[now-1] - 2;
            Listy[now] = Listy[now-1];
            maze[Listx[now]][Listy[now]] = '*';
        }

        void D(){
            maze[Listx[now]+1][Listy[now]] = ' ';//wall

            now++;//new
            Listx[now] = Listx[now-1] + 2;
            Listy[now] = Listy[now-1];
            maze[Listx[now]][Listy[now]] = '*';
        }

        void L(){
            maze[Listx[now]][Listy[now]-1] = ' ';//wall

            now++;//new
            Listx[now] = Listx[now-1];
            Listy[now] = Listy[now-1] - 2;
            maze[Listx[now]][Listy[now]] = '*';
        }

        void R(){
            maze[Listx[now]][Listy[now]+1] = ' ';//wall

            now++;//new
            Listx[now] = Listx[now-1];
            Listy[now] = Listy[now-1] + 2;
            maze[Listx[now]][Listy[now]] = '*';
        }

        void delete_(){now--;}
};

int main(){
    int cases,m,n,startx,starty;
    char instr;

    cin >> cases;
    while(cases--){
        cin >> m >> n;
        Maze maze(m,n);
        ////////////////////////////////////////////////////////
        cin >> startx >> starty;
        maze.push_start(startx,starty);
        ////////////////////////////////////////////////////////
        while(maze.continue_()){
            if(!maze.dead()){
                cin >> instr;
                switch(instr){
                    case 'F': maze.F(); break;

                    case 'U': maze.U(); break;

                    case 'D': maze.D(); break;

                    case 'L': maze.L(); break;

                    case 'R': maze.R(); break;

                    default: break;
                }
            }
            else maze.delete_();
        }
        maze.print();
        if(cases) printf("\n\n");
    }
}


