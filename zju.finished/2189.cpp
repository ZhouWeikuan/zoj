#include<iostream>
using namespace std;
enum {
    SIZ = 4,
};
struct Node {
    int s;
    int cnt[SIZ];
};
Node temp[2][504];
int score;
int coin[SIZ];
int val[SIZ] = {25, 10, 5, 1};

void fun(){
    Node * cur = temp[0];
    Node * nex = temp[1];
    Node * tmp;
    memset(cur, 0, (score + 1)* sizeof(*cur));
    for(int i=0;i<3;i++){
        memset(nex, 0, (score + 1)* sizeof(*nex));
        for(int j=1;j<=coin[i] && j*val[i]<=score; j++){
            int t = j * val[i];
            nex[t] = cur[t];
            if(nex[t].s == 0 || nex[t].s > j){
                memset(&nex[t], 0, sizeof(nex[t]));
                nex[t].s = j;
                nex[t].cnt[i] = j;
            }
        }
        for(int t=1;t<=score;t++){
            if(cur[t].s == 0)
                continue;
            if(nex[t].s == 0 || nex[t].s > cur[t].s)
                nex[t] = cur[t];
            for(int j=1;j<=coin[i]&&t+j*val[i]<=score;j++){
                int v = t + j * val[i];
                if(nex[v].s == 0 || nex[v].s > j + cur[t].s){
                    nex[v] = cur[t];
                    nex[v].s += j;
                    nex[v].cnt[i] = j;
                }
            }
        }
        tmp = cur;
        cur = nex;
        nex = tmp;
    }
    int cnt = 99999999;
    int ptr = -1;
    for(int i=0;i<=coin[3];i++){
        int t = score-i;
        if(t != 0 && cur[t].s ==0){
            continue;
        }
        t = cur[t].s;
        if(cnt > t + i){
            cnt = i + t;
            ptr = score - i;
        }
    }
    if(cnt == 99999999){
        cout<<"NO EXACT CHANGE"<<endl;
    } else {
        for(int i=0;i<3;i++){
            cout<<cur[ptr].cnt[i]<<" ";
        }
        cout<<(score - ptr)<<endl;
    }
}

int main(){
    double v;
    while(cin >> v){
        for(int i=0;i<SIZ;i++){
            cin>>coin[i];
        }
        v *= 100;
        score = static_cast<int> (v);
        v -= score;
        if(v > 0.01){
            score ++;
        }
        fun();
    }

    return 0;
}

