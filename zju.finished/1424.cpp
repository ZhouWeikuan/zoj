#include<iostream>
using namespace std;
enum {
    NUM = 16,
    SIZ = 1<<NUM,
};
struct Rect{
    int x0, x1, y0, y1, c;
};
int num;
unsigned step[SIZ];
bool nex[NUM][NUM];
int pre[NUM];
Rect r[NUM];

void dfs(unsigned stat, int pc){
    unsigned ns;
    int i, j;
    for(i=0; i<num; i++){
        if(pre[i] != 0) continue;
        ns = stat | (1<<i);
        if(step[ns] <= step[stat] + (pc!=r[i].c)) continue;
        step[ns] = step[stat] + (pc!=r[i].c);
        for(j=0; j<num; j++){
            pre[j] -= nex[i][j];
        }
        dfs(ns, r[i].c);
        for(j=0; j<num; j++){
            pre[j] += nex[i][j];
        }
    }
}
void fun(){
    memset(step, -1, sizeof(step));
    step[0] = 0;
    dfs(0, -1);
}

int cmp(const Rect&a,const Rect&b){
    if(a.x1<=b.x0 || a.x0 >= b.x1){
        return 0;
    }
    return a.y1 -  b.y1;
}
void readIn(){
    scanf("%d", &num);
    int i,j,t;
    for(i=0; i<num; i++){
        scanf("%d%d%d%d%d", &r[i].y0, &r[i].x0, &r[i].y1, &r[i].x1, &r[i].c);
    }
    memset(nex, false, sizeof(nex));
    memset(pre, 0, sizeof(pre));
    for(i=0; i<num; i++){
        for(j=i+1;j<num;j++){
            t = cmp(r[i], r[j]);
            if(t < 0){ // r[i] -> r[j]
                nex[i][j] = true;
                pre[j]++;
            } else if(t > 0){ // r[j] -> r[i]
                nex[j][i] = true;
                pre[i]++;
            }
        }
    }
}
int main(){
    int tst;
    scanf("%d",&tst);
    while(tst--){
        readIn();
        fun();
        printf("%u\n", step[(1<<num)-1]);
    }
    return 0;
}

