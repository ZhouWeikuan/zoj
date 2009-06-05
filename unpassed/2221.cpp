#include<iostream>
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
int tab[SIZ][SIZ];
int pred[SIZ];
int dis[SIZ];
int num;

inline int calc(int a, int b,int c, int d){
    return abs(a-c) + abs(b-d);
}
int avail(Taxi &a, Taxi&b){
    return a.time + a.cost + calc(a.x[1],a.y[1],b.x[0],b.y[0]) < b.time;
}
void init_tab(){
    for(int i=1;i<=num;i++){
        for(int j=1;j<=num;j++){
            if(i==j){
                tab[i][j] = 0;
            } else {
                tab[i][j] = avail(cab[i],cab[j]);
            }
        }
    }
    for(int i=1;i<=num;i++){
        tab[0][i] = 1;
        tab[i][num+1] = 1;
    }
}
bool augmentable(int s, int t) {
    queue<int> queue;
    memset(pred, -1, sizeof(pred));
    memset(dis, -1, sizeof(dis));
    pred[s] = s;
    dis[s] = 0;
    queue.push(s);
    while(!queue.empty()) {
        int p = queue.front(), i;
        queue.pop();
        for(i = 1; i <= num+1; i++) {
            if(tab[p][i] && (dis[i]==-1 || dis[i] <= dis[p])) {
                pred[i] = p;
                dis[i] = dis[p] + 1;
                if(i != t) {
                    queue.push(i);
                }
            }
        }
    }
    return dis[t]>=0;
}

int maxFlow(int s, int t) {
    int car = 0, i;
    while(augmentable(s, t)) {
        for(i = t; i != s; i = pred[i]) {
            tab[pred[i]][i] = 0; 
            tab[i][pred[i]] = 1;
        }
        ++car;
    }
    return car;
}
int fun(){
    init_tab();
    return maxFlow(0,num+1);
}
int main(){
	int tstcase;
	int h,m;
    scanf("%d",&tstcase);
	while(tstcase --){
        scanf("%d",&num);
		for(int i=1;i<=num;i++){
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
		cout<<fun()<<endl;
	}
	
	return 0;
}

