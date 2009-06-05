#include<iostream>
#include<queue>
#include<set>
using namespace std;
enum {
    SIZ = 504,
};
int num;
int pos, sav;
unsigned mat[SIZ][SIZ];
unsigned dis[SIZ];
unsigned nd[SIZ];

unsigned test(int i){
    int v;
    unsigned d;
    queue<int> q;
    set<int> s;
    nd[i] = 0;
    q.push(i); s.insert(i);
    while(!q.empty()){
        i = q.front(); q.pop();
        s.erase(i);
        for(v=1; v<=num; v++){
            if(mat[i][v] == -1) continue;
            d = nd[i] + mat[i][v];
            if(nd[v] > d){
                nd[v] = d;
                if(s.find(v) == s.end()){
                    s.insert(v);
                    q.push(v);
                }
            }
        }
    }
    unsigned ret = 0;
    for(i=1; i<=num; i++){
        if(ret < nd[i]) ret = nd[i];
    }
    return ret;
}
void fun(){
    int i, p;
    unsigned t;
    sav = 0;
    for(i=1; i<=num; i++){
        if(sav < dis[i])
            sav = dis[i];
    }
    p = -1;
    for(i=1; i<=num; i++){
        if(dis[i] == 0) continue;
        memcpy(nd, dis, sizeof(int)*(num+4));
        t = test(i);
        if(sav > t){
            sav = t;
            p = i;
        }
    }
    sav = p;
    if(sav == -1){
        sav = 0;
    }
}

void readIn(){
    int i,a,b,d;
    static char buf[SIZ];
    queue<int> q;
    set<int> tab;
    memset(mat, -1, sizeof(mat));
    memset(dis, -1, sizeof(dis));
    for(i=0; i<pos; i++){
        scanf("%d ", &a);
        dis[a] = 0;
        tab.insert(a);
        q.push(a);
    }
    for(; fgets(buf, SIZ, stdin)!=NULL&&buf[0]!='\n'; ){
        sscanf(buf, "%d%d%d", &a, &b, &d);
        mat[a][b] = mat[b][a] = d;
    }
    while(!q.empty()){
        i = q.front(); q.pop();
        tab.erase(i);
        for(a=1; a<=num; a++){
            if(mat[i][a] == -1) continue;
            d = dis[i] + mat[i][a];
            if(dis[a] > d){
                dis[a] = d;
                if(tab.find(a) == tab.end()){
                    tab.insert(a);
                    q.push(a);
                }
            }
        }
    }
}

int main(){
    while(scanf("%u%d", &pos, &num)>0){
        readIn();
        fun();
        printf("%u\n", sav);
    }
    return 0;
}

