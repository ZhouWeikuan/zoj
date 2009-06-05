#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const double eps = 1e-8;
struct Node {
    int no;
    double score;
    bool operator < (const Node&rhs) const {
        if( fabs(score - rhs.score) < eps)
            return no < rhs.no;
        return score > rhs.score;
    }
};
struct cmp{
    bool operator()(const Node&lhs, const Node&rhs)const {
        return lhs.no > rhs.no;
    }
};
int N,M,K;
vector<Node> t;

void fun(){
    t.reserve(M);
    for(int i=0;i<M;i++){
        t[i].no = i + 1;
        t[i].score = 0;
    }
    double s;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%lf",&s);
            t[j].score += s;
        }
    }
    sort(t.begin(), t.begin() + M);
    sort(t.begin(), t.begin() + K, cmp());
    for(int i=0;i<K;i++){
        if(i==0){
            printf("%d", t[i].no);
        } else {
            printf(" %d", t[i].no);
        }
    }
    printf("\n");
}

int main(){
    while(scanf("%d%d%d",&N,&M,&K) > 0){
        fun();
    }
    return 0;
}

