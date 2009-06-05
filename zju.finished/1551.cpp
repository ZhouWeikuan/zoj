#include<iostream>
using namespace std;
enum {
    SIZ = 108,
};
struct Point{
    int x,y;
};
int num;
Point tree[SIZ];
struct _cmp_x{
    bool operator()(const int&a, const int&b)const{
        if(tree[a].x != tree[b].x)
            return tree[a].x < tree[b].x;
        return tree[a].y<tree[b].y;
    }
}xc;
struct _cmp_y{
    bool operator()(const int&a, const int&b)const{
        if(tree[a].y != tree[b].y)
            return tree[a].y<tree[b].y;
        return tree[a].x < tree[b].x;
    }
}yc;
int W,H;
int x[SIZ];
int y[SIZ];
int wid;
Point o;

void fun(){
    int i,j,k;
    int gw, ow;// gw为以前离W的最大值,ow为当前x,y的最大值
    for(i=0; i<num; i++){
        if(i && tree[x[i]].x == tree[x[i-1]].x)
            continue;
        for(j=0; j<num; j++){ // tree[x[i]].x tree[y[i]].y
            if(j &&tree[y[j]].y==tree[y[j-1]].y)
                continue;
            gw = W - tree[x[i]].x;
            for(k=j+1; k<num; k++){
                if( tree[y[k]].y == tree[y[j]].y
                    ||tree[y[k]].x <= tree[x[i]].x
                    ||tree[y[k]].x > tree[x[i]].x + gw) continue;
                ow = min(gw, tree[y[k]].y-tree[y[j]].y);
                gw = min(gw, tree[y[k]].x-tree[x[i]].x);
                if(ow > wid){
                    wid = ow;
                    o.x = tree[x[i]].x;
                    o.y = tree[y[j]].y;
                }
            }
            ow = min(gw, H-tree[y[j]].y);
            if(ow > wid){
                wid = ow;
                o.x = tree[x[i]].x;
                o.y = tree[y[j]].y;
            }
        }
    }
    printf("%d %d %d\n", o.x, o.y, wid);
}
int readIn(){
    if(scanf("%d%d%d",&num,&W,&H)<0)
        return 0;
    for(int i=0; i<num; i++){
        scanf("%d%d",&tree[i].x, &tree[i].y);
        x[i] = y[i] = i;
    }
    tree[num].x = 0, tree[num].y = 0;
    x[num] = y[num] = num;
    num++;
    wid = o.x = o.y = 0;
    sort(x, x+num, xc);
    sort(y, y+num, yc);
    return 1;
}
int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

