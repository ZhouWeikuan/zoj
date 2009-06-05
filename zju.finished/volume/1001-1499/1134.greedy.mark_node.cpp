#include<cstdio>
/*
终于知道自己错的原因了，这题要求是所有边中两点至少有一点被标记
而我写的程序实现的却是：所有点，要么被标记，要么与被标记的点有边直接相连
所以n=1时，结果是0,我还以为你一开始没考虑到...
 */
using namespace std;
enum {
    SIZ = 1504,
    NZ = 12,
};
struct Node {
    int parent;
    int refer, used;
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
        tree[cur].refer = tree[cur].used = 0;
        return 0;
    }
    int ret, i, usednum, refernum, s;
    ret = usednum = refernum = 0;
    for(i=0; i<tree[cur].pos; i++){
        s = tree[cur].ptr[i];
        ret += calc(s);
        usednum += tree[s].used;
        refernum += tree[s].refer;
    }
    if(refernum < tree[cur].pos){
        tree[cur].refer = tree[cur].used = 1;
        ret ++;
    } else if(usednum > 0){
        tree[cur].used = 0;
        tree[cur].refer = 1;
    } else {
        tree[cur].used = tree[cur].refer = 0;
    }

    return ret;
}

int fun(){
    int ans = calc(root);
    if(tree[root].refer == 0)
        ans ++;
    return ans;
}

int main(){

    while(scanf("%d ", &num) > 0){
        readIn();
        printf("%d\n", fun());
    }
	return 0;
}
