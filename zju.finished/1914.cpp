#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;
enum {
    SIZ = 508,
};
struct Node {
    int a;
    int b;
    double dis;
};
struct cmp {
    bool operator()(const Node &a, const Node&b){
        return b.dis < a.dis;
    }
};
Node tree[SIZ * SIZ / 2];
int cord[SIZ][2];
int par[SIZ];
int num, sate;

void init(){
    for(int i=0;i<num;i++){
        par[i] = i;
    }
}
int getPar(int a){
    int p = par[a];
    while(p != par[p]){
        p = par[p];
    }
    return par[a] = p;
}
int in_same(int a, int b){
    a = getPar(a); b = getPar(b);
    return (a == b);
}
void connect(int a, int b){
    a = getPar(a); b = getPar(b);
    if(a < b){
        par[b] = a;
    } else if(a > b){
        par[a] = b;
    } 
}

void readIn(){
    scanf("%d%d", &sate, &num);
    for(int i=0;i<num;i++){
        scanf("%d%d", &cord[i][0], &cord[i][1]);
    }
}

double fun(){
    double ans = 0;
    int a, b;
    Node one;
    priority_queue<Node, vector<Node>, cmp> q;
    for(a=0;a<num;a++){
        for(b=a+1;b<num; b++){
            one.a = a; one.b = b;
            one.dis = (cord[a][0] - cord[b][0]);
            one.dis *= one.dis;
            ans = cord[a][1] - cord[b][1];
            ans *= ans;
            one.dis += ans;
            one.dis = sqrt(one.dis);
            q.push(one);
        }
    }

    init();
    while(num > sate){
        one = q.top(); q.pop();
        if(in_same(one.a, one.b)){
            continue;
        }
        ans = one.dis;
        connect(one.a, one.b);
        num --;
    }

    return ans;
}

int main(){
    int tstcase;
    scanf("%d", &tstcase);
    while(tstcase --){
        readIn();
        printf("%.2lf\n", fun());
    }
	return 0;
}
