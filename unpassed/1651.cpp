#include<iostream>
using namespace std;
// TLE
enum {
    SIZ = 32800,
};
struct Node {
    unsigned p,d;
};
int num, pos;
Node tree[16];
int proc[SIZ];
unsigned pred[SIZ];
unsigned dely[SIZ];
unsigned ptr[2][16];

inline int getDelay(int d){
    return d>0?d:0;
}
unsigned getPos(unsigned v){
    int RetVal = 15;
    if (v& 0x00ff) { RetVal -= 8; v &= 0x00ff; }
    if (v& 0x0f0f) { RetVal -= 4; v &= 0x0f0f; }
    if (v& 0x3333) { RetVal -= 2; v &= 0x3333; }
    if (v& 0x5555) RetVal -=1;
    return RetVal;
}
void traceback(unsigned *v,unsigned a){
    pos = 0;
    unsigned p = pred[a];
    while(p != -1){
        v[pos++] = getPos(a^p);
        a = p;
        p = pred[a];
    }
}
int cmp(unsigned a, unsigned b){
    traceback(ptr[0],a);
    traceback(ptr[1],b);
    for(int i=pos-1; i>=0; i--){
        if(ptr[0][i]!=ptr[1][i]){
            return ptr[0][i]-ptr[1][i];
        }
    }
    return 0;
}
void fun(){
    unsigned lim = 1<<num;
    memset(proc, 0, sizeof(proc[0])*lim);
    memset(pred, -1, sizeof(pred[0])*lim);
    memset(dely, -1,  sizeof(dely[0])*lim);
    dely[0] = proc[0] = 0, pred[0]=-1;
    int t,i,b,v,p;
    for(i=1; i<lim; i++){
        for(b=1,p=0; b<=i; p++,b<<=1){
            if((i&b)==0) continue;
            t = i&(~b);
            v = dely[t] + getDelay(proc[t]+tree[p].p-tree[p].d);
            if(dely[i]>v||(dely[i]==v&&cmp(pred[i], t) > 0)){
                dely[i] = v;
                proc[i] = proc[t] + tree[p].p;
                pred[i] = t;
            }
        }
    }
    printf("%u\n", dely[lim-1]);
    traceback(ptr[0], lim-1);
    i = pos - 1;
    printf("%u", ptr[0][i]+1);
    for(i--; i>=0; i--){
        printf(" %u",ptr[0][i]+1);
    }
    printf("\n");
}
int readIn(){
    if(scanf("%d",&num)<0)
        return 0;
    for(int i=0; i<num; i++){
        scanf("%d%d", &tree[i].p, &tree[i].d);
    }
    return 1;
}
int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

