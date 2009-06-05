#include<iostream>
#include<queue>
#include<vector>
// Wrong Answer
using namespace std;
typedef unsigned long long u64;
u64 num;

void fun(){
    u64 a, b;
    priority_queue<u64, vector<u64>, greater<u64> > q;
    for(a=0; a<num; a++){
        scanf("%llu", &b);
        q.push(b);
    }
    unsigned long long s = 0;
    while(num-- > 1){
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        a += b;
        s += a;
        q.push(a);
    }
    a = q.top(); q.pop();
    printf("%llu\n", s);
}

int main(){
    int tst;
    scanf("%d", &tst);
    while(tst--){
        scanf("%llu", &num);
        fun();
        if(tst) printf("\n");
    }

    return 0;
}

