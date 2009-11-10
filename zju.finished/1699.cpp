#include<iostream>
using namespace std;
enum {
    SIZ = 4,
};
int pos[SIZ];
int N,L,M, last;
char deck[100];

void init(){
    for(int i=0;i<N;i++){
        pos[i] = -1;
    }
}
void play(int c, char m){
    pos[c]++;
    while(pos[c] < L && deck[pos[c]] != m){
        pos[c]++;
    }
    if(pos[c] >= L){
        pos[c] = L;
    }
}
int fun(){
    int cur = 0;
    char buf[4];
    for(int i=0;i<M;i++){
        cin>>buf;
        play(cur, buf[0]);
        if(buf[1]){
            play(cur,buf[1]);
        }
        if(pos[cur] >= L){
            ++i;
            last = i;
            for(;i < M;i++){
                cin>>buf;
            }
            return cur + 1;
        }
        cur = (cur + 1 ) % N;
    }
    return -1;
}
int main(){
    int t;
    cin>>N>>L>>M;
    while(N){
        L--;
        init();
        cin>>deck;
        t = fun();
        if(t >= 0){
            cout<<"Player "<<(t)<<" won after "<<(last)<<" cards."<<endl;
        } else {
            cout<<"No player won after "<<M<<" cards."<<endl;
        }
        cin>>N>>L>>M;
    }

    return 0;
}

