#ifndef _HERE_H_
#define _HERE_H_

#define MAX_N 10
#define EQUAL(p,q) (p.x == q.x && p.y == q.y)

typedef struct coordinate{
    int x;
    int y;
}XY_;

typedef struct stack{
    XY_ path[MAX_N*MAX_N];
    int top;
}pocket_;


void push(pocket_ *stackptr, XY_ xy);
XY_ pop(pocket_ *stackptr);
int is_empty(pocket_ *stackptr);

#endif