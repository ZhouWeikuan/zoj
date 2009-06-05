#include<iostream>
using namespace std;
/*
 * 动态规划，我还是动了点脑子:)，把三种状态合并了
 *  一开始的处理有点烦，代码多了点，其实应该可以把很多种情况合并的
 *  状态应该是 d[x][y] = max{d[x+1][y+1], d[x+k][y+1]-4-k+1, d[x+1][y+k]-4-k+1}
 *  开始时某边可能有前导的-，因此取d[0][0], d[x][0]-4-x+1, d[0][y]-4-y+1的最大值
 */
enum {
    SIZ = 504,
    A = 0,
    B = 1,
    None = 2,
};
int d[SIZ][SIZ];
char X[SIZ];
char Y[SIZ];

int fun(){
    int m,n;
    m= strlen(X), n = strlen(Y);
    d[m][n] = 0; 
    d[m-1][n-1] = (X[m-1]==Y[n-1]?2:-1);
    int i,j,k,t;
    for(j=0;j<n-1;j++){
        d[m-1][j] = (X[m-1]==Y[j]?2:-1);
        d[m-1][j] -= 4 + n - 1 - j;
    }
    for(i=0;i<m-1;i++){
        d[i][n-1] = (X[i]==Y[n-1]?2:-1);
        d[i][n-1] -= 3 + m - i;
    }
    for(i=m-2;i>=0;i--){
        for(j=n-2;j>=0;j--){
            d[i][j] = d[i+1][j+1];
            for(k=i+2;k<m;k++){
                t = d[k][j+1] - 4 - (k-i-1);
                if(t>d[i][j]) {
                    d[i][j] = t;
                }
            }
            for(k=j+2;k<n;k++){
                t = d[i+1][k] - 4 - (k-j-1);
                if(t>d[i][j]) {
                    d[i][j] = t;
                }
            }
            d[i][j] += (X[i]==Y[j]?2:-1);
        }
    }
    int ans = d[0][0];
    for(i=1;i<m;i++){ // Y 前导-
        t = d[i][0] - 4 - i;
        if(t>ans) {
            ans = t;
        }
    }
    for(j=1;j<n;j++){// X 前导-
        t = d[0][j] -4 - j;
        if(t>ans) {
            ans = t;
        }
    }
    printf("%d\n",ans);
}

int main(){
    int tstcase;
    scanf("%d",&tstcase);
    while(tstcase--){
        scanf(" %s %s",X,Y);
        fun();
    }
    return 0;
}
