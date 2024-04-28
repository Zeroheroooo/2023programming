#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Check{
public:
    char num[11],turn[11],tmp;
    int len;

    void zero(){
        len = strlen(num);
        for(int i=len;i<10;i++){
            num[i] = '0';
            turn[i] = '0';
        }
        num[10] = '\0';
        turn[10] = '\0';
    }

    void reverse_(int len){
        for(int i=0;i < len/2;i++){
            tmp = num[i];
            num[i] = num[len-1-i];
            num[len-1-i] = tmp;
        }
    }

    void assign_(){
        for(int i=0;i<10;i++){
            turn[i] = num[i];
        }
    }

    void plus_(){
        for(int i=0;i<9;i++){
            num[i+1] += (turn[i] + num[i] - 2*'0') / 10;
            num[i] = (turn[i] + num[i] - 2*'0') % 10 +'0';
        }
        if(num[len] != '0') len++;
    }

    bool palindrome(){
        int counts=0;
        for(int i=0;i<len/2;i++){
            if(num[i] == num[len - 1 - i])
                counts ++;
        }
        if(counts == len/2) return true;
        return false;
    }

    void test(){
        int counts = 0;
        while(1){
            assign_();
            reverse_(len);
            plus_();
            counts ++;
            if(palindrome()) break;
            reverse_(len);
        }

        printf("%d ",counts);
        reverse_(len);
        num[len] = '\0';
        printf("%s\n",num);

    }
};


int main(){
    int n;
    scanf("%d",&n);

    Check p;
    for(int i=0;i<n;i++){
        scanf("%s",p.num);
        p.zero();
        p.test();
    }
    return 0;
}

