#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
enum {
    SIZ = 54,
};
struct Point {
    int x,y;
    int v;
};
struct cmp {
    bool operator()(const Point &a, const Point &b){
        return a.v < b.v;
    }
};
int M,N,K;
int val = 0;
typedef    priority_queue<Point, vector<Point>, cmp> heap;

void readIn(heap & q){
    scanf("%d%d%d",&M,&N,&K);
    int t;
    Point one;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            scanf("%d", &t);
            if(t ==0)
                continue;
            one.x = i, one.y = j, one.v = t;
            q.push(one);
        }
    }
}

void fun(){
    heap q;
    val = 0;
    readIn(q);
    Point pred = { -1, -1, 0};
    Point cur;
    while(!q.empty()){
        cur = q.top(); q.pop();
        if(pred.x == -1){
            K -= cur.x;
        } else {
            K -= abs(pred.x - cur.x) + abs(pred.y - cur.y);
        }
        K --;
        if(K < cur.x){
            break;
        }
        val += cur.v;
        pred = cur;
    }
    printf("%d\n", val);
}

int main(){
    int tstcase;
    scanf("%d", &tstcase);    
    while(tstcase --){
        fun();
    }

	return 0;
}
