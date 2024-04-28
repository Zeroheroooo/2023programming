#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector<int> > matrix;

class Matrix{
public:
    int n;
    void scan(){
        cin >> n;
        matrix.resize(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cin >> matrix[i][j];
        }
    }

    void rotate_l(){
        vector <vector<int> > newMatrix = {matrix.size(), vector<int> (matrix.size())};
        if(matrix.empty()){
            cout << "No element in matrix can be rotated.\n";
            return;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                newMatrix[n-j-1][i] = matrix[i][j];
        }
        matrix = newMatrix;
    }

    void rotate_r(){
        vector <vector<int> > newMatrix = {matrix.size(), vector<int> (matrix.size())};
        if(matrix.empty()){
            cout << "No element in matrix can be rotated.\n";
            return;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                newMatrix[j][n-i-1] = matrix[i][j];
        }
        matrix = newMatrix;
    }

    void print(){
        if(matrix.empty()){
            cout << "No element in matrix can be printed.\n";
            return;
        }
            for(int i=0;i<n;i++){
                for(int  j=0;j<n;j++){
                    cout << matrix[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
    }
};

int main(){
    Matrix M;
    string instr,dir;
    int n;
    while(cin >> instr && instr != "stop"){
        if(instr == "scan") M.scan();
        else if(instr == "print") M.print();
        else if(instr == "rotate"){
            cin >> dir;
            if(dir == "left") M.rotate_l();
            else if(dir == "right") M.rotate_r();
        }
        else cout << "unknown\n";
    }
    return 0;
}
