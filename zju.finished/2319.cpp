#include<iostream>
using namespace std;
enum {
    SIZ = 100008,
};

struct Member{
    int s,v,loc,ptr;
    bool operator<(const Member &rhs) const {
        if(s != rhs.s){
            return s <rhs.s;
        }
        return v > rhs.v;
    }
};
Member tree[SIZ];
int    club[SIZ];
int    pos[SIZ];
int tn,cn;

void readIn(){
    scanf("%d", &tn);
    for(int i=0; i<tn; i++){
        scanf("%d%d", &tree[i].s, &tree[i].v);
        tree[i].loc = i + 1;
        tree[i].ptr = -1;
    }
    sort(tree, tree+tn);
}

void update(int cur){
    int low = 0, high = cn, mid;
    const Member &m = tree[cur];
    while(low < high){
        mid = (low+high)/2;
        if(tree[club[mid]].v < m.v ){
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    while(mid>0 && tree[club[mid]].v >= m.v){
        mid--;
    }
    while(mid<cn-1 && tree[club[mid]].v <= m.v){
        mid++;
    }
    if(mid == 0 || (tree[club[mid-1]].v < m.v && tree[club[mid-1]].s < m.s) ){
        club[mid] = cur;
        if(mid != 0){
            tree[cur].ptr = club[mid-1];
        } 
    }
}

void trace(){
    int t = 0;
    printf("%d\n", cn);
    cn--;
    pos[t++] = tree[club[cn]].loc;
    int ptr = tree[club[cn]].ptr;
    while(ptr >= 0){
        pos[t++] = tree[ptr].loc;
        ptr = tree[ptr].ptr;
    }
    --t;
    printf("%d", pos[t]);
    while(--t >= 0){
        printf(" %d", pos[t]);
    }
    printf("\n");
}

void fun(){
    cn = 1;
    club[0] = 0;
    for(int i=1;i<tn;i++){
        if(tree[i].v > tree[club[cn-1]].v && tree[i].s > tree[club[cn-1]].s){
            club[cn] = i;
            tree[i].ptr = club[cn-1];
            cn++;
        } else {
            update(i);
        }
    }
    trace();
}
int main(){
    int tstcase;

    scanf("%d", &tstcase);
    while(tstcase-- > 0){
        readIn();
        fun();
        if(tstcase){
            printf("\n");
        }
    }

    return 0;
}
