#include<iostream>
#include<set>
using namespace std;
enum {
    SIZ = 108,
};
int num;
unsigned cost[SIZ][SIZ];
unsigned dis[SIZ];
bool use[SIZ];

int getLowest(){
    int i, p = 0;
    unsigned v = -1;
    for(i=0; i<num; i++){
        if(use[i]) continue;
        if(v > dis[i]){
            v = dis[i];
            p = i;
        }
    }
    return p;
}
void update(int s){
    for(int i=0; i<num; i++){
        if(use[i] || cost[s][i] == -1) 
            continue;
        if(dis[i] > cost[s][i] + dis[s]){
            dis[i] = cost[s][i] + dis[s];
        }
    }
}
void fun(){
    memset(dis, -1, sizeof(dis));
    memset(use, false, sizeof(use));
    dis[0] = 0;
    int s, i;
    for(i=1; i<num; i++){
        s = getLowest();
        use[s]= true;
        update(s);
    }

    s = 0;
    for(i=1; i<num; ++i){
        if(dis[i] > dis[s]){
            s = i;
        }
    }
    printf("%d\n", dis[s]);
}

void readIn(){
    int i,j;
    static char buf[16];
    scanf("%d",&num);
    for(i=1; i<num; ++i){
        for(j=0; j<i; ++j){
            scanf("%s ", buf);
            if(buf[0] =='x'){
                cost[i][j] = cost[j][i] = -1;
            } else {
                cost[i][j] = cost[j][i] = atoi(buf);
            }
        }
    }
}

int main(){
    int tst;
    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
        if(tst) printf("\n");
    }
    return 0;
}

