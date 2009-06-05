#include<iostream>
using namespace std;
enum {
    SIZ = 108,
    MaxN = -1,
};
// m[a][b]表示到目前为止，->时最后选择的为a,<-时最后选择的为b,
// 则max{a,b}前面的石子都已经被分配
// i > j 时
// m[i+1][j] 由 m[i][j] 更新而来
// m[i][i+1] 由 m[i][j] 更新而来
// m[j][i+1] 由 m[j][i] 更新而来
// m[i+1][i] 由 m[j][i] 更新而来
int n, s[SIZ];
int m[SIZ][SIZ];

int readIn(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    return n;
}
inline void update(int &lhs, int v){
    if(lhs==-1 || lhs > v) lhs = v;
}

int fun(){
    if(n == 2){
        return abs(s[0] - s[1]);
    }
    memset(m, MaxN, sizeof(m));
    m[0][0] = 0;
    m[1][0] = abs(s[1] - s[0]);
    m[0][1] = 0;
    for(int i=2;i<n-1;i++){
        for(int j=0; j<i-1;j++){ // m[i-1][j] m[j][i-1]
            update(m[i][j], abs(s[i]-s[i-1])+m[i-1][j]);
            update(m[i-1][i], m[i-1][j] + (j==0?(0):(abs(s[i]-s[j])))); 
            update(m[i][i-1], abs(s[i]-s[j])+m[j][i-1]);
            update(m[j][i], m[j][i-1] + abs(s[i]-s[i-1]) ); 
        }
    }
    int ret = -1;
    int t = s[n-1];
    int v = n - 2;
    for(int i=0; i< v;i++){
        update(ret, m[i][v] + abs(t - s[i]) + abs(t - s[v]) );
        update(ret, m[v][i] + (i==0?0:abs(t - s[i])) + abs(t - s[v]) );
    }

    return ret;
}

int main(){

    while(readIn() > 0){
        printf("%d\n",fun());
    }

    return 0;
}

