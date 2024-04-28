#include <iostream>

using namespace std;

class Point{
    public:
    int head;
    int tail;
};

int main(){
    int tmp;
    Point p1,p2;
    cin >> p1.head >> p1.tail >> p2.head >> p2.tail;

    if(p1.head > p1.tail){
        tmp = p1.head;
        p1.head = p1.tail;
        p1.tail = tmp;
    }
    if(p2.head > p2.tail){
        tmp = p2.head;
        p2.head = p2.tail;
        p2.tail = tmp;
    }


    if((p2.head < p1.head && p1.head < p2.tail) || (p2.head < p1.tail && p1.tail < p2.tail) || (p1.head < p2.head && p2.head < p1.tail) || (p1.head < p2.tail && p2.tail < p1.tail))
        cout << "overlay" << endl;
    else cout << "no overlay" << endl;

    return 0;

}
