#include<iostream>
#include<iomanip>
#include<queue>
#include<cmath>
// 精度问题
using namespace std;
enum {
    SIZ = 104,
};
struct Point {
    double x,y,z,r;
};
struct Node {
    int a;
    int b;
    double dis;
    struct cmp{
        bool operator()(const Node&a, const Node&b){
            return a.dis > b.dis;
        }
    };
};

Point tree[SIZ];
int num;
int par[SIZ];
const double eps = 1e-8;

double getDis(const Point&a, const Point&b){
    double ret = 0;
    double t;
    t = a.x - b.x;
    ret += t * t;
    t = a.y - b.y;
    ret += t * t;
    t = a.z - b.z;
    ret += t * t;
    return ret = sqrt(ret);
}

int get_par(int n){
    int p = par[n];
    while(par[p] != p){
        p = par[p];
    }
    return par[n] = p;
}
int in_same(int a, int b){
    a = get_par(a);
    b = get_par(b);
    return (a==b);
}

void con(int a, int b){
    a = get_par(a);
    b = get_par(b);
    if(a < b){
        par[b] = a;
    } else {
        par[a] = b;
    }
}

double fun(){
    int i,j;
    Node one;
    priority_queue<Node,vector<Node>, Node::cmp> q;
    for(i=0;i<num;i++){
        cin>>tree[i].x>>tree[i].y>>tree[i].z>>tree[i].r;
        par[i] = i;
    }
    int cnt = num;
    for(i=0; i<num;i++){
        for(j=i+1;j<num;j++){
            one.dis = getDis(tree[i], tree[j]);
            if(one.dis <= tree[i].r + tree[j].r + eps){
                if(!in_same(i,j)){
                    con(i,j);
                    cnt --;
                }
            } else {
                one.dis -= tree[i].r;
                one.dis -= tree[j].r;
                one.a = i; one.b = j;
                q.push(one);
            }
        }
    }

    double ret = 0;
    while(cnt > 1){
        one = q.top(); q.pop();
        if(in_same(one.a, one.b)){
            continue;
        }
        ret += one.dis;
        cnt --;
        con(one.a, one.b);
    }

    return ret;
}

int main(){
    double t;

    cin>>num;
    while(num){
        t = fun();
        cout<<setiosflags(ios::fixed)<<setprecision(3)
            <<t<<endl;
        cin>>num;
    }

	return 0;
}
