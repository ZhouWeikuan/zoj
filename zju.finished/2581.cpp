#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
enum {
    SIZ = 100,
};
struct Node {
    double x,y;
};
Node tree[SIZ];
struct Hist {
    int update;
    double val;
};
Hist save[SIZ][SIZ];
double dm[SIZ][SIZ];
int num, tstcase =0;

inline double getDis(Node &a, Node &b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
void readIn(){
    int i,j;
    for(i=0;i<num;i++){
        cin>>tree[i].x>>tree[i].y;
    }
    for(i=0;i<num;i++){
        for(j=i+1;j<num;j++){
            dm[i][j] = dm[j][i] = getDis(tree[i], tree[j]);
        }
    }
}

void calc(int a, int b){
    if(a==num || b==num)
        return;
    int m = max(a,b);
    m ++;
    // set a to m
    if(save[m][b].update < tstcase || save[m][b].val > save[a][b].val + dm[a][m]){
        save[m][b].update = tstcase; save[m][b].val = save[a][b].val + dm[a][m];
        calc(m,b);
    }
    // set b to m
    if(save[a][m].update<tstcase||save[a][m].val>save[a][b].val + dm[m][b]){
        save[a][m].update = tstcase; save[a][m].val = save[a][b].val + dm[m][b];
        calc(a,m);
    }
}

int fun(){
    save[0][0].val = 0;
    save[0][0].update = tstcase;
    num--;
    calc(0,0);
    double ret = 1e27;
    double t;
    for(int i=0;i<num-1;i++){
        t = dm[i][num] + dm[num-1][num] + save[i][num-1].val;
        if(t < ret)
            ret = t;
        t = dm[i][num] + dm[num-1][num] + save[num-1][i].val;
        if(t < ret)
            ret = t;
    }

    cout<<setiosflags(ios::fixed)<<setprecision(2)<<ret<<endl;

    return 0;
}

int main(){
    while(cin>>num){
        tstcase ++;
        readIn();
        fun();
    }

    return 0;
}
