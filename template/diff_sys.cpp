#include<cstdio>
#include<cstdlib>
#include<cstring>

// 差分系统
using namespace std;
enum {
    SIZ = 50004,
};
int d[SIZ];

struct Node {
    int l;
    int h;
    int c;
};
Node tree[SIZ];
int num;
int range;

int cmp(const Node * a, const Node * b){
    if(a->l == b->l)
        return a->h - b->h;
    return a->l - b->l;
}
int fun(){
    int flag = 1, i;
    int t, p;
    memset(d, 0, sizeof(int) * (range + 2));
    while( flag){
        flag = 0;
        for(i=0;i<num;i++){
            t = tree[i].h;
            p = d[tree[i].l] + tree[i].c;
            if(d[t] < p){
                d[t] = p;
                flag = 1;
            }
        }
        for(i=range;i>0;i--){
            if(d[i] > d[i-1] + 1){ // >号的差分，提升底部, <号的差分,降低高部
                d[i - 1] = d[i] - 1;
            }
        }
        for(i=1;i<=range;i++){
            if(d[i] < d[i-1]){
                d[i ] = d[i -1];
                flag = 1;
            } 
        }

    }

    return d[range] - d[0];
}

int main(){

    while(scanf("%d",&num) > 0){
        range = 0;
        for(int i=0;i<num;i++){
            scanf("%d%d%d",&tree[i].l, &tree[i].h, &tree[i].c);
            tree[i].l --;
            if(range < tree[i].h)
                range = tree[i].h;
        }
        qsort(tree, num, sizeof(Node),
                (int(*)(const void*,const void*)) cmp);
        printf("%d\n",fun());
    }
	return 0;
}
