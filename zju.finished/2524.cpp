#include<iostream>
#include<ext/hash_map>
using namespace std;
using namespace __gnu_cxx;
enum {
    SIZ = 10008,
};
struct Node {
    char name[24];
    int win, draw, lose;
    int point;
    int goal;
    bool operator<(const Node&rhs)const{
        if(point != rhs.point)
            return point>rhs.point;
        if(goal != rhs.goal)
            return goal>rhs.goal;
        return strcmp(name,rhs.name)<0;
    }
};
char buf[24];
struct eqstr {
    bool operator()(const char*lhs, const char *rhs)const {
        return strcmp(lhs,rhs)==0;
    }
};
hash_map<const char *,int, hash<const char*>, eqstr> tab;
hash_map<const char *,int, hash<const char*>, eqstr>::iterator it;
int next = 0;
int num;
Node tree[SIZ];
int query(const char *s){
    it = tab.find(s);
    if(it != tab.end())
        return it->second;
    memset(&tree[next], 0, sizeof(tree[next]));
    strcpy(tree[next].name, s);
    tab.insert(make_pair(tree[next].name,next));
    return next++;
}
int fun(){
    char ch;
    int a,b, ga,gb;
    while(num--){
        scanf("%s%d:", buf, &ga);
        a = query(buf);
        scanf("%d%s", &gb, buf);
        b = query(buf);
        if(ga > gb){
            tree[a].point += 3;
            tree[a].goal += ga - gb;
            tree[b].goal += gb - ga;
            tree[a].win++;
            tree[b].lose++;
        } else if(ga == gb){
            tree[a].point ++;
            tree[b].point ++;
            tree[a].draw++;
            tree[b].draw++;
        } else { // ga < gb
            tree[b].point += 3;
            tree[b].goal += gb-ga;
            tree[a].goal += ga-gb;
            tree[a].lose++;
            tree[b].win++;
        }
    }
    sort(tree, tree+next);
    for(int i=0;i<next;i++){
        printf("%d %s %d %d %d %d %d\n", i+1, tree[i].name, tree[i].win,
                tree[i].draw, tree[i].lose, tree[i].point, tree[i].goal);
    }
    return 0;
}

int main(){
    int tstcase = 0;
    while(scanf("%d",&num) > 0){
        if(tstcase++)
            printf("\n");
        next = 0;
        tab.clear();
        fun();
    }
    return 0;
}
