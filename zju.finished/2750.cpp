#include<iostream>
#include<map>
using namespace std;
enum {
    SIZ = 2008,
    MaxVal = 99999999,
};
struct Node {
    int time;
    int f,t;
};
struct strLess{
    bool operator()(const char*l, const char*r)const{
        return strncmp(l,r,4) < 0;
    }
};
char id[SIZ][6];
map<const char*, int, strLess> tab;
map<const char*, int, strLess>::iterator iter;
int num, next;
Node tree[SIZ];
char buf[200];
int  mark[SIZ];
int  dis[SIZ];

int query(const char *s){
    iter = tab.find(s);
    if(iter != tab.end())
        return iter->second;
    strncpy(id[next],s,4);
    id[next][4] = 0;
    tab.insert(make_pair(id[next], next));
    return next++;
}
int readIn(){
    tab.clear();
    next = 0;
    scanf("%d",&num);
    int len,a;
    for(int i=0;i<num;i++){
        scanf("%d%s",&tree[i].time, buf);
        len = strlen(buf);
        tree[i].f = query(buf);
        tree[i].t = query(buf+len-4);
    }
    for(int i=0;i<next;i++){
        dis[i] = MaxVal;
        mark[i] = 0;
    }
    return num;
}
int fun(){
    int cur, val;
    if(num == 1) // trap 1. just one idiom
        return 0;
    dis[tree[0].t] = tree[0].time; // trap 2, 
    // if the first and the last share the same starting code. 
    // Thus, don't close the tree[0].f;
    while(1){
        val = MaxVal;
        for(int i=0;i<num;i++){
            if(mark[tree[i].f] == 1)
                continue;
            if(dis[tree[i].f] < val){
                cur = i;
                val = dis[tree[i].f];
            }
        }
        if(val == MaxVal || cur == num - 1)
            break;
        mark[tree[cur].f] = 1;
        for(int i=0;i<num;i++){
            if(tree[i].f != tree[cur].f || mark[tree[i].t] == 1)
                continue;
            if(dis[tree[i].t] > dis[tree[i].f] + tree[i].time){
                dis[tree[i].t] = dis[tree[i].f] + tree[i].time;
            }
        }
    }
    if(dis[tree[num-1].f] == MaxVal)
        return -1;
    return dis[tree[num-1].f];
}
int main(){
    while(readIn() > 0){
        printf("%d\n", fun());
    }
    return 0;
}

