#include<iostream>
using namespace std;
enum {
    SIZ = 2000000,
};
struct Node {
    int a,b;
    bool operator<(const Node &rhs) const{
        return a < rhs.a;
    }
};
int sum[SIZ]= {-1,-1,0};
Node tree[1200];
int pos;

void init(){
    int i,t;
    for(i=2;i<SIZ;i++){
        t = sum[i]+1;
        if(t < i && sum[t] == i-1){
            tree[pos].b = i; tree[pos].a = t;
            pos ++;
        }
        for(t=i+i;t<SIZ;t+=i){
            sum[t] += i;
        }
    }
    sort(tree, tree+pos);
}

int main(){
    init();
    int t;
    while(scanf("%d",&t) != EOF){
        --t;
        printf("%d %d\n", tree[t].a, tree[t].b);
    }
    return 0;
}
