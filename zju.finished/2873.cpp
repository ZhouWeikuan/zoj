#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
enum {
    SIZ = 80000,
};
const long long LIM = (long long)1e18;
int num;
long long dat[SIZ];
int m[4] = {2, 3, 5, 7};

void init(){
    int i;
    long long val = 1, nex;
    priority_queue<long long, vector<long long>, greater<long long> > q;
    q.push(val);
    num = 0;
    while(!q.empty()){
        val = q.top(); q.pop();
        dat[num++] = val;
        for(i=3; i>0; i--){
            if(val % m[i] == 0)
                break;
        }
        for(; i<4; i++){
            nex = val * m[i];
            if(nex >= LIM) 
                break;
            q.push(nex);
        }
    }
}

int main(){
    init();
    int tstcase, t;
    scanf("%d", &tstcase);
    while(tstcase--){
        scanf("%d", &t);
        t--;
        printf("%lld\n", dat[t]);
    }

    return 0;
}

