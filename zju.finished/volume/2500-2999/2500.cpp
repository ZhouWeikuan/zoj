#include<cstdio>
#include<cstring>

using namespace std;
enum {
    SIZ = 104,
};
struct Node {
    int dn;
    int up;
};

Node tree[SIZ];
int mat[SIZ][SIZ];
int N,M;

void gen(){
    int flag = 1;
    int i,j,k;
    while(flag){
        flag = 0;
        for(k=1;k<=N;k++){
            for(i=1;i<=N;i++){
                if(mat[i][k] == 0)
                    continue;
                for(j=1;j<=N;j++){
                    if(mat[k][j]== 0 || mat[i][j]!=0)
                        continue;
                    if(mat[i][k] == 1 && mat[k][j]==1){
                        mat[i][j] = 1;
                        flag ++;
                    }
                    if(mat[i][k] == -1 && mat[k][j]==-1){
                        mat[i][j] = -1;
                        flag ++;
                    }
                }
            }
        }
    }
    for(i=1; i<=N;i++){
        tree[i].dn = tree[i].up = 0;
        for(j=1;j<=N;j++){
            if(mat[i][j] == 1){
                tree[i].dn ++;
            } else if(mat[i][j] ==-1){
                tree[i].up ++;
            }
        }
    }
}

void fun(){
    int a,b;
    memset(mat, 0, sizeof(mat));
    while(M --){
        scanf("%d %d ", &a, &b);
        mat[a][b] = 1;
        mat[b][a] = -1;
    }
    gen();
    int lim = N/2;
    b = 0;
    for(a=1;a<=N;a++){
        if(tree[a].up > lim || tree[a].dn>lim){
            b++;
        }
    }
    printf("%d\n", b);
}

int main(){
    int tstcase;
    scanf("%d ", &tstcase);
    while(tstcase --){
        scanf("%d %d ", &N, &M);
        fun();
    }
	return 0;
}
