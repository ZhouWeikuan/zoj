#include<iostream>
#include<string>
#include<iterator>

using namespace std;
enum {
    SIZ = 24,
};
int N,K;
struct Node {
    int mark;
    string s;
};
Node pred[SIZ];
Node cur[SIZ];
ostream & operator << (ostream &o, const Node &n){
    o<<n.s;
    return o;
}

void fun(){
    int i, a,b;
    cin>>N>>K;
    for(i=0;i<N;i++){
        cin>>pred[i].s;
        pred[i].mark = -1;
        cur[i].mark = -1;
    }
    for(i=0;i<K;i++){
        cin>>a>>b;
        a--, b--;
        cur[b].s = pred[a].s;
        pred[a].mark = b;
        cur[b].mark = a;
    }
    a = b = 0;
    while(a < N && b < N){
        if(pred[a].mark != -1){
            a++;
        } else if(cur[b].mark != -1){
            b++;
        } else {
            cur[b].s = pred[a].s;
            a++,b++;
        }
    }
    cout<<cur[0].s;
    for(i=1;i<N;i++){
        cout<<" "<<cur[i].s;
    }
    cout<<endl;
}

int main(){
    int tstcase;

    cin>>tstcase;
    while(tstcase --){
        fun();
    }

	return 0;
}
