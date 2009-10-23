#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
enum {
    SIZ = 1004,
};
int num;
int x[SIZ], y[SIZ], r[SIZ];

double fun(){
    if (num == 1) return 0.0;
    double ans;
    sort(x, x+num);
    sort(y, y+num);
    if (num == 2){
        ans = (x[1] - x[0]) * (y[0] + y[1]) ;
        ans /= 2; 
        return ans;
    }
    r[0] = x[1] - x[0];
    r[num-1] = x[num-1] - x[num-2];
    for (int i=2; i<num; ++i){
        r[i-1] = x[i] - x[i-2];
    }
    sort(r, r+num);
    ans = 0;
    for (int i=0; i<num; ++i){
        ans += r[i] * y[i];
    }
    ans /= 2;
    return ans;
}

void readIn(){
    scanf("%d", &num);
    for (int i=0; i<num; ++i){
        scanf("%d%d", &x[i], &y[i]);
    }
}

int main(){
    int tn;
    scanf("%d", &tn);
    while(tn-- > 0){
        readIn();
        double t = fun();
        printf("%.1lf\n", t);
    }

    return 0;
}

