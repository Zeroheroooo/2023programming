#include <iostream>

using namespace std;

class Point {
private:
    float X,Y;

public:

    Point(){
        X = 0;
        Y = 0;
    }
    void setXY(float x,float y){
        X = x;
        Y = y;
    }

    float getX(){
        return X;
    }
    float getY(){
        return Y;
    }

};


int main(){

    int i,n;
    cin >> n;

    Point point;
    float x,y;
    for(i=0;i<n;i++){
        cin >> x >> y;
        point.setXY(x,y);
        cout << "(" << point.getX() << ", " << point.getY() << ")" << endl;
    }

    return 0;
}
