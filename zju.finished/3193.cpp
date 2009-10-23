#include<iostream>
#include<algorithm>
using namespace std;

enum {
    SIZ = 17,
};

int ran[SIZ] = {1, 2, 10, 11, 100, 101, 1000, 1002, 
    10000, 10001, 100000, 100001, 1000000, 1000001,
    10000000, 10000001, 100000000};
int val[SIZ] = {7, 27,70,270, 700,2700, 7000, 26999,
    70000,270000, 700000,1699999, 7000000, 27000000,
    70000000,270000000, 700000000};

void fun(){
    int len;
    scanf("%d", &len);
    int *s = lower_bound(ran, ran+SIZ, len);
    s = s - ran + val;
    printf("%d\n", *s);
}

int main(){
    int tn = 1;
    scanf("%d", &tn);
    while(tn-- > 0){

        fun();
    }

    return 0;
}

