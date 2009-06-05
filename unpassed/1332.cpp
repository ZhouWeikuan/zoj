#include<iostream>
using namespace std;
enum {
    SIZ = 4,
    NUM = 6,
};
struct Matrix {
    int wid, hei;
    char m[SIZ][SIZ];
};
int num, pos;
Matrix mat[NUM];
char puz[SIZ][SIZ];
bool mark[NUM];

void disclose(int r, int c, const Matrix &m){
    int i,j;
    for(i=0; i<m.hei; i++){
        for(j=0; j<m.wid; j++){
            if(m.m[i][j] == puz[r+i][c+j]){
                puz[r+i][c+j] = '0';
            }
        }
    }
}

bool cover(int r, int c, const Matrix &m){
    if(r + m.hei > SIZ){
        return false;
    }
    int i,j;
    bool flag=false;
    j=0;
    while(m.m[0][j] == '0'){
        j++;
        if(--c < 0)
            return false;
    }
    for(i=0; i<m.hei; i++){
        for(j=0; j<m.wid; j++){
            if(m.m[i][j] != '0'){
                if(puz[r+i][c+j] != '0'){
                    flag = true;
                } else {
                    puz[r+i][c+j] = m.m[i][j];
                }
            }
        }
    }
    if(flag){
        disclose(r, c, m);
        return false;
    }
    return true;
}
bool dfs(int r){
    if(r == 0) return true;
    int i,j,k;
    for(i=0; i<SIZ; i++){
        for(j=0; j<SIZ; j++){
            if(puz[i][j] == '0')
                goto end;
        }
    }
    return false;
end:
    for(k=0; k<num; k++){
        if(mark[k] == false){
            mark[k] = true;
            if(cover(i,j,mat[k]) && dfs(r-1)){
                return true;
            }
            disclose(i,j,mat[k]);
            mark[k] = false;
        }
    }
    return false;
}
void output(){
    for(int i=0; i<SIZ; i++){
        for(int j=0; j<SIZ; j++){
            printf("%c", puz[i][j]);
        }
        printf("\n");
    }
}
void fun(){
    memset(mark, false, sizeof(mark));
    memset(puz, '0', sizeof(puz));
    if(pos!=SIZ*SIZ || dfs(num) ==false){
        printf("No solution possible\n");
    } else {
        output();
    }
}
int readIn(){
    scanf("%d", &num);
    int i,j,k;
    pos = 0;
    for(i=0; i<num; i++){
        scanf("%d%d",&mat[i].hei, &mat[i].wid);
        for(j=0; j<mat[i].hei; j++){
            scanf("%s", mat[i].m[j]);
            for(k=0; mat[i].m[j][k]; k++){
                if(mat[i].m[j][k] == '1'){
                    mat[i].m[j][k] = '1' + i;
                    pos++;
                }
            }
        }
    }
    return num;
}
int main(){
    int tst=0;
    while(readIn() > 0){
        if(tst++) printf("\n");
        fun();
    }
    return 0;
}

