#include<iostream>
#include<map>

using namespace std;

typedef struct {
    int parent;
    int deep;
}Node;
map<int,Node>   tree;
map<int,int>    trace;

int nodenum;
int pairnum;

void init(){
    tree.clear();
    trace.clear();    
}

void make_dp(int i){
    Node &n = tree[i];
    if(n.deep != -1)
        return;
    Node &p = tree[n.parent];
    if(p.deep == -1){
        make_dp(n.parent);
    }
    n.deep = p.deep + 1;
}

void make_depth(){
    map<int,Node>::iterator iter;
    for(iter=tree.begin();iter!=tree.end();iter++){
        Node &n = iter->second;
        if(n.deep != -1){
            continue;
        } else if(n.parent==-1){
            n.deep = 0;
        } else if(tree[n.parent].deep!=-1){
            n.deep = tree[n.parent].deep + 1;
        } else {
            make_dp(n.parent);
            n.deep = tree[n.parent].deep + 1;
        }
    }
    
}

void trace_pair(int a, int b){
    Node *na = &tree[a];
    Node *nb = &tree[b];
    while(na->deep > nb->deep){
        a  = na->parent;
        na = &tree[a];
    }
    while(nb->deep > na->deep){
        a = nb->parent;
        nb = &tree[a];
    }
    while(na != nb){
        a = na->parent;
        na = &tree[a];
        nb = &tree[nb->parent];
    }
    trace[a] ++;
}

int fun(){
    int tnum;
    cin>>tnum;
    int a,b;
    char c;
    
    while(tnum--){
        cin>>c>>a>>c>>b>>c;
        trace_pair(a,b);
    }
    map<int,int>::iterator iter;
    for(iter=trace.begin();iter!=trace.end();iter++){
        cout<< (iter->first) <<":" <<(iter->second)<<endl;
    }
}

int main(){
    char c;    
    int num;   
    int i,j;
    int n;
    Node p = {-1,-1}; 
    Node q = {-1,-1};    
    
    while(cin>>nodenum){        
        init();
        for(i=0;i<nodenum;i++){
            cin>>p.parent>>c>>c>>num>>c;
            if(tree.end() == tree.find(p.parent)){
                tree[p.parent] = q;
            }
            for(j=0;j<num;j++){
                cin>>n;
                tree[n] = p;
            }
        }
        make_depth();
        fun();
    }
    
    return 0;
}
