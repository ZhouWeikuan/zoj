#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
enum {
    SIZ = 104,
    MSK = 0x0ffff,
};

struct Node {
    int m[2];
    double r[2];
    double f[2];
};

Node tree[SIZ];
int N, M, S;
const double eps = 1e-7;
double V;
double val[SIZ];
bool use[SIZ];
vector<int> con[SIZ];

bool fun(){
    memset(val, 0, sizeof(val));
    memset(use, false, sizeof(use));
    val[S] = V;
    queue<int> q;
    q.push(S);
    use[S] = true;
    int cur;
    while(!q.empty()){
        if (val[S] > V + eps) return true;
        cur = q.front(); q.pop();
        use[cur] = false;
        for (int i=0; i<con[cur].size(); ++i){
            int opp = con[cur][i];
            int pnt = opp & MSK;
            opp >>= 16;
            double nv = (val[cur] - tree[pnt].f[opp]) * tree[pnt].r[opp];
            int t = tree[pnt].m[1-opp];
            if (nv > val[t]){
                if (!use[t]){
                    use[t] = true;
                    q.push(t);
                }
                val[t] = nv;
            }
        }
    }

    return (val[S] > V + eps);
}

int readIn(){
    if (scanf("%d%d%d", &N, &M, &S)< 0)
        return 0;
    --S;
    scanf("%lf", &V);
    for (int i=0; i<SIZ; ++i)
        con[i].clear();
    for (int i=0; i<M; ++i){
        scanf("%d%d", &tree[i].m[0], &tree[i].m[1]);
        --tree[i].m[0], --tree[i].m[1];
        scanf("%lf%lf", &tree[i].r[0], &tree[i].f[0]);
        con[tree[i].m[0]].push_back(i);
        scanf("%lf%lf", &tree[i].r[1], &tree[i].f[1]);
        con[tree[i].m[1]].push_back((1<<16)|i);
    }
    return 1;
}

int main(){
    const char *ans[] = {
        "NO",
        "YES"
    };
    while(readIn() > 0){
        printf("%s\n", ans[fun()]);
    }

    return 0;
}

