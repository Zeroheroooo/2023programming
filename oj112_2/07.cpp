#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    Point(double _x, double _y);
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }

private:
    double x, y;
};

//********************************************************
class Segment {
public:
    Point p1,p2;
    Segment(Point x,Point y) : p1(x),p2(y){
    }

    double length(){
        double x = abs(p1.getX()-p2.getX());
        double y = abs(p1.getY()-p2.getY());
        double len = sqrt(x*x+y*y);
        return len;
    }

    Point getEnd(int n){
        if(n == 0) return p1;
        return p2;
    }
};
//*********************************************************

int main(){


    return 0;
}
