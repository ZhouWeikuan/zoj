#include<iostream>
#include<queue>
#include<ext/hash_set>
using namespace std;
using namespace __gnu_cxx;
typedef unsigned ut;
enum {
    SIZ = 30,
    Row = 5,
    Col = 6,
};
hash_set<ut> tab;
struct Node {   
    ut m,o,s;
    struct cmp{
        bool operator()(const Node&a, const Node&b){
            return a.s<b.s;
        }
    };
};

inline void set(Node &one, ut pos){
    ut k = 1<<pos;
    // self
    if(one.m & k){
        one.m &= ~k;
        one.s --;
    } else {
        one.m |=k;
        one.s++;
    }
    //up
    if(pos>=Col){
        k = 1<<(pos-Col);
        if( one.m & k){
            one.m &= ~k;
            one.s--;
        } else {
            one.m |= k;
            one.s++;
        }
    }
    // down
    if(pos + Col < SIZ){
        k = 1<<(pos + Col);
        if(one.m &k){
            one.m &= ~k;
            one.s--;
        } else {
            one.m |= k;
            one.s++;
        }
    }
    // left
    if( pos % Col != 0){
        k = 1<<(pos-1);
        if(one.m & k){
            one.m &= ~k;
            one.s--;
        } else {
            one.m |= k;
            one.s++;
        }
    }
    // right
    if(pos %Col != Col-1){
        k = 1<<(pos+1);
        if(one.m &k ){
            one.m &= ~k;
            one.s--;
        } else {
            one.m |= k;
            one.s++;
        }
    }
}
void output(ut o){
    ut k;
    for(ut i=0;i<SIZ;i++){
        k = 1<<i;
        if(o & k){
            if(i%Col==0){
                cout<<"1";
            } else {
                cout<<" 1";
            }
        } else {
            if(i%Col==0){
                cout<<"0";
            } else {
                cout<<" 0";
            }
        }
        if(i % Col == 5){
            cout<<endl;
        }
    }
}

int fun(){
    ut i, t;
    Node one = {0}, next;
    tab.clear();
    for(i=0;i<SIZ;i++){
        cin>>t;
        if(t){
            one.m |= (1<<i);
            one.s++;
        } 
    }
    priority_queue<Node, vector<Node>, Node::cmp> q;
    q.push(one);
    while(!q.empty()){
        one=q.top(); q.pop();
        if(one.m == 0)
            break;
        for(i=0;i<SIZ;i++){
            next = one;
            next.o |= (1<<i);
            set(next,i);
            if(tab.find(next.m) == tab.end()){
                q.push(next);
                tab.insert(next.m);
            }
        }
    }
    output(one.o);
    return 0;
}

int main(){
    int tstnum,tstcase=0;
    cin>>tstnum;
    while(tstcase++ < tstnum){
        fun();
        cout<<"PUZZLE #"<<tstcase<<endl;
    }
    return 0;
}
