#include<iostream>
#include<queue>
#include<vector>
using namespace std;
enum {
    SIZ = 42,
};
int num, pos;           // num for vertex and pos for untouched
vector<int> ed[SIZ];    // edge
vector<int> ver;   // vertex
bool mark[SIZ];         // 
bool vis[SIZ];
unsigned dis[SIZ];

void bfs(int s){
    int i, v;
    memset(dis, -1, sizeof(dis));
    vis[s] = true;  dis[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        s = q.front(); q.pop();
        for(i=0; i<ed[s].size(); i++){
            v = ed[s][i];
            if(dis[v] > dis[s] + 1){
                dis[v] = dis[s]+1;
                q.push(v);
            }
        }
    }

}
void btf(int s, int e){
    int i,v;
    queue<int> q;
    vis[s] = true;
    while(s != e){
        for(i=0; i<ed[s].size(); i++){
            v = ed[s][i];
            if(dis[v] == dis[s] - 1){
                vis[v] = true;
                q.push(v);
            }
        }
        s = q.front(); q.pop();
    }
}
int merge(){
    int i, ret=0;
    for(i=1; i<=num; i++){
        if(vis[i] && !mark[i]){
            mark[i] = true;
            ret++;
        }
    }
    return ret;
}
bool test(){
    int i, j;
    pos = num;
    memset(mark, false, sizeof(mark));
    for(i=0; i<ver.size(); i++){
        memset(vis, false, sizeof(vis));
        bfs(ver[i]);
        for(j=i+1;j<ver.size();j++){
            btf(ver[j], ver[i]);
        }
        pos -= merge();
        if(pos <= 0){
            return true;
        }
    }
    return false;
}
void readLine(vector<int> &v){
    v.clear();
    int a; char ch;
    scanf("%d%c", &a,&ch);
    while(ch!='\n'){
        v.push_back(a);
        scanf("%d%c", &a,&ch);
    }
    v.push_back(a);
}
void fun(){
    int tst;
    const char *ans[2] = {
        "no","yes"
    };
    scanf("%d ", &tst);
    while(tst--){
        readLine(ver);
        printf("%s\n", ans[test()]);
    }
}
int readIn(){
    if(scanf("%d ", &num)<0)
        return 0;
    for(pos=1; pos<=num; pos++){
        readLine(ed[pos]);
    }
    return 1;
}
int main(){

    while(readIn()> 0){
        fun();
    }
    return 0;
}

