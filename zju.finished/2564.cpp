#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
enum {
    SIZ = 1004,
};
struct Node {
    int pos;
    double rad;
    bool operator <(const Node &o) const {
        return rad < o.rad;
    }
};

int N, R, H;
int st[2];
double ans;
double sum[SIZ];
int ptr[SIZ];
Node hi[SIZ];
Node md[SIZ];
Node lo[SIZ];

double getDis(double a, double b){
    a -= b;
    if (a < 0) a = -a;
    if (a >= M_PI) a = 2*M_PI - a;
    a *= R;
    b = H / 2.0;
    a *= a;
    b *= b;
    a = sqrt(a + b);
    return a;
}
void output(int p){
    int b = (ptr[p] + st[0]) % N;
    int c = (b + st[1]) % N;
    printf("%d %d %d\n", p + 1, md[b].pos + 1, lo[c].pos + 1);
}

void fun(){
    double m;
    memset(sum, 0, sizeof(sum));
    int i, d;
    for (i=0; i<N; ++i){
        for (d=0; d<N; ++d){
            sum[d] += getDis(hi[i].rad, md[(i+d)%N].rad);
        }
    }
    m = sum[0]; st[0] = 0;
    for (i=1; i<N; ++i){
        if (m > sum[i]){
            m = sum[i]; 
            st[0] = i;
        }
    }
    ans = m;

    memset(sum, 0, sizeof(sum));
    for (i=0; i<N; ++i){
        for (d=0; d<N; ++d){
            sum[d] += getDis(md[i].rad, lo[(i+d)%N].rad);
        }
    }
    m = sum[0]; st[1] = 0;
    for (i=1; i<N; ++i){
        if (m > sum[i]){
            m = sum[i]; 
            st[1] = i;
        }
    }
    ans += m;

    printf("%.4lf\n", ans);
    for (i=0; i<N; ++i){
        output(i);
    }
}

int readIn(){
    if (scanf("%d%d%d", &N,&R,&H)<0)
        return 0;
    for (int i=0; i<N; ++i){
        hi[i].pos = i;
        scanf("%lf", &hi[i].rad);
        if (hi[i].rad < 0){
            hi[i].rad += 2*M_PI;
        }
    }
    sort(hi, hi+N);
    for (int i=0; i<N; ++i)
        ptr[hi[i].pos] = i;
    for (int i=0; i<N; ++i){
        md[i].pos = i;
        scanf("%lf", &md[i].rad);
        if (md[i].rad < 0){
            md[i].rad += 2*M_PI;
        }
    }
    sort(md, md+N);
    for (int i=0; i<N; ++i){
        lo[i].pos = i;
        scanf("%lf", &lo[i].rad);
        if (lo[i].rad < 0){
            lo[i].rad += 2*M_PI;
        }
    }
    sort(lo, lo+N);
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

