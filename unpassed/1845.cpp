#include<iostream>
#include<queue>
// TLE 
using namespace std;
enum {
    SIZ = 1008,
};
int num, vn;
char name[40][100];
unsigned use[40];
vector<int> ptr[40];
deque<int> vote[SIZ];

int check(int &p){
    unsigned maxV = 0, minV = num + 1;
    for(int i=1; i<=num; i++){
        if(use[i] == -1) continue;
        if(ptr[i].size() > maxV){
            maxV = ptr[i].size();
            if(maxV > vn/2){
                p = i;
                return 1;
            }
        }
        if(ptr[i].size() < minV){
            minV = ptr[i].size();
            p = i;
        }
    }
    if(minV == maxV) 
        return -1;
    return 0;
}

void fun(){
    int pos, t;
    while( (t=check(pos)) == 0){
        use[pos] = -1;
        while(ptr[pos].size()){
            t = ptr[pos].back(); ptr[pos].pop_back();
            while(use[vote[t].front()]== -1){
                vote[t].pop_front();
            }
            ptr[vote[t].front()].push_back(t);
        }
    }
    if(t == -1){ // tie
        for(t=1; t<=num; t++){
            if(use[t] == -1) continue;
            printf("%s", name[pos]);
        }
    } else {
        printf("%s", name[pos]);
    }
}
int readIn(){
    if(scanf("%d ", &num) < 0) return 0;
    int i, j, t;
    for(i=1; i<=num; i++){
        fgets(name[i], 100, stdin);
        ptr[i].clear();
    }
    memset(use, 0, sizeof(use));
    scanf("%d ", &vn);
    for(i=0; i<vn; i++){
        vote[i].clear();
        scanf("%d", &t);
        ptr[t].push_back(i);
        vote[i].push_back(t);
        for(j=1; j<num; j++){
            scanf("%d", &t);
            vote[i].push_back(t);
        }
    }
    return 1;
}
int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

