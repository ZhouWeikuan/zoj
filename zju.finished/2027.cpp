#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
enum {
    SIZ = 108,
    MAX = 10000008,
};
struct Node {
    int dest;
    int cost;
};
struct Save {
    int val0; int max0;
    int val1; int max1;
};
vector<Node> flight[SIZ];
map<string, int> tab;
map<string, int>::iterator it;
Save save[SIZ];
int next;
void init(){
    int i;
    for(i=0;i<SIZ;i++){
        flight[i].clear();
        save[i].val0 = save[i].val1 = save[i].max0 = save[i].max1 = MAX;
    }
    tab.clear();
    next = 0;
    save[1].val0 = save[1].val1 = save[1].max0 = save[1].max1 = 0;
}
int getIndex(string &s){
    it = tab.find(s);
    if(it!= tab.end()){
        return it->second;
    }
    tab.insert(make_pair(s,next));
    return next++;
}
int readIn(){
    init();
    int a,b,c;
    string s,d;
    cin>>s;
    if(!cin)
        return 0;
    getIndex(s);
    cin>>s;
    getIndex(s);
    int num;
    Node one;
    cin>>num;
    while(num--){
        cin>>s>>d;
        a = getIndex(s);
        b = getIndex(d);
        cin>>c;
        one.dest = b;
        one.cost = c;
        flight[a].push_back(one);
    }
    return 1;
}
void calc(int cur){
    if(save[cur].val0 != MAX)
        return;
    int i, v, m, d,c;
    for(i=0;i<flight[cur].size();i++){
        d = flight[cur][i].dest;
        c = flight[cur][i].cost;
        calc(d);
        // 0 -> 0
        v = c + save[d].val0;
        m = save[d].max0>c?save[d].max0:c;
        if(save[cur].val0 > v){
            save[cur].val0 = v; save[cur].max0 = m;
        }
        // 1 -> 0 
        v = c + save[d].val1 + save[d].max1;
        m = save[d].max1>c?save[d].max1:c;
        if(save[cur].val0 > v){
            save[cur].val0 = v; save[cur].max0 = m;
        }
        // 0 -> 1
        v = c + save[d].val0;
        m = save[d].max0>c?save[d].max0:c;
        v -= m;
        if(save[cur].val1 > v){
            save[cur].val1 = v; save[cur].max1 = m;
        }
        // 1 -> 1
        v = c + save[d].val1 + save[d].max1;
        m = save[d].max1>c?save[d].max1:c;
        v -= m;
        if(save[cur].val1 > v){
            save[cur].val1 = v; save[cur].max1 = m;
        }
    }
}
void fun(){
    calc(0);
    int v = MAX;
    v = save[0].val0 - save[0].max0;
    if(v > save[0].val1)
        v = save[0].val1;
    cout<<v<<endl;
}
int main(){

    while(readIn()){
        fun();
    }
    return 0;
}
