#include<iostream>
#include<queue>

// DP?递推？ 很长的运行时间...
using namespace std;
enum {
    SIZ = 32,
};
int path[SIZ][SIZ] = {0};
int tstcase = 0;
int num;
int mask[SIZ][SIZ][SIZ];

void readIn(){
    int i,j,k,t;
    cin>>num;
    for(i=0;i<num;i++){
        for(j=i+1;j<num;j++){
            cin>>path[i][j];
        }
    }
    memset(mask, 9999999, sizeof(mask));
}
struct Node {
    int car[3];
    int score;
    int next;
};

int check_dup(Node &o){
    int a,b,c;
    a = min(o.car[0], min(o.car[1],o.car[2]));
    c = max(o.car[0], max(o.car[1],o.car[2]));
    if(a == o.car[0]){
        b = min(o.car[1], o.car[2]);
    }else if(a==o.car[1]){
        b = min(o.car[0], o.car[2]);
    } else {
        b = min(o.car[0], o.car[1]);
    }
    if(mask[a][b][c] <= o.score)
        return 1;
    mask[a][b][c] = o.score;
    return 0;
}

int fun(){
    int val = 9999999;
    int i,t;
    Node cur = {0}, one;
    cur.next = 1;
    queue<Node> q;
    q.push(cur);
    while(!q.empty()){
        cur = q.front(); q.pop();
        if(cur.next == num){
            if(val > cur.score)
                val = cur.score;
            continue;
        }
        for(i=0;i<3;i++){
            for(t = cur.car[i]+1;t <= cur.next;t++){
                one = cur;
                one.car[i] = t;
                one.score += path[cur.car[i]][one.car[i]];
                if(check_dup(one)){
                    continue;
                }
                if(t == cur.next){
                    one.next ++;
                }
                q.push(one);
            }
        }
    }

    return val;
}

int main(){
    int tstnum;

    cin>>tstnum;
    while(tstcase ++ < tstnum){
        readIn();
        cout<<fun()<<endl;
    }

	return 0;
}
