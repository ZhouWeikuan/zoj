#include<iostream>
using namespace std;
enum {
    SIZ = 66000,
};
struct Node {
    int no;
    double p;
    bool operator<(const Node&rhs) const{
        return p>rhs.p;
    }
};
int num;
Node tree[SIZ];
int readIn(){
    if(scanf("%d",&num)<= 0)
        return 0;
    int len; double f;
    for(int i=0;i<num;i++){
        scanf("%d%d%lf",&tree[i].no,&len,&f);
        tree[i].p = f/len;
    }
    return 1;
}
int fun(){
    int t;
    scanf("%d",&t);
    sort(tree, tree+num);
    return tree[t-1].no;
}

int main(){
    while(readIn()){
        cout<<fun()<<endl;
    }
    return 0;
}
