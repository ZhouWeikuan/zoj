#include<iostream>
using namespace std;
enum {
    SIZ = 10,
};
struct Point {
    unsigned r:8;
    unsigned c:8;
    unsigned v:16;
};
int num;
Point blk[SIZ*SIZ];
char cell[SIZ][SIZ];
bool row[SIZ][SIZ];
bool col[SIZ][SIZ];
bool mat[SIZ][SIZ];

inline int getMat(int r, int c){
    return (r)/3*3 + (c)/3;
}
bool match(int n){
    return row[blk[n].r][blk[n].v]==false
        &&col[blk[n].c][blk[n].v]==false
        &&mat[getMat(blk[n].r, blk[n].c)][blk[n].v]==false;
}
void append(int n){
    row[blk[n].r][blk[n].v]=true;
    col[blk[n].c][blk[n].v]=true;
    mat[getMat(blk[n].r, blk[n].c)][blk[n].v]=true;
}
void remove(int n){
    row[blk[n].r][blk[n].v]=false;
    col[blk[n].c][blk[n].v]=false;
    mat[getMat(blk[n].r, blk[n].c)][blk[n].v]=false;
}
void fun(){
    int cur = 0;
    int i,j;
    blk[cur].v = 10;
    while(cur < num){
        blk[cur].v--;
        while(blk[cur].v>0 && !match(cur)){
            blk[cur].v --;
        }
        if(blk[cur].v <= 0){
            --cur;
            remove(cur);
        } else {
            append(cur);
            ++cur;
            blk[cur].v = 10;
        }
    }
    for(i=0; i<num; i++){
        cell[blk[i].r][blk[i].c] = blk[i].v;
    }
    for(i=0; i<9; i++){
        for(j=0;j<9;j++){
            cell[i][j] += '0';
        }
        printf("%s\n", cell[i]);
    }
}

void readIn(){
    int i,j;
    memset(row,false,sizeof(row));
    memset(col,false,sizeof(col));
    memset(mat,false,sizeof(mat));
    num = 0;
    for(i=0; i<9; i++){
        scanf("%s", cell[i]);
        for(j=0;j<9;j++){
            cell[i][j] -= '0';
            if(cell[i][j] == 0){
                blk[num].r = i;
                blk[num].c = j;
                num++;
            } else {
                row[i][cell[i][j]] = true;
                col[j][cell[i][j]] = true;
                mat[getMat(i,j)][cell[i][j]] = true;
            }
        }
    }
}
int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst--){
        readIn();
        fun();
    }
    return 0;
}

