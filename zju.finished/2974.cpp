#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<cmath>
// We have passed the problem here, but it is better to use Matrix to 
// indicate the water swift from status i to status i+1
// so M^n = M^(n/2) * M^(n/2), plus M if n is odd
using namespace std;
enum {
    SIZ = 24,
};
int num, cnt;
double eps = 1e-4;
double tab[2][SIZ];
double *cur, *nex;
vector<int> pour[SIZ];

void fun(){
    int t = 0, i, j;
    double v;
    while(t++ < cnt){
        memset(nex, 0, sizeof(tab[0]));
        for (i=0; i<num; ++i){
            if (pour[i].size() <=0 ){
                nex[i] += cur[i];
                continue;
            }
            v = cur[i] / pour[i].size();
            for (j=0; j<pour[i].size(); ++j){
                nex[pour[i][j]] += v;
            }
        }
        double *tmp = cur;
        cur = nex; nex = tmp;
        j = 0;
        for (i=0; i<num; ++i){
            j += (fabs(cur[i]-nex[i]) <= eps);
        }
        if (j>=num)
            break;
    }
    for (i=0; i<num; ++i){
        if (i) printf(" ");
        printf("%.2lf", cur[i]);
    }
    printf("\n");
}

void readIn(){
    scanf("%d ", &num);
    int i, n, a;
    cur = tab[0];
    nex = tab[1];
    for (i=0; i<num; ++i){
        scanf("%lf ", &cur[i]);
    }
    for (i=0; i<num; ++i){
        pour[i].clear();
        scanf("%d ", &n);
        while(n--){
            scanf("%d ", &a);
            --a;
            pour[i].push_back(a);
        }
    }
    scanf("%d ", &cnt);
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}

