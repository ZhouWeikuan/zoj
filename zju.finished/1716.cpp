#include<cstdio>
#include<cstring>

using namespace std;
struct Node {
    int mark;
    int s;
};
enum {
    SIZ = 104,
};
Node tree[SIZ][SIZ];
int W,H;
int S,T;
int num;

void readIn(){
    int i,j;
    scanf("%d%d",&W,&H);
    memset(tree, 0, sizeof(tree));
    for(int k=0;k<num;k++){
        scanf("%d%d",&i,&j);
        i--,j--;
        tree[i][j].mark = 1;
    }
    scanf("%d%d",&S,&T);
}
void init(){
    int i,j;
    for(i=0;i<W;i++){
        for(j=0;j<H;j++){
            tree[i][j].s = tree[i][j].mark;
            if(i > 0)
                tree[i][j].s += tree[i-1][j].s;
            if(j > 0) 
                tree[i][j].s += tree[i][j-1].s;
            if(i>0 && j>0)
                tree[i][j].s -= tree[i-1][j-1].s;
        }
    }
}

int calc(int a, int b){
    int ret = tree[a+S-1][b+T-1].s; 
    if(b > 0)
        ret -= tree[a+S-1][b-1].s;
    if(a > 0)
        ret -= tree[a-1][b+T-1].s;
    if(a>0 && b>0)
        ret += tree[a-1][b-1].s;
    return ret;
}

int fun(){
    int i,j,t;
    init();
    int val = 0;
    for(i=0;i+S<=W;i++){
        for(j=0;j+T<=H;j++){
            t =  calc(i,j);
            if(t > val)
                val = t;
        }
    }

    return val;
}

int main(){

    scanf("%d",&num);
    while(num > 0){
        readIn();
        printf("%d\n", fun());
        scanf("%d",&num);
    }

	return 0;
}
