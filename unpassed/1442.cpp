#include<iostream>
using namespace std;
// Wrong Answer
enum {
    SIZ = 8,
};
int num, val;
int b[SIZ];
double calc(int v){
    if(v < 0) return 0;
    double ret = 1;
    int t = v + num - 1;
    v = min(v, t - v);
    for(int i=1; i<=v; i++){
        ret *= t - i + 1;
        ret /= i;
    }
    return ret;
}
double  fun(){
    if(val == 0) return 1;
    else if(val < 0) return 0;
    double  ret = 0;
    unsigned lim = 1<<num, v, c;
    for(unsigned s=0; s<lim; ++s){
        v = val; c = 0;
        for(int i=0; i<num; i++){
            if(s & (1<<i)){
                v -= b[i];
                c++;
            }
        }
        if(c % 2 == 0)
            ret += calc(v);
        else 
            ret -= calc(v);
    }
    return ret;
}

void readIn(){
    scanf("%d%d",&num,&val);
    int a;
    for(int i=0; i<num; i++){
        scanf("%d%d", &a, &b[i]);
        b[i] -= a - 1;
        val  -= a;
    }
}

int main(){
    int tst;
    scanf("%d", &tst);
    while(tst--){
        readIn();
        printf("%.0lf\n", fun());
    }
    return 0;
}

