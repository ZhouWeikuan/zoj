#include<cstdio>

using namespace std;
enum {
    SIZ = 1504,
    NZ = 12,
};
struct Node {
    int parent;
    int used;
    int pos;
    int ptr[NZ];
};
Node tree[SIZ];
int num, root;
void readIn(){
    int i, t, a ,b;
    for(i=0;i<num;i++){
        tree[i].parent = i;
    }
    for(i=0;i<num;i++){
        scanf("%d:(%d) ", &a, &t);
        tree[a].pos = 0;
        while( t --){
            scanf("%d ", &b);
            tree[a].ptr[tree[a].pos ++] = b;
            tree[b].parent = a;
        }
    }
    root = 0;
    while(root != tree[root].parent){
        root = tree[root].parent;
    }
}

int calc(int cur) {
    if(tree[cur].pos ==0){
        tree[cur].used = 0;
        return 0;
    }
    int ret, i, usednum, s;
    ret = usednum = 0;
    for(i=0; i<tree[cur].pos; i++){
        s = tree[cur].ptr[i];
        ret += calc(s);
        usednum += tree[s].used;
    }
    if( usednum < tree[cur].pos){
        tree[cur].used = 1;
        ret ++;
    } else {
        tree[cur].used = 0;
    }

    return ret;
}

int fun(){
    int ans = calc(root);
    return ans;
}

int main(){

    while(scanf("%d ", &num) > 0){
        readIn();
        printf("%d\n", fun());
    }
	return 0;
}
