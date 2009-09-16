#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
enum {
    SIZ = 504,
};
struct Taxi {
	int time;
	int cost;
    int x[2];
    int y[2];
};
Taxi cab[SIZ];
bool tab[SIZ][SIZ];
int mat[SIZ];
bool vis[SIZ];
int num;

inline int abs(int a){
    if (a<0) a=-a;
    return a;
}
inline int calc(int a, int b,int c, int d){
    return abs(a-c) + abs(b-d);
}
int avail(Taxi &a, Taxi&b){
    return a.time + a.cost + calc(a.x[1],a.y[1],b.x[0],b.y[0]) < b.time;
}
void init_tab(){
    memset(tab, false, sizeof(tab));
    for(int i=0;i<num;++i){
        for(int j=i+1;j<num;++j){
            tab[i][j] = avail(cab[i],cab[j]);
        }
    }
}

int dfs(int p){
    int i,t;
    for(i=0;i<num;++i)
        if(tab[i][p] && !vis[i]){
            vis[i]=true;
            t=mat[i];
            mat[i]=p;
            if(t==-1 || dfs(t))
                return 1;
            mat[i]=t;
        }
    return 0;
}

int get_match(){
    int i,res=0;
    memset(mat,-1,sizeof(mat));
    for(i=0;i<num;++i){
        memset(vis,false,sizeof(vis));
        dfs(i);
    }
    memset(vis,false,sizeof(vis));
    for (i=0; i<num; ++i){
        if (vis[i]) continue;
        vis[i] = true;
        int t = mat[i];
        while(t >=0 && !vis[t]){
            vis[t] = true;
            t = mat[t];
        }
        ++res;
    }
    return res;
}

int fun(){
    init_tab();
    int car = get_match();
    return car;
}
int main(){
	int tstcase;
	int h,m;
    scanf("%d",&tstcase);
	while(tstcase --){
        scanf("%d",&num);
		for(int i=0;i<num;i++){
            scanf("%d:%d",&h,&m);
			cab[i].time = h * 60 + m;
            scanf("%d%d%d%d",
                    &cab[i].x[0],
                    &cab[i].y[0],
                    &cab[i].x[1],
                    &cab[i].y[1]);
			cab[i].cost = 
                calc(cab[i].x[0], cab[i].y[0], cab[i].x[1], cab[i].y[1]);
		}
        int h = fun();
        printf("%d\n", h);
	}
	
	return 0;
}

