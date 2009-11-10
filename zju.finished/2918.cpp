#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
enum {
    SIZ = 104,
};

int H, W;
char mat[SIZ][SIZ];
double tab[2][SIZ];

void fun(){
    double *pre=tab[0], *cur=tab[1];
    memset(pre, 0, sizeof(tab[0]));
    for (int i=H-1; i>=0; --i){
        for (int j=0; j<W; ++j){
            if (i+1<H && mat[i+1][j] == '*'){
                int t = 0;
                double v = 0;
                if (j!=0){
                    v += pre[j-1];
                    ++t;
                }
                if(j!=W-1){
                    v += pre[j+1];
                    ++t;
                }
                cur[j] = 0;
                if (t) cur[j] = v/t;
            } else {
                cur[j] = pre[j];
            }
            if (isdigit(mat[i][j])){
                cur[j] = mat[i][j] - '0';
            }else if (mat[i][j]=='*'){
                cur[j] = 0;
            }
        }
        swap(pre, cur);
    }
    double ans = 0;
    for (int i=0; i<W; ++i){
        ans = max(pre[i], ans);
    }
    printf("%.06lf\n", ans);
}

void readIn(){
    scanf("%d%d ", &H, &W);
    for (int i=0; i<H; ++i){
        scanf("%s", mat[i]);
    }
}

int main(){
    int tn;
    scanf("%d", &tn);
    while(tn-- > 0){
        readIn();
        fun();
    }

    return 0;
}

