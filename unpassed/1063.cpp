#include<iostream>
using namespace std;
// Wrong answer
enum {
    SIZ = 60,
    MRK = 10000,
};
int move[6][3] = {
    {-1, 0, 0}, {1, 0, 0},
    {0, -1, 0}, {0, 1, 0},
    {0, 0, -1}, {0, 0, 1}
};
int N, M, K, l, F;
int m[SIZ][SIZ][SIZ];
int i,j,k,t;
bool valid(int a, int b, int c){
    return (a>=0&&a<K)&&(b>=0&&b<M)&&(c>=0&&c<N);
}
int path(int a, int b, int c){
    int na,nb,nc;
    m[a][b][c] = MRK;
    for(int i=0; i<6; i++){
        na = a + move[i][0];
        nb = b + move[i][1];
        nc = c + move[i][2];
        if(!valid(na,nb,nc) || (m[na][nb][nc]==-1&&path(na, nb, nc) ==1)){
            return 1;
        }
    }
    return 0;
}
void flood(int a, int b, int c, int v){
    int na, nb, nc;
    m[a][b][c] = v;
    for(int i=0; i<6; i++){
        na = a + move[i][0];
        nb = b + move[i][1];
        nc = c + move[i][2];
        if(!valid(na,nb,nc)){
            continue;
        }
        if(m[na][nb][nc]==MRK){
            m[na][nb][nc] = v;
            flood(na, nb, nc, v);
        }
    }
}
void fun(){
    int face = 0;
    for(i=0; i<K; i++){
        for(j=0; j<M; j++){
            for(k=0; k<N; k++){
                if(m[i][j][k] == -1){
                    if(path(i,j,k) == 1){
                        flood(i,j,k, 1);
                    } else {
                        flood(i,j,k, 0);
                    }
                }
            }
        }
    }
    for(i=0; i<K; i++){
        for(j=0; j<M; j++){
            for(k=0; k<N; k++){
                if(m[i][j][k] != 0) continue;
                face += 6;
                if(i!=0&&m[i-1][j][k]==0){//down
                    face--;
                }
                if(i!=K-1&&m[i+1][j][k] ==0){// up
                    face--;
                }
                if(j!=0&&m[i][j-1][k]==0){ //front
                    face--;
                }
                if(j!=M-1&&m[i][j+1][k]==0){ //back
                    face--;
                }
                if(k!=0&&m[i][j][k-1]==0){ // left
                    face--;
                }
                if(k!=N-1&&m[i][j][k+1]==0){ // right
                    face--;
                }
            }
        }
    }
    printf("The number of faces needing shielding is %d.\n", face);
}
int readIn(){
    scanf("%d%d%d%d",&N,&M,&K,&l);
    if(N + M + K + l ==0) return 0;
    memset(m, -1, sizeof(m));
    F = N * M;
    for(;l>0;l--){
        scanf("%d", &t);
        i = t/F;  t %= F;
        j = t/N;  t %= N;
        m[i][j][t] = 0;
    }
    return 1;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

