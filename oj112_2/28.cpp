#include <iostream>
#include <cmath>
using namespace std;

class Point {
    private:
        float x,y;
    public:
        Point(){x=y=0;}
        Point(float x_,float y_):x(x_),y(y_){}
        void printPoint(){
            cout << "(" << x << ", " << y << ")";
        }
        float getX(){return x;}
        float getY(){return y;}
        void setX(float x_){x=x_;}
        void setY(float y_){y=y_;}

        float getDistance(Point &another){return sqrt((x-another.getX())*(x-another.getX()) + (y-another.getY())*(y-another.getY()));}

};

class Segment {
    private:
        Point point1,point2;
    public:
        Segment(){
            point1.setX(0);
            point1.setY(0);
            point2.setX(0);
            point2.setY(0);
        }

        Segment(Point&p1,Point &p2){
            point1.setX(p1.getX());
            point1.setY(p1.getY());
            point2.setX(p2.getX());
            point2.setY(p2.getY());
        }

        float getLength(){
            return point1.getDistance(point2);
        }

};

int main(){
    Point p01(0,1),p02(1,2);
    p01.printPoint();
    p02.printPoint();
    cout << p01.getDistance(p02) << endl;

    Segment L(p01,p02);
    cout << L.getLength() << endl;



}
