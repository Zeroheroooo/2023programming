#ifndef _HERE_H_
#define _HERE_H_

#define MAX_N 10
#define inside(x,y) ((x) < MAX_N && (y) < MAX_N)


typedef struct point{
    int x;
    int y;
}XY_;

typedef struct stack{
    XY_ elements[MAX_N*MAX_N];
    int top;
}stack_;


int is_empty(stack_ *stackptr){
    if(stackptr->top == -1) return 1;
    return 0;
}

int is_full(stack_ *stackptr){
    if(stackptr->top == MAX_N * MAX_N -1) return 1;
    return 0;
}

void push(stack_ *stackptr, XY_ newpoint){
    if(!is_full(stackptr)){
        stackptr->top++;
        stackptr->elements[stackptr->top] = newpoint;
    }
}

XY_ pop(stack_ *stackptr){
    //XY_ tmp={-1,-1};
    if(!is_empty(stackptr)) return stackptr->elements[stackptr->top--];
}

#endif