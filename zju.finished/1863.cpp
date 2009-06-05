#include<cstdio>
// 弱题
using namespace std;
struct Node {
    int a;
    int b;
};
Node up[2];
Node dn[2];
int p,q,r,s;
int low,high;

int get_low(){
    if(low >= 2)
        return 0;
    if(dn[low].a <= dn[low].b)
        return dn[low].a ++;
    low ++;
    return get_low();
}
int get_high(){
    if(high >= 2)
        return 0;
    if(up[high].a <= up[high].b)
        return up[high].a ++;
    high ++;
    return get_high();
}

void fun(){
    up[0].a = q + 1;
    up[0].b = p;
    dn[0].a = s + 1;
    dn[0].b = r;
    if( p -q < r-s){
        up[1].a = p - q + 1;
        up[1].b = r - s;
    } else {
        dn[1].a = r - s + 1;
        dn[1].b = p - q;
    }
    low = high = 0;
    double ret = 1.0;
    r = get_high(); s = get_low();
    while(r > 0 && s > 0){
        ret *= r;
        ret /= s;
        r = get_high(); s=get_low();
        while(ret > 1000000 && s > 0){
            ret /= s;
            s = get_low();
        }
        while(ret < 0.000001 && r > 0){
            ret *= r;
            r = get_high();
        }
    }
    while(r > 0){
        ret *= r;
        r = get_high();
    }
    while(s > 0){
        ret /= s;
        s = get_low();
    }
    printf("%.5lf\n", ret);
}

int main(){
    
    while(scanf("%d%d%d%d", &p, &q, &r, &s) > 0){
        up[1].a = up[1].b = dn[1].a = dn[1].b = 0;
        fun();
    }
    
	return 0;
}
