#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
enum {
    SIZ = 104,
};
int N, M, K;
int scc;
bool mat[SIZ][SIZ];
int order[SIZ], order_pos, id[SIZ];
bool vis[SIZ];
int tab[2][SIZ];
 
void dfs(int pos)
{
	vis[pos] = true;
	for (int i=0;i<N;i++) {
	    if (!mat[pos][i]) continue;
		if (!vis[i]) {
			dfs(i);
		}
	}
	order[ order_pos ++ ] = pos;//make order
}
 
void ndfs(int pos)
{
	vis[pos] = true;
	++id[scc];
	for (int i=0;i<N;i++) {
	    if (!mat[i][pos]) continue;
		if (!vis[i]) {
			ndfs(i);
		}
	}
}
 
void Kosaraju()
{
	int i,j,l;
	order_pos = 0;
	//dfs in original graph
	memset(vis, 0, sizeof(vis));
	for (i=0; i<N;i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	//dfs in inverse graph
	memset(vis, 0, sizeof(vis));
	memset(id, 0, sizeof(id));
	scc = 0;
	for (i=order_pos-1; i>=0 ;i--) {
		if (!vis[ order[i] ]) {
			ndfs(order[i]);
			scc ++;
		}
	}
}

void fun(){
    Kosaraju();
    memset(tab[0], 0, sizeof(tab[0]));
    int *pre = tab[0], *cur=tab[1], *tmp;
    pre[0] = 1;
    for (int i=0; i<scc; ++i){
        memset(cur, 0, sizeof(tab[0]));
        for (int j=0; j<=K; ++j){
            if (!pre[j]) continue;
            for (int k=1; k<=id[i]&&j+k<=K; ++k){
                cur[j+k] += pre[j];
            }
        }
        tmp = pre, pre = cur, cur = tmp;
    }
    printf("%d\n", pre[K]);
}

int readIn() {
    if (scanf("%d%d%d", &N, &M, &K) < 0) 
        return 0;
    memset(mat, false, sizeof(mat));
    int a, b;
    for (int i=0; i<M; ++i){
        scanf("%d%d", &a, &b);
        mat[--a][--b] = true;
    }
    
    return 1;
}
 
int main()
{
	int i,j;
	while(readIn() > 0){
	    fun();
	}
	return 0;
}
