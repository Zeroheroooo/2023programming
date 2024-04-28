#include <iostream>
#include <cmath>

using namespace std;

class Point{
private:
    double x;
    double y;

public:
    void setX(double X){
        x = X;
    }
    void setY(double Y){
        y = Y;
    }

    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
};

class Segment{

public:
    double distance(Point p1, Point p2){
            double x = abs(p1.getX()-p2.getX());
            double y = abs(p1.getY()-p2.getY());
            return sqrt(x*x+y*y);
        }
};

int main(){
    Point p1,p2;
    int n;
    double x1,x2,y1,y2;
    cin >> n ;

    Segment s;
    for(int i=0;i<n;i++){
        cin >> x1  >> y1 >> x2 >> y2;
        p1.setX(x1);
        p1.setY(y1);
        p2.setX(x2);
        p2.setY(y2);
        cout << s.distance(p1,p2) << endl;
    }
    return 0;
}
