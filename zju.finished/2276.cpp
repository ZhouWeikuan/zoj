#include<iostream>
#include<queue>
using namespace std;
// Dijkstra 求最短路径
enum {
    SIZ = 104,
    MaxVal = 99999999,
};
struct Node {
    int next[2];
};
Node tree[SIZ];
int tab[2][SIZ];
int num;

void dijkstra(int s, int *dis){
    queue<int> q;
    q.push(s);
    int n;
    while(!q.empty()){
        s = q.front(); q.pop();
        for(int i=0;i<2;i++){
            n = tree[s].next[i];
            if(dis[n] > dis[s] + 1){
                dis[n] = dis[s] + 1;
                q.push(n);
            }
        }
    }
}
void fun(){
    int i, t;
    for(i=0; i<num; i++){
        scanf("%d",&t);
        tree[i].next[0] = (i-t+num)%num;
        tree[i].next[1] = (i+t)%num;
        tab[0][i] = tab[1][i] = MaxVal;
    }
    for(i=0;i<2;i++){
        scanf("%d",&t);
        tab[i][t] = 0;
        dijkstra(t, tab[i]);
    }
    int val = MaxVal;
    for(i=0; i<num; i++){
        t = tab[0][i] + tab[1][i];
        if(t < val){
            val = t;
        }
    }
    if(val >= MaxVal){
        printf("Lara is traped!\n");
    } else {
        printf("open it on the %dth move!\n", val);
    }
}

int main(){
    scanf("%d", &num);
    while(num > 0){
        fun();
        scanf("%d", &num);
    }
    return 0;
}

