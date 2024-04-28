#include <iostream>
#include <string.h>

using namespace std;

class Point {
public:
  Point(double _x, double _y);
  double getX();
  double getY();
};

class Segment {
public:
  Segment(Point p1, Point p2);
  Point getEnd(int n);
  double length();
};

class Path {
public:

    Path(Segment *A, int B){
      	Point repeat[100];
        int counts=0,i,tail=0,now;
        double length=0;

        for(i=0;i<B-1;i++){
            if((A[i].getEnd(1)).getX() == (A[i+1].getEnd(0)).getX() && (A[i].getEnd(1)).getY() == (A[i+1].getEnd(0)).getY()){
              now = 0;
              	while(i <= tail){

                  now++;
                }
                counts++;
              	length += A[i].length();
            }
        }
        if(counts == B){
            cout << length << endl;
        }
        else cout << -1 << endl;

    }
};
int main(){

    return 0;
}
