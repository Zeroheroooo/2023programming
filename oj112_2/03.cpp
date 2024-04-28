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

class Triangle{

public:
    double perimeter(Point p1, Point p2,Point p3){
        double d = 0,x,y;
        x = abs(p1.getX()-p2.getX());
        y = abs(p1.getY()-p2.getY());
        d+= sqrt(x*x+y*y);

        x = abs(p2.getX()-p3.getX());
        y = abs(p2.getY()-p3.getY());
        d+= sqrt(x*x+y*y);

        x = abs(p3.getX()-p1.getX());
        y = abs(p3.getY()-p1.getY());
        d+= sqrt(x*x+y*y);
        return d;
    }
};

int main(){
    Point p1,p2,p3;
    int n;
    double x1,y1,x2,y2,x3,y3;
    cin >> n ;

    Triangle t;
    for(int i=0;i<n;i++){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        p1.setX(x1);
        p1.setY(y1);
        p2.setX(x2);
        p2.setY(y2);
        p3.setX(x3);
        p3.setY(y3);
        cout << t.perimeter(p1,p2,p3) << endl;
    }
    return 0;
}

