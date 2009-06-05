#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 1008,
};
struct Node{
    int ptr, val;
};
int num;
vector<int> talk[SIZ];
Node tree[SIZ];
int mark[SIZ];

void clearflag(int p){
    if(mark[p] == -1) return;
    mark[p] = -1;
    clearflag(tree[p].ptr);
    for(vector<int>::iterator it=talk[p].begin(); 
            it!=talk[p].end(); ++it){
        clearflag(*it);
    }
}
int set(int p, int v){
    int t = 0, a;
    if(mark[p]==-1){
        mark[p] = v;
        t += v;
    } else {
        if(mark[p]!=v) return -1;
        return 0;
    }
    if(mark[tree[p].ptr]==-1){
        a = set(tree[p].ptr, v==tree[p].val);
        if(a == -1) return -1;
        t += a;
    } else if(mark[tree[p].ptr] != (v==tree[p].val)){
        return -1;
    }
    for(vector<int>::iterator it=talk[p].begin(); 
            it!=talk[p].end(); ++it){
        a = set(*it, v==tree[*it].val);
        if(a == -1) return a;
        t += a;
    }
    return t;
}
int fun(){
    int ret = 0, a, b;
    for(int i=1; i<=num; i++){
        if(mark[i]>=0) continue;
        a = set(i, 0);
        clearflag(i);
        b = set(i, 1);
        if(a==-1&&b==-1){
            ret = -1;
            break;
        }
        ret += max(a, b);
    }
    return ret;
}
void parse(int p){
    static char buf[1000];
    int a,b;
    scanf("%s%d",buf, &a);
    scanf("%s",buf);
    scanf("%s",buf);
    b = (buf[0]=='t');
    tree[p].ptr = a;
    tree[p].val = b;
    talk[a].push_back(p);
}
int readIn(){
    int i;
    scanf("%d",&num);
    if(num == 0) return 0;
    for(i=1; i<=num; i++){
        talk[i].clear();
        mark[i] = -1;
    }
    for(i=1; i<=num; i++){
        parse(i);
    }
    return num;
}
int main(){
    int ret;
    while(readIn() > 0){
        ret = fun();
        if(ret <= 0){
            printf("Inconsistent\n");
        } else {
            printf("%d\n", ret);
        }
    }
    return 0;
}

