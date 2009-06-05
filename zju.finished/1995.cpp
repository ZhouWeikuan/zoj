#include<iostream>

// dp,以高度为标志
using namespace std;
enum {
    SIZ = 1008,
    Range = 508,
};
struct Node {
    int update;
    int flag ;
    int opt ;
};
Node tree[SIZ][Range];
char buf[SIZ];
int dat[SIZ];
int num, lim;
int tstcase;

int readIn(){
    lim = 0;
    scanf("%d", &num);
    for(int i=0;i<num;i++){
        scanf("%d", &dat[i]);
        lim += dat[i];
    }
    if(lim %2 )
        return 0;
    lim /= 2;
    return 1;
}

void calc(){
    int i,j, s;
    int nop;
    tree[0][0].update = tstcase;
    tree[0][0].opt    = 0;
    for(i=0;i<num;i++){
        for(j=0;j<=lim;j++){
            if(tree[i][j].update < tstcase)
                continue;
            s = j + dat[i];
            if(s <= lim ){
                nop = s > tree[i][j].opt?s:tree[i][j].opt;
                if(tree[i+1][s].update < tstcase 
                        || nop < tree[i+1][s].opt){
                    tree[i+1][s].update = tstcase;
                    tree[i+1][s].flag = 1;
                    tree[i+1][s].opt = nop;
                }
            }

            s = j - dat[i];
            if(s >= 0){
                nop = tree[i][j].opt;
                if(tree[i+1][s].update < tstcase 
                        || nop < tree[i+1][s].opt ){
                    tree[i+1][s].update = tstcase;
                    tree[i+1][s].flag = 0;
                    tree[i+1][s].opt  = nop;
                }
            }
        }
    }
}

void backtrace(){
    buf[num] = 0;
    int s = 0, i;
    for(i=num;i>0;i--){
        if(tree[i][s].flag == 1){
            buf[i-1] = 'U';
            s -= dat[i-1];
        } else {
            buf[i-1] = 'D';
            s += dat[i-1];
        }
    }
    printf("%s\n", buf);
}

void fun(){
    if( readIn() == 0){
        printf("IMPOSSIBLE\n");
        return;
    }
    calc();
    if(tree[num][0].update < tstcase){
        printf("IMPOSSIBLE\n");
        return;
    }
    backtrace();
}

int main(){
    int tstnum;
    tstcase = 0;
    scanf("%d", &tstnum);
    while(tstcase ++ < tstnum){
        fun();
    }

	return 0;
}
