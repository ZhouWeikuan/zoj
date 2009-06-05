#include<iostream>
#include<vector>
#include<map>
using namespace std;
enum {
    SIZ = 808,
};
struct Node{
    int s;   // sum
    vector<int> no;
    void operator=(const Node&rhs){
        s = rhs.s;
        no = rhs.no;
    }
};
map<int, Node> tab[24];
int D[200], P[200];
int N, M; 
int diff, sum;
vector<int> v;

void update(map<int, Node> &m, int d, const Node &o){
    if(&m != &tab[M]){
        map<int, Node>::iterator iter = m.find(d);
        if(iter==m.end() ){
            m.insert(make_pair(d, o));
        }else if(iter->second.s < o.s){
            iter->second = o;
        }
        return;
    }
    if(abs(d) > abs(diff) || abs(d) == abs(diff) && sum > o.s ){
        return;
    }
    diff = d;
    sum  = o.s;
    v = o.no;
}

void fun(){
    int d, s, nd; 
    Node one;
    one.s = 0, one.no.clear();
    tab[0].insert(make_pair(0, one));
    int i,j,k;
    map<int, Node>::iterator it;
    for(i=0; i<N; i++){
        d = D[i] - P[i];
        s = D[i] + P[i];
        for(j=M-1;j>=0; j--){
            for(it=tab[j].begin(); it!=tab[j].end(); ++it){
                nd = it->first + d;
                one.s = it->second.s + s; 
                one.no = it->second.no;
                one.no.push_back(i);
                update(tab[j+1], nd, one);
            }
        }
    }
    d = (diff + sum) / 2;
    s = (sum - diff) / 2;
    printf( "Best jury has value %d for prosecution "
            "and value %d for defence:\n", s, d);
    for(i=0;i<v.size(); i++){
        printf(" %d", v[i] + 1);
    }
    printf("\n\n");
}

int readIn(){
    scanf("%d%d",&N,&M);
    if(N + M ==0) return 0;
    int i;
    for(i=0; i<N; i++){
        scanf("%d%d", &P[i], &D[i]);
    }
    for(i=0; i<=M; i++){
        tab[i].clear();
    }
    diff = 0x7fffffff;
    sum  = 0;
    v.clear();
    return 1;
}

int main(){
    int tst = 0;

    while( readIn() > 0){
        printf("Jury #%d\n", ++tst);
        fun();
    }
    return 0;
}

