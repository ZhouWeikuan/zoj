#include<iostream>
#include<cmath>
using namespace std;
// 这个是minimum range query的二维版，使用四叉树速度会更快。
// 使用sqrt()的方法刚刚过
enum {
    SIZ = 308,
    SUB = 20,
    MaxN= 999999999,
};
struct Point{
    int x,y;
};
int num, sqr;
int r1,c1,r2,c2;
int dat[SIZ][SIZ];
int mat[SUB][SUB]; 

void inline update(int &t, int v){
    if(v < t) t = v;
}
void readIn(){
    int i,j, t;
    scanf("%d",&num);
    sqr = (int)sqrt((double)num);
    for(i=0;i<num;i++){
        t = (i%sqr==0);
        for(j=0;j<num;j++){
            scanf("%d",&dat[i][j]);
            if(t&&j%sqr==0){
                mat[i/sqr][j/sqr] = dat[i][j];
            } else {
                update(mat[i/sqr][j/sqr], dat[i][j]);
            }
        }
    }
}
int check(int a, int b){
    int i = a*sqr, j =b*sqr;
    int m = i + sqr, n = j + sqr;
    if(r1<=i&&m<=r2 && c1<=j&&n<=c2){
        return mat[a][b];
    }
    i = max(i,r1);
    j = max(j,c1);
    m = min(m,r2);
    n = min(n,c2);
    a = MaxN;
    for(; i<m;i++){
        for(b=j;b<n;b++){
            update(a, dat[i][b]);
        }
    }
    return a;
}
void query(){
    int x1,y1,x2,y2, v = MaxN;
    int j,t;
    x1 = r1/sqr, x2 = r2/sqr;
    y1 = c1/sqr, y2 = c2/sqr;
    for(;x1<=x2;x1++){
        for(j=y1;j<=y2;j++){
            t = check(x1, j);
            update(v, t);
        }
    }
    printf("%d\n",v);
}

void fun(){
    int op;
    scanf("%d", &op);
    while(op--){
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        r1--,c1--;
        query();
    }
}

int main(){
    int tstcase;
    scanf("%d",&tstcase);
    while(tstcase --){
        readIn();
        fun();
    }
    return 0;
}

