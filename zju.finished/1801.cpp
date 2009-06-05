#include<iostream>
#include<cmath>

using namespace std;
enum {
	SIZ = 1000008,
    DAT = 300001,
};
struct Node{
    int fir; // first factor, 1 for prime
    int cnt; // current cnt for prime
    int pos; // position in use , 0 not used
};
Node tree[SIZ];
int pn;
int pl[80000] = {2};

void prList(){
    int i,j;
    pn = 1;
    bool stat;
    for(i=3; i<SIZ; i+=2){
        stat = true;
        for(j=0; pl[j]*pl[j]<=i;j++){
            if(i%pl[j]==0){
                stat = false;
                break;
            }
        }
        tree[i].pos = 0;
        tree[i].cnt = 1;
        if(stat){
            pl[pn++] = i;
            tree[i].fir = 1;
        } else {
            tree[i].fir = pl[j];
        }
    }
    //printf("prime size %d\n", pn);
}
void getPrList(int v){
    pn = -1;
    while(tree[v].fir != 1){
        if(tree[v].fir == 0)
            tree[v].fir = 2;
        if(pn<0||pl[pn]!=tree[v].fir)
            pl[++pn] = tree[v].fir;
        v /= tree[v].fir;
    }
    pl[++pn] = v;
    ++pn;
}
int genNext(int cur){
    getPrList(cur);
    int v=SIZ, t;
    for(int i=0; i<pn; i++){
        t = pl[i]*tree[pl[i]].cnt;
        while(t < SIZ && tree[t].pos){
            tree[pl[i]].cnt++;
            t = pl[i]*tree[pl[i]].cnt;
        }
        if(v>t){
            v = t;
        }
    }
    return v;
}
void init(){
    int num  = DAT - 3;
    int i;
    tree[0].pos = 0;
    tree[1].pos = 1;
    tree[2].pos = 2;
    tree[2].cnt = 1;
    tree[2].fir = 1;
    prList();
    int cur = 2;
    i = 2;
    while(num > 0 ){
        cur = genNext(cur);
        i++;
        //printf("%d\n", cur);
        if(cur < DAT){
            num--;
        }
        tree[cur].pos = i;
    }
}
int main(){
    int v;
	init();	
    scanf("%d", &v);
    while(v){
        printf("The number %d appears in location %d.\n",
                v,
                tree[v].pos);
        scanf("%d", &v);
    }
    return 0;
}
