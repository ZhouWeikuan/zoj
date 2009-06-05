#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 752,
};
struct Point{
    int x,y;
};
struct Node {
    int v, a, b;
    bool operator<(const Node&rhs)const{
        return v > rhs.v;
    }
};
int num;
int par[SIZ];
Point town[SIZ];

int getPar(int a){
    int p = par[a];
    while(p != par[p]){
        p = par[p];
    }
    return par[a] = p;
}
int in_same(int a, int b){
    a = getPar(a); b = getPar(b);
    return (a == b);
}
void connect(int a, int b){
    a = getPar(a); b = getPar(b);
    if(a < b){
        par[b] = a;
    } else if(a > b){
        par[a] = b;
    } 
}
inline int getDis(int a, int b){
    return (town[a].x - town[b].x)*(town[a].x - town[b].x)
        + (town[a].y - town[b].y)*(town[a].y - town[b].y);
}
void fun(){
    int i, j;
    Node one;
    priority_queue<Node> q;
    for(i=0; i<num; i++){
        for(j=i+1; j<num; j++){
            if(!in_same(i, j)){
                one.v = getDis(i, j);
                one.a = i;
                one.b = j;
                q.push(one);
            }
        }
    }
    while(!q.empty()){
        one = q.top(); q.pop();
        if(in_same(one.a, one.b)){
            continue;
        }
        connect(one.a, one.b);
        printf("%d %d\n", one.a+1, one.b+1);
    }
}
void readIn(){
    int i, a, b;
    scanf("%d", &num);
    for(i=0; i<num; i++){
        par[i] = i;
        scanf("%d%d", &town[i].x, &town[i].y);
    }
    scanf("%d", &i);
    while(i--){
        scanf("%d%d",&a,&b);
        a--, b--;
        connect(a, b);
    }
}
int main(){
    int tst;
    scanf("%d", &tst);
    while(tst-- > 0){
        readIn();
        fun();
        if(tst){
            printf("\n");
        }
    }
    return 0;
}

