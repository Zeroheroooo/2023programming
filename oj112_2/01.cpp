#include <iostream>

using namespace std;

class Point{
    public:
    float x;
    float y;
};

int main(){
    Point point;
    int n;
    cin >> n ;
    for(int i=0;i<n;i++){
        cin >> point.x >> point.y;
        cout << "(" << point.x << ", " << point.y << ")" << endl;
    }
    return 0;
}
