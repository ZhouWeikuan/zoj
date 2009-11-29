#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
enum {
    SIZ = 54,
    LEN = 9999,
    LIM = 0x7fffffff,
};
char line[LEN];
struct Node {
    int a, b, d;
    vector<pair<int, int> > door;
    void readIn(){
        char * del = " \t\n\r\f";
        door.clear();
        fgets(line, LEN, stdin);
        char *p = strtok(line, del);
        a = atoi(p);
        p = strtok(NULL, del);
        b = atoi(p);
        p = strtok(NULL, del);
        d = atoi(p);
        p = strtok(NULL, del);
        if (p){
            door.push_back(make_pair(-1, atoi(p)));
        } else {
            door.push_back(make_pair(-1, (int)LIM));
            return;
        }
        int a, b;
        while(p!=NULL){
            p = strtok(NULL, del);
            if (p == NULL) return;
            a = atoi(p);

            p = strtok(NULL, del);
            if (p == NULL) {
                b = LIM;
            } else {
                b = atoi(p);
            }
            door.push_back(make_pair(a, b));
        }
    }
    int getOther(int t){
        return (t==a?b:a);
    }
};

int N, M, S, T;
vector<int> nei[SIZ];
int vis[SIZ];
Node tree[SIZ*10];

int avail(int src, int cur, Node &o){
    for (int n=0; n < o.door.size(); ++n){
        pair<int, int> &p = o.door[n];
        if (cur + o.d <= p.second){
            int t = max(cur, p.first) + o.d;
            if (t <= p.second)
                return t;
        }
    }
    return -1;
}

struct vcmp {
    bool operator ()(int a, int b) const {
        if (vis[a] != vis[b])
            return vis[a]<vis[b];
        return a < b;
    }
};

int fun(){
    vis[S] = 0;
    set<int, vcmp> q;
    q.insert(S);
    while(!q.empty()){
        S = *q.begin(); q.erase(q.begin());
        if (S == T){
            return vis[S];
        }
        for (int m=0; m<nei[S].size(); ++m){
            Node &o=tree[nei[S][m]];
            int nex = o.getOther(S);
            int t = avail(S, vis[S], o);
            if (t>=0 && (vis[nex] < 0 || vis[nex] > t)){
                vis[nex] = t;
                q.insert(nex);
            }
        }
    }
    return -1;
}

int readIn(){
    scanf("%d%d%d%d ", &N, &M, &S, &T);
    if (N == 0) return 0;
    memset(vis, -1, sizeof(vis));
    for (int i=1; i<=N; ++i){
        nei[i].clear();
    }
    for (int i=0; i<M; ++i){
        tree[i].readIn();
        nei[tree[i].a].push_back(i);
        nei[tree[i].b].push_back(i);
    }

    return 1;
}

int main(){

    while(readIn() > 0){
        int t = fun();
        if (t < 0){
            printf("*\n");
        } else {
            printf("%d\n", t);
        }
    }

    return 0;
}

