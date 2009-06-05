#include<iostream>
using namespace std;
enum {
    SIZ = 50000,
};
struct Node {
    unsigned s, n; // s is the product, n*(n-1) = s;
};
int num;
Node tree[SIZ];
unsigned p,q;

void init(){
    unsigned n,t;
    num = 0;
    for(n=2, t=n*(n-1); n<=SIZ; ++n, t=n*(n-1)){
        tree[num].s=t;
        tree[num].n=n;
        num++;
    }
}
int find(unsigned v){
    int l=0, h=num,m;
    while(l < h){
        m = (l+h)/2;
        if(tree[m].s < v){
            l = m + 1;
        } else if(tree[m].s > v){
            h = m;
        } else {
            return tree[m].n;
        }
    }
    return -1;
}
void fun(){
    if(p == 0){
        printf("0 2\n");
        return;
    }
    int i,k,r;
    for(i=0; i<num; i++){
        if(tree[i].s%q!=0) continue;
        k = tree[i].s / q;
        r = find(p*k);
        if(r==-1) continue;
        printf("%u %u\n", r, tree[i].n-r);
        return;
    }
    printf("impossible\n");
}
unsigned gcd(unsigned a, unsigned b){
    unsigned t;
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main(){
    unsigned v;
    init();
    scanf("%u%u",&p,&q);
    while(p + q){
        v = gcd(p, q);
        p /= v;
        q /= v;
        fun();
        scanf("%u%u",&p,&q);
    }
    return 0;
}

