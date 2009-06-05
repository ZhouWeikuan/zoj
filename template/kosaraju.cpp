//http://purety.jp/akisame/oi/TJU/

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define NMAX 11000 
 
vector< vector< int > > path;
vector< vector< int > > npath;
int n,m, scc;
int order[NMAX], order_pos, id[NMAX], id_total[NMAX];
bool vis[NMAX];
int out_degre[NMAX];
 
void dfs(int pos)
{
	int i,j,l;
	vis[pos] = true;
	l = path[pos].size();
	for (i=0;i<l;i++) {
		j = path[pos][i];
		if (!vis[j]) {
			dfs(j);
		}
	}
	order[ order_pos ++ ] = pos;//make order
}
 
void ndfs(int pos)
{
	int i,j,l;
	vis[pos] = true;
	id[pos] = scc;
	l = npath[pos].size();
	for (i=0;i<l;i++) {
		j = npath[pos][i];
		if (!vis[j]) {
			ndfs(j);
		}
	}
}
 
void Kosaraju()
{
	int i,j,l;
	//dfs in original graph
	memset(vis, 0, sizeof(vis));
	for (i=1; i<=n ;i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	//dfs in inverse graph
	memset(vis, 0, sizeof(vis));
	memset(id, 0, sizeof(id));
	scc = 1;
	for (i=order_pos-1; i>=0 ;i--) {
		if (!vis[ order[i] ]) {
			ndfs(order[i]);
			scc ++;
		}
	}
	//statist
	scc --;
	memset(id_total, 0, sizeof(id_total));
	for (i=1;i<=n;i++) {
		id_total[ id[i] ] ++;
	}
 
	memset(out_degre, 0, sizeof(out_degre));
	for (i=1;i<=n;i++) {
		l = path[i].size();
		int id1 = id[i];
		for (j=0;j<l;j++) {
			int id2 = id[ path[i][j] ];
			if (id1 != id2) {//id1 -> id2
				out_degre[id1] ++;
			}
		}
	}
	int ans_id,zero_degre = 0;
	for (i=1;i<=scc;i++) {
		if (out_degre[i] == 0) {
			zero_degre ++;
			ans_id = i;
		}
	}
 
	if (zero_degre > 1) {
		printf("0\n");
	}
	else {
		printf("%d\n",id_total[ ans_id ]);
	}
}
 
int main()
{
	int i,j;
	while (scanf("%d %d",&n,&m)==2) {
		path.resize(n+10);
		npath.resize(n+10);
		for (i=0;i<=n;i++) {
			path[i].clear();
			npath[i].clear();
		}
		order_pos = 0;
		//set graph
		for (i=0;i<m;i++) {
			int x,y;
			scanf("%d %d",&x,&y);
			path[x].push_back(y);
			npath[y].push_back(x);
		}
		Kosaraju();
	}
}
