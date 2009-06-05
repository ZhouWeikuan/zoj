#include<iostream>
using namespace std;
enum {
    Camp = 1008,
    SIZ  = 10008, 
};
int sum[Camp];
int num[Camp];
struct Node {
    int a,b;
    int c;
    bool operator<(const Node&rhs)const{
        if(a!=rhs.a) return a<rhs.a;
        return b<rhs.b;
    }
};
Node tree[SIZ];
int N,M;

void readIn(){
    int t, i;
    sum[0] = num[0] = 0;
    for(i=1;i<=N;i++){
        scanf("%d",&t);
        sum[i] = sum[i-1] + t;
        num[i] = 0;
    }
    for(i=0;i<M;i++){
        scanf("%d%d%d",&tree[i].a,&tree[i].b,&tree[i].c);
        tree[i].a--;
    }
    sort(tree, tree+M);
}
int fun(){
    int i=0, j=0;
    int t;
    bool flag = true;
    while(flag){
        flag = false;
        j = 0;
        for(i=0; i<=N; i++){
            if(i>0){
                if(num[i]< num[i-1]){
                    // 提升后面
                    num[i] = num[i-1];
                    flag = true;
                } else if(num[i] - num[i-1] > sum[i] - sum[i-1]){
                    // 如果后面比前面大很多，前面的也要提升
                    // 一开始没有这个，wa到死
                    num[i-1] = num[i] - sum[i] + sum[i-1];
                    flag = true;
                }
            }
            if(num[i] > sum[i]){
                return -1;
            }
            for( ; j<M && tree[j].a == i; j++){
                if(sum[tree[j].b] - sum[tree[j].a] < tree[j].c){
                    return -1;
                }
                t = num[tree[j].a] + tree[j].c;
                if(num[tree[j].b] < t){
                    num[tree[j].b] = t;
                    flag = true;
                }
            }
        }
    }
    return num[N];
}
int main(){
    int t;
    while(scanf("%d%d",&N,&M) > 0){
        readIn();
        t = fun();
        if(t < 0){
            printf("Bad Estimations\n");
        } else {
            printf("%d\n",t);
        }
    }
    return 0;
}

