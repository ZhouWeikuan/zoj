#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;
enum {
    SIZ = 104,
};
struct Node {
    bool init;
    int par;
    int age;
    string name;

    bool operator <(const Node&o)const{
        if (age != o.age){ // prefer elder
            return age < o.age;
        }
        // prefer smaller
        return name > o.name;
    }

    void initAge();
};
Node tree[SIZ];

void Node::initAge(){
    if (init) return;
    tree[par].initAge();
    age = tree[par].age - age;
    init = true;
}

int num, pos;
map<string, int> tab;

void output(priority_queue<Node> &q){
    static int tst = 0;
    printf("DATASET %d\n", ++tst);
    while(!q.empty()){
        const Node &o = q.top();
        if (o.name != "Ted")
            cout<<o.name<<" "<<o.age<<"\n";
        q.pop();
    }
}

void fun(){
    priority_queue<Node> q;
    ++num;
    for (int i=0; i<num; ++i){
        tree[i].initAge();
        q.push(tree[i]);
    }
    output(q);
}

int find(string &s){
    map<string, int>::iterator it = tab.find(s);
    if (it != tab.end()) return it->second;
    tree[pos].par = -1;
    tree[pos].init = false;
    tree[pos].name = s;
    tab.insert(make_pair(s, pos));
    return pos++;
}

void readIn(){
    tab.clear();
    pos = 0;
    cin>>num;
    int diff;
    string a, b;
    int pa, pb;
    for (int i=0; i<num; ++i){
        cin>>a>>b>>diff;
        pa = find(a);
        pb = find(b);
        tree[pb].age = diff;
        tree[pb].par = pa;
    }
    a = "Ted"; pa = find(a);
    tree[pa].init = true;
    tree[pa].age = 100;
}

int main(){
    int tst;

    cin>>tst;
    while(tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}

