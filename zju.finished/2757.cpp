#include<iostream>
using namespace std;
enum {
    SIZ = 10008,
};
// 把所有发生关系的全部放在同一等级上
struct Node {
    int a,b,v;
    bool operator<(const Node&rhs)const{
        if(a != rhs.a)  return a < rhs.a;
        if(b != rhs.b)  return b < rhs.b;
    }
};
struct Value_t {
    int deg;
    int val;
};
int n,m,k;
Node tree[SIZ];
Value_t sum[SIZ];

void readIn(){
    n+=8;
    for(int i=1; i<n;i++){
        sum[i].deg = -1;
    }
    n-=8;
    sum[0].deg = 0;
    sum[0].val = 0;
    for(int i=0; i<m; i++){
        scanf("%d%d%d",&tree[i].a, &tree[i].b, &tree[i].v);
        tree[i].a --;
    }
    sort(tree, tree+m);
}
void fun(){
    int i,j;
    bool flag = true;
    int deg = -1;
    while(m > 0){
        deg++;
        flag = true;
        while(flag  && m > 0){
            j = 0;
            flag = false;
            for(i=0; i<m; i++){
                if(sum[tree[i].a].deg == deg){
                    flag = true;
                    sum[tree[i].b].val = sum[tree[i].a].val + tree[i].v;
                    sum[tree[i].b].deg = deg;
                } else if(sum[tree[i].b].deg == deg){
                    flag = true;
                    sum[tree[i].a].val = sum[tree[i].b].val - tree[i].v;
                    sum[tree[i].a].deg = deg;
                } else {
                    tree[j++] = tree[i];
                }
            }
            m = j;
        }
        if(m > 0){
            m--;
            sum[tree[m].a].val = 0;
            sum[tree[m].b].val = tree[m].v;
            sum[tree[m].a].deg = deg+1;
            sum[tree[m].b].deg = deg+1;
        }
    }
}
void query(){
    int a, b, i;
    for(i=0; i<k; i++){
        scanf("%d%d",&a,&b);
        a--;
        if(sum[a].deg == sum[b].deg && sum[a].deg >= 0){
            printf("%d\n", sum[b].val - sum[a].val);
        } else {
            printf("UNKNOWN\n");
        }
    }
}
int main(){

    while(scanf("%d%d%d",&n,&m,&k) != -1){
        readIn();
        fun();
        query();
        printf("\n");
    }
    return 0;
}

