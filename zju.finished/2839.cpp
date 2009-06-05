#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 52,
    LIM = 2 * SIZ * SIZ * SIZ,
};
int cub[SIZ];
int sum[SIZ*SIZ], top;
int M,N;
char mark[LIM];

void init(){
    for(int i=0;i<SIZ;i++){
        cub[i] = i * i * i;
    }
}
void predo(){
    memset(mark, 0, sizeof(mark));
    top = 0;
    for(int i=0;i<=M;i++){
        for(int j=i;j<=M;j++){
            sum[top] = cub[i] + cub[j];
            if(mark[sum[top]] == 0){
                mark[sum[top]] = 1;
                top++;
            }
        }
    }
    sort(sum, sum+top);
}
struct Node {
    int f,d;
    bool operator<(const Node &rhs)const{
        if(d != rhs.d){
            return d<rhs.d;
        }
        return f<rhs.f;
    }
};
void fun(){
    vector<Node> tree;
    Node one;
    int f,d,t,flag;
    for(int i=0;i<top;i++){
        for(int j=i+1;j<top;j++){
            flag = 1;
            f = sum[i], d = sum[j]-sum[i];
            for(t =2;t<N;t++){
                if(f + t*d >=LIM || mark[f + t*d] == 0){
                    flag = 0;
                    break;
                }
            }
            /*
            if(flag ){
                if(f + t*d<LIM && mark[f+t*d] == 1){
                    flag = 0;
                }
            }*/
            if(flag ){
                one.f = f, one.d = d;
                tree.push_back(one);
            }
        }
    }
    sort(tree.begin(), tree.end());
    for(int i=0;i<tree.size();i++){
        printf("%d %d\n", tree[i].f, tree[i].d);
    }
    if(tree.size() ==0){
        printf("NONE\n");
    }
}

int main(){
    int tstcase = 0;
    init();
    
    scanf("%d%d",&N,&M);
    while(N + M){
        if(tstcase++){
            printf("\n");
        }
        printf("Case %d:\n", tstcase);
        predo();
        fun();
        scanf("%d%d",&N,&M);
    }

    return 0;
}
