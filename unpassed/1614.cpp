#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
enum {
    SIZ = 204,
};
struct Event {
    int type; // 0 for in, 1 for exit
    long double val;
    bool operator < (const Event &e) const {
        if (val != e.val)
            return val < e.val;
        return type < e.type;
    }
};

int N, num;
Event e[SIZ];

void fun(){
    int cnt = 0;
    long double lastx, ans=0;
    for (int i=0; i<num; ++i){
        if (e[i].type == 0){
            if (cnt != 0){
                ans += (e[i].val - lastx) 
                    * (pow((long double)N, (long double)cnt) - 1);
            }
            ++cnt;
        } else {
            ans += (e[i].val - lastx) 
                * (pow((long double)N, (long double)cnt) - 1);
            --cnt;
        }
        lastx = e[i].val;
    }
    cnt = 0;
    if (fabs(ans) < 1e-10){
        ans = 0;
    } else if (ans < 1.0){
        while(ans < 1.0){
            --cnt;
            ans *= 10;
        }
    } else {
        while(ans >= 10){
            ++cnt;
            ans /= 10;
        }
    }
    printf("%.010llfe", ans);
    printf("%+04d\n", cnt);
}

int readIn(){
    if (scanf("%d", &N) < 0) return 0;
    num = 0;
    for (int i=0; i<N; ++i){
        scanf("%llf", &e[num].val);
        e[num++].type = 0;

        scanf("%llf", &e[num].val);
        e[num++].type = 1;
    }
    sort(e, e+num);
    return 1;
}

int main(){
    
    while(readIn() > 0){
        fun();
    }

    return 0;
}

