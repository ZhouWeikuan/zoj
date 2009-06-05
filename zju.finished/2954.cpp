#include<iostream>
using namespace std;
struct Node {
    int pos;
    int dat[20];
    void init(int m){
        pos = 0;
        for(int i=m; i>0; i--){
            dat[pos++] = i;
        }
    }
    int top(){
        if(pos > 0){
            return dat[pos-1];
        }
        return 1000;
    }
    void pop(){pos--;}
    void push(int v){
        dat[pos++] = v;
    }
};

Node S[3];
bool move(int f, int t){
    int s = S[f].top();
    if(s >= S[t].top()) return false;
    S[f].pop();
    S[t].push(s);
    return true;
}

void fun(){
    int d, n, a, b, p = 0;
    scanf("%d%d",&d,&n);
    S[0].init(d); S[1].init(0); S[2].init(0);
    for(int i=1; i<=n; i++){
        scanf("%d%d",&a,&b);
        if(p != 0) continue;
        --a, --b;
        if(!move(a, b)){
            p = -i;
        }else if(S[2].pos == d){
            p = i;
        }
    }
    printf("%d\n", p);
}
int main(){
    int tst;

    scanf("%d", &tst);
    while(tst--){
        fun();
    }
    return 0;
}

