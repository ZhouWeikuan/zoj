#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 10008,
};
struct Node {
    int a,b; // cpu & memory
    int t,u; // arrive & timeline
    int v,w,x; // reward, bonus, punishment
    int fin;  // time for finished;

    bool operator < (const Node& rhs)const{
        if(t != rhs.t) return t < rhs.t;
        return v > rhs.v;
    }
};
int num;
Node tree[SIZ];
int F, M, N;  // timeline, cpu & memory;
int sus[SIZ], sl;
int run[SIZ], rl;
int wl;

int fun(){
    int cur, i, score = 0, t, p;
    sl = rl = wl = 0;
    for(cur=0; cur<F; cur++){
        while(rl > 0){
            t  = run[--rl];
            M += tree[t].a;
            N += tree[t].b;
            // calc score.
            score += tree[t].v;
            if(cur <= tree[t].u){
                score += (tree[t].u - cur) * tree[t].w;
            } else {
                score -= (cur - tree[t].u) * tree[t].x;
            }
        }
        p = 0;
        for( i=0; i<sl; i++){
            t = sus[i];
            if(M >= tree[t].a && N >= tree[t].b){
                M -= tree[t].a;
                N -= tree[t].b;
                run[rl++] = t;
            } else {
                sus[p++] = sus[i];
            }
        }
        sl = p;
        while(wl < num) {
            t = wl;
            if(tree[t].t > cur)
                break;
            if(M >= tree[t].a && N >= tree[t].b){
                M -= tree[t].a;
                N -= tree[t].b;
                run[rl++] = t;
                wl++;
            } else {
                sus[sl++] = t;
                wl++;
                //break;
            }
        }
    }
    while(rl>0){
        t  = run[--rl];
        M += tree[t].a;
        N += tree[t].b;
        // calc score.
        score += tree[t].v;
        if(cur <= tree[t].u){
            score += (tree[t].u - cur) * tree[t].w;
        } else {
            score -= (cur - tree[t].u) * tree[t].x;
        }
    }
    rl = 0;
    for(i=0; i<sl; i++){
        t = sus[i];
        if(cur < tree[t].u)
            continue;
        score -= (cur - tree[t].u) * tree[t].x;
    }
    while(wl < num){
        t = wl++;
        if(cur < tree[t].u)
            continue;
        score -= (cur - tree[t].u) * tree[t].x;
    }

    return score;
}

int readIn(){
    scanf("%d",&F);
    if(F==0) return 0;
    scanf("%d%d%d",&M, &N, &num);
    for(int i=0; i<num; i++){
        scanf("%d%d%d%d%d%d%d", &tree[i].a, &tree[i].b, &tree[i].t, &tree[i].u,
                &tree[i].v, &tree[i].w, &tree[i].x);
        tree[i].fin = 0;
    }
    sort(tree, tree+num);
    return F;
}
int main(){
    int tst=0;
    while( readIn() > 0){
        printf("Case %d: %d\n\n", ++tst, fun());
    }
    return 0;
}

