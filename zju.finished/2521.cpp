#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 10,
    NUM = 1008,
};
vector<int> e[SIZ];
int cnt[SIZ];
int t[NUM];
int num;

inline void add(int a, int b){
    e[a].push_back(b);
}
void init(){
    add(0,8);
    add(1,7); add(1,4); add(1,0); add(1,3); add(1,9); add(1,8);
    add(2,8);
    add(3,9); add(3,8);
    add(4,9); add(4,8);
    add(5,6); add(5,8);
    add(6,8);
    add(7,0); add(7,3); add(7,9); add(7,8);
    add(9,8);
}

void readIn(){
    for(int i=0;i<num;i++){
        cin>>t[i];
    }
}
int fun(){
    int res = 0;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<num;i++){
        for(int j=0;j<e[t[i]].size();j++){
            int v = e[t[i]][j];
            if(cnt[v] > 0){
                res --;
                cnt[v]--;
                break;
            }
        }
        res++;
        cnt[t[i]]++;
    }

    return res;
}

int main(){
    init();

    while(cin>>num){
        readIn();
        cout<<fun()<<endl;
    }

    return 0;
}
