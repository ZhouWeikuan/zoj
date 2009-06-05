#include<iostream>
#include<stack>
using namespace std;
// 先铺i行,再铺i+1行,只可能会影响到下一行
enum {
    SIZ = 4096,
};
struct Node{
    unsigned cur:12;
    unsigned nex:12;
    unsigned fir:4;  // first bit is zero
};
unsigned long long mat[12][12];
unsigned long long tab[2][SIZ]; 
unsigned long long *pre, *cur, *tmp;
int n, m;

// return true for bit p is 1, false other wise;
bool inline bittest(unsigned v, int p){
    return ((v>>p)&0x01);
}
bool inline check_duo(int s, int b){
    for(int i=0; i<b; i++){
        if(bittest(s, i)) continue;
        if(i==b-1 || bittest(s, i+1)){
            return false;
        } else {
            i++;
        }
    }
    return true;
}
int firstZero(unsigned v, int b){
    for(int i=0; i<b; i++){
        if(!bittest(v, i))
            return i;
    }
    return b;
}
long long query(int a, int b){
    int lim = (1<<b), i, j;
    Node one, non;
    pre = tab[0], cur = tab[1];
    for(i=0; i<lim; i++){
        pre[i] = check_duo(i, b);
    }
    for(j=1; j<a; j++){
        memset(cur, 0, sizeof(cur[0])*lim);
        for(i=0; i<lim; i++){
            cur[i] = 0;
            one.cur = i, one.nex = 0, one.fir = firstZero(i, b);
            stack<Node> s;
            s.push(one);
            while(!s.empty()){
                one = s.top(); s.pop();
                if(one.fir >= b){
                    cur[i] += pre[one.nex];
                } else {
                    // vertical
                    non.cur = one.cur | (1<<one.fir);
                    non.nex = one.nex | (1<<one.fir);
                    non.fir = firstZero(non.cur, b);
                    s.push(non);
                    // horizontal
                    if(one.fir < b-1 && !bittest(one.cur, one.fir+1)){
                        non.cur = one.cur | (0x3<<one.fir);
                        non.nex = one.nex;
                        non.fir = firstZero(non.cur, b);
                        s.push(non);
                    }
                }
            }
        }
        tmp = cur, cur = pre, pre = tmp;
    }
    return pre[0];
}
void init(){
    int i,j;
    for(i=1; i<12; i++){
        for(j=2; j<12; j+=2){
            if(mat[i][j] != 0) continue;
            mat[i][j] = mat[j][i] = query(i, j);
        }
    }
}

int main(){
    init();

    scanf("%d%d",&n,&m);
    while(n+m){
        printf("%llu\n", mat[n][m]);
        scanf("%d%d",&n,&m);
    }
    return 0;
}

