#include<iostream>
using namespace std;
// TLE, 使用缩写后的位图吗?但不知道数据大小呀...
unsigned nc, nt;
unsigned coin[52];

unsigned gcd(unsigned a, unsigned b){
    unsigned t;
    if(a < b){
        t = a, a = b, b = t;
    }
    while(b>0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
unsigned lcm(unsigned a, unsigned b){
    return a * b / gcd(a, b);
}
unsigned lcm(unsigned a, unsigned b, unsigned c, unsigned d){
    return lcm(lcm(a, b), lcm(c, d));
}

void fun(){
    int a,b,c,d;
    unsigned t, h,l, th, tl;
    unsigned v;
    while(nt--){
        h = 0xffffffff;
        l = 0;
        scanf("%u", &t);
        for(a=0;a<nc;a++)
        for(b=a+1;b<nc;b++)
        for(c=b+1;c<nc;c++)
        for(d=c+1;d<nc;d++){
            v = lcm(coin[a], coin[b], coin[c], coin[d]);
            tl = t / v * v;
            th = (t/v + (t%v!=0))*v;
            l = max(l, tl);
            h = min(h, th);
        }
        printf("%u %u\n", l, h);
    }
}

int readIn(){
    int i;
    scanf("%u%u",&nc,&nt);
    if(nc + nt == 0) return 0;
    for(i=0; i<nc; i++){
        scanf("%d",&coin[i]);
    }
    return 1;
}

int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

