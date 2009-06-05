#include<iostream>
using namespace std;
enum{
    SIZ = 24,
};
struct Node{
    int cur, diff;
};
int num;
Node tree[SIZ];

bool search(int &p){
    int cnt = 0;
    p = 0;
    for(int i=0;i<num; i++){
        if(tree[i].cur >= 10000){
            p = -1;
            return true;
        }
        if(tree[p].cur > tree[i].cur){
            p = i;
        }else if(tree[p].cur == tree[i].cur){
            cnt++;
        }
    }
    if(cnt == num){
        return true;
    }
    tree[p].cur += tree[p].diff;
    return false;
}
int fun(){
    int t;
    bool ret = false;
    while( ret == false){
        ret = search(t);
    }
    if(t>=0){
        t = tree[t].cur;
    }
    return t;
}
int readIn(){
    scanf("%d", &num);
    int a, b;
    for(int i=0; i<num; i++){
        scanf("%d%d%d",&tree[i].cur, &a, &b);
        tree[i].diff = b - a;
    }
    return num;
}
int main(){
    int tst=0, t;
    while(readIn() > 0){
        printf("Case #%d:\n", ++tst);
        t = fun();
        if(t >= 0){
            printf("The actual year is %d.\n", t);
        } else {
            printf("Unknown bugs detected.\n");
        }
        printf("\n");
    }
    return 0;
}

