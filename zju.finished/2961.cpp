#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
using namespace std;
enum {
    LIM = 1000000,
    SIZ = 104,
};

int D, N, src, dst;
unsigned vis[LIM];
unsigned pre[LIM];
vector<string> btn;
int unit[] = {1, 10, 100, 1000, 10000, 100000, 1000000};


inline int updatePos(int v, int p, int nv){
    return (v/unit[p+1]*unit[p+1]) + (v%unit[p]) + (nv*unit[p]);
}

int inline getPos(int v, int p){
    return (v/unit[p])%10;
}

int makeNext(int cur, const string&s){
    int i, v;
    for (i=0; i<D; ++i){
        v = getPos(cur, D-i-1);
        v += s[i] - '0';
        v %= 10;
        cur = updatePos(cur, D-i-1, v);
    }
    return cur;
}

void fun(){
    if (src == dst){
        printf("0\n"); return;
    }
    pre[src] = src; vis[src] = SIZ;
    queue<int> q; q.push(src);
    int nex, i;
    while(!q.empty()){
        src = q.front(); q.pop();
        for (i=0; i<N; ++i){
            nex = makeNext(src, btn[i]);
            if (vis[nex] == -1){
                vis[nex] = i;
                pre[nex] = src;
                if (nex == dst)
                    goto end;
                q.push(nex);
            }
        }
    }
end:
    if (vis[dst]==-1){
        printf("-1\n"); return;
    }
    vector<int> pos;
    while(pre[dst] != dst){
        pos.push_back(vis[dst]);
        dst = pre[dst];
    }
    printf("%d\n", pos.size());
    for (i=pos.size()-1; i>=0; --i){
        printf("%s\n", btn[pos[i]].c_str());
    }
}

int readIn(){
    if (scanf("%d%d",&D,&N) < 0)
        return 0;
    char buf[10];
    btn.clear();
    for (int i=0; i<N; ++i){
        scanf("%s", buf);
        btn.push_back(buf);
    }
    sort(btn.begin(), btn.end());
    scanf("%s", buf);
    src = 0;
    for (int i=0; i<D; ++i){
        src *= 10;
        src += buf[i] - '0';
    }
    scanf("%s", buf);
    dst = 0;
    for (int i=0; i<D; ++i){
        dst *= 10;
        dst += buf[i] - '0';
    }
    memset(vis, -1, sizeof(vis[0])*unit[D]);
    memset(pre, -1, sizeof(pre[0])*unit[D]);
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

