#include<iostream>
#include<queue>

using namespace std;
enum {
    SIZ = 30008,
};
int input[SIZ];
int N,M, pos;

int readIn(){
    int i;
    if(scanf("%d%d",&N,&M) <= 0)
        return 0;
    for(i=0;i<N;i++){
        scanf("%d", &input[i]);
    }
    return 1;
}

void fun(){
    int cur, i=0, t;
    priority_queue<int, vector<int>, less<int> > old;
    priority_queue<int, vector<int>, greater<int> > one;
    pos = 0;
    while(M -- > 0){
        scanf("%d", &cur);
        while(i < cur){
            old.push(input[i]);
            i++;
        }
        while( old.size() > pos){
            t = old.top(); old.pop();
            one.push(t);
        }
        t = one.top(); one.pop();
        printf("%d\n", t);
        old.push(t);
        pos ++;
    }
}

int main(){
    int tstcase = 0;

    while(readIn()){
        if(tstcase++) {
            printf("\n");
        }
        fun();
    }

	return 0;
}
