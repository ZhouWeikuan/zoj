#include<iostream>
#include<queue>

using namespace std;
enum {
    SIZ = 108,
};
struct Node {
    int dis, val, used;
    int n;
    int no[SIZ];
};
int num;
Node tree[SIZ];
void readIn(){
    int i,j,t,p;
    for(i=0;i<num;i++){
        tree[i].used = 0;
    }
    for(i=0;i<num;i++){
        scanf("%d%d", &tree[i].val, &p);
        tree[i].n = p;
        for(j=0;j<p;j++){
            scanf("%d",&t);
            t --;
            tree[i].no[j] = t;
        }
        tree[i].dis = -SIZ;
    }
}

int reach(int s){
    static char mask[SIZ];
    for(int i=0;i<num;i++){
        mask[i] = 0;
    }
    queue<int> q;
    mask[s] = 1;
    q.push(s);
    while(!q.empty()){
        int o= q.front(); q.pop();
        for(int i=0;i<tree[o].n;i++){
            int t = tree[o].no[i];
            if(mask[t] ==0 ){
                mask[t] = 1;
                q.push(t);
            }
        }
    }
    return mask[num-1];
}

int fun(){
    if(!reach(0)){
        return 0;
    }
    tree[0].dis = 100;
    tree[0].used = 1;
    queue<int> q;
    q.push(0);
    int o,t,i,v;
    int count = 0;
    int lim = (num-1)*num/2;
    while(!q.empty()){
        o = q.front(); q.pop();
        count ++;
        tree[o].used = 0;
        if(o == num-1){
            break;
        }
        for(i=0;i<tree[o].n;i++){
            t = tree[o].no[i];
            v = tree[o].dis + tree[t].val;
            if(v <= 0 || v <= tree[t].dis)
                continue;
            if(count <= lim){
                tree[t].dis = v;
                if(tree[t].used == 0){
                    q.push(t);
                    tree[t].used = 1;
                }
            } else if(reach(t)){
                // positive circle, but what if not on the road?
                return 1;
            } else { // forbid to access this again
                tree[t].dis = 99999999;
                tree[t].used = 1;
            }
        }
    }
    
    return tree[num-1].dis > 0;
}

int main(){
    
    scanf("%d",&num);
    while(num > 0){
        readIn();
        if(fun()){
            printf("winnable\n");
        } else {
            printf("hopeless\n");
        }
        scanf("%d",&num);
    }

    return 0;
}
