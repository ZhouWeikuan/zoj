#include<iostream>
using namespace std;
enum {
    SIZ = 20008,
};
struct Node {
    int x, y;
    int used;
    bool operator < (const Node&rhs) const{
        if(x!=rhs.x)
            return x<rhs.x;
        return y<rhs.y;
    }
};
Node tree[SIZ];
int num;
int gx,gy;

int fun(){
    int i,j;
    gx = gy = 0;
    for(i=0;i<num;i++){
        scanf("%d%d",&tree[i].x, &tree[i].y);
        gx += tree[i].x;
        gy += tree[i].y;
        tree[i].used = 0;
    }
    if(num % 2 ==1){
        if(gx % num !=0 || gy %num !=0)
            return 0;
    }
    gx *= 2;
    gy *= 2;
    gx /= num;
    gy /= num;
    
    sort(tree, tree+num);
    Node one, *t;
    for(i=0;i<num;i++){
        if(tree[i].used == 1)
            continue;
        one.x = gx - tree[i].x;
        one.y = gy - tree[i].y;
        t = lower_bound(tree+i, tree+num, one);
        if(t == tree+num || t->x != one.x || t->y != one.y){
            return 0;
        }
        tree[i].used = 1;
        t->used = 1;
    }
    return 1;
}

int main(){
    scanf("%d",&num);
    while(num > 0){
        if(fun() == 0){
            printf("This is a dangerous situation!\n");
        } else {
            double a = gx, b = gy;
            printf("V.I.P. should stay at (%.1lf,%.1lf).\n", a/2, b/2);
        }
        scanf("%d",&num);
    }
    return 0;
}
