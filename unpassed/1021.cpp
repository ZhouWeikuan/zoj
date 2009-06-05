#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 20,
};
struct Node {
    int x, l, h;
    int n;
    int p[SIZ];
    int y[SIZ];
};
int num, lvl, res;
Node tube[SIZ];
bool use[SIZ];

void dfs(int s){
    if(use[s]||res==-1) return;
    use[s] = true;
    if(lvl <= tube[s].l){
        res = -1; 
        return;
    }
    if(lvl <= tube[s].h){
        res += tube[s].h - lvl;
    }
    for(int i=0; i<tube[s].n; i++){
        if(tube[s].y[i] >= lvl){
            dfs(tube[s].p[i]);
        }
    }
}
int getTube(int x){
    for(int i=0; i<num; i++){
        if(x == tube[i].x)
            return i;
    }
    return -1;
}
void fun(){
    int s;
    memset(use, false, sizeof(use));
    scanf("%d%d", &s, &lvl);
    res = 0;
    --s;
    
    if(lvl > tube[s].h)
        res = -1;
    else{
        for(s=0; s<num; s++){
            if(lvl <= tube[s].l){
                res = -1;break;
            } else if(lvl < tube[s].h){
                res += tube[s].h - lvl;
            }
        }
        //dfs(s);
    }
    
    if(res == -1){
        printf("No Solution\n");
    } else {
        printf("%d\n", res);
    }
}
void readIn(){
    int i;
    scanf("%d", &num);
    for(i=0; i<num; i++){
        scanf("%d%d%d", &tube[i].x, &tube[i].l, &tube[i].h);
        tube[i].h += tube[i].l;
        tube[i].n = 0;
    }
    int a, b, y;
    scanf("%d",&i);
    while(i--){
        scanf("%d%d%d",&a,&y,&b);
        b += a;
        a--;
        a = getTube(a);
        b = getTube(b);
        if(a < 0 || b < 0) 
            continue;
        tube[a].p[tube[a].n] = b;
        tube[a].y[tube[a].n] = y;
        tube[b].p[tube[b].n] = a;
        tube[b].y[tube[b].n] = y;
        tube[a].n++;
        tube[b].n++;
    }
}
int main(){
    int tst;
    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
    }
    return 0;
}

