#include<iostream>
using namespace std;
enum {
    SIZ = 54,
};
double C[SIZ][SIZ] = {0};
int tot, sum[SIZ], out[SIZ], n, k;

void init(){
    C[0][0] = 1.0;
    for(int i=1;i<SIZ;i++){
        C[i][0] = 1.0;
        for(int j=1;j<=i;j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}
int readIn(){
    scanf("%d%d",&n,&k);
    if(n < 0)
        return 0;
    tot = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &sum[i]);
        tot += sum[i];
    }
    for(int i=0; i<n; i++){
        scanf("%d", &out[i]);
    }
    return n;
}
double fun(){
    double ret = 1.0;
    for(int i=0;i<n;i++){
        ret *= C[sum[i]][out[i]];
    }
    ret /= C[tot][k];
    return ret;
}

int main(){
    int a,b;

    init();
    while( readIn() > 0){
        printf("%.5lf\n", fun());
    }

    return 0;
}

