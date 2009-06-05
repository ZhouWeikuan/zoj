#include<iostream>
#include<iterator>
using namespace std;
enum {
    SIZ = 10,
};

int d[SIZ] = {0}; 
int t[SIZ] = {0};
int a,b;

void self(int n){
    int t;
    while(n > 0){
        t = n %10;
        n /= 10;
        d[t]++;
    }
}
void add(){
    for(int i=0;i<SIZ;i++){
        d[i] += t[i];
    }
}
void sub(){
    for(int i=0;i<SIZ;i++){
        d[i] -= t[i];
    }
}
void iter(int n, int k){
    for(int i=0;i<=k;i++){
        t[i] += n;
    }
}

void add_high(int n, int v){
    int k;
    while(n > 0){
        k = n %10; n /=10;
        t[k] += v;
    }
}
void add_cur(int n, int v){
    for(int i=0;i<n;i++){
        t[i] += v;
    }
    t[n]++;
}
void add_low(int v, int x){
    for(int i=0;i<SIZ;i++)
        t[i] += v;
    if(x)
        t[0]-= x;
}
void calc(int v){
    int k;
    int base = 1;
    int ind = 0;
    while(v > 0){
        k = v % 10;
        v /= 10;
        //高位数
        add_high(v, base * k);
        //本位数
        add_cur(k, base);
        //低位数
        int x = ind*base/10;
        add_low(k * x, x);
        base *= 10;
        ind ++;
    }
    // 调整0的个数，根据经验所得...
    t[0] -= base/10;
    ind -= 2;
    base /= 100;
    while(ind > 0){
        t[0] += ind * base;
        ind --;
        base /= 10;
    }
}

void fun(){
    memset(d , 0, sizeof(d));
    memset(t , 0, sizeof(t));
    calc(b);
    add();
    memset(t , 0, sizeof(t));
    calc(a);
    sub();
    self(a);
    printf("%d", d[0]);
    for(int i=1; i<SIZ; i++){
        printf(" %d", d[i]);
    }
    printf("\n");
}

int main(){
    /*
    while(cin>>a){
        memset(t,0,sizeof(t));
        calc(a);
        copy(t, t+SIZ, ostream_iterator<int>(cout," "));
        cout<<endl;
    }*/
    
    cin>>a>>b;
    while(a ){
        if(a > b){
            a ^= b; b ^= a; a^= b;
        }
        fun();
        cin>>a>>b;
    }

    return 0;
}
