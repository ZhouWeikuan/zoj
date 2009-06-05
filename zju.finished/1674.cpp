#include<iostream>
#include<map>
using namespace std;
enum {
    SIZ = 1008,
};
struct cmp{
    bool operator()(const char *a, const char *b)const{
        return strcmp(a, b)<0;
    }
};
struct Node{
    int par, in, out, lvl;
    char name[24];
};
map<const char*, int, cmp> tab;
map<const char*, int, cmp>::iterator it;
Node tree[SIZ];
char buf[80];
int num, ask;

int getTab(const char *s){
    it = tab.find(s);
    if(it!=tab.end()){
        return it->second;
    } else {
        return 99999999;
    }
}
int ad(const char *as, const char *ds){
    int a = getTab(as), d = getTab(ds);
    return (tree[a].in<tree[d].in&&tree[a].out>tree[d].out);
}
int pc(const char *ps, const char *cs){
    int p = getTab(ps), c = getTab(cs);
    return tree[c].par == p;
}
int sib(const char *as, const char *bs){
    int a = getTab(as), b = getTab(bs);
    return tree[a].par == tree[b].par;
}
void fun(){
    static char a[24], b[24], rel[24];
    static const char *ans[2] = {"False","True"};
    int i;
    for(; ask>0; ask--){
        scanf("%s%s%s", a, rel, rel);
        scanf("%s%s", rel, b);
        scanf("%s", b);
        for(i=0; b[i]!='.'; i++)
            ;
        b[i] = 0;
        if(strcmp(rel, "child") == 0){
            i = pc(b, a);
        } else if(strcmp(rel, "parent") == 0){
            i = pc(a, b);
        } else if(strcmp(rel, "sibling") == 0){
            i = sib(a, b);
        } else if(strcmp(rel, "ancestor") == 0){
            i = ad(a, b);
        } else if(strcmp(rel, "descendant") == 0){
            i = ad(b, a);
        } else {
            i = 999999999;
        }
        printf("%s\n", ans[i]);
    }
}

char *trim(int &l){
    int i;
    for(i=0; buf[i]==' '; i++)
        ;
    l = i;
    for( ; buf[i]!='\n'; i++){
    }
    buf[i] = 0;
    return &buf[l];
}
int readIn(){
    scanf("%d%d ",&num,&ask);
    int par = -1, cur = 0, t = 0;
    tab.clear();
    while(cur < num){
        fgets(buf, 80, stdin);
        strcpy(tree[cur].name, trim(tree[cur].lvl));
        while(par >=0 && tree[par].lvl >= tree[cur].lvl){
            tree[par].out = t++;
            par = tree[par].par;
        }
        tree[cur].par = par;
        tree[cur].in = t++;
        tab.insert(make_pair(tree[cur].name, cur));
        par = cur++;
    }
    while(par >= 0){
        tree[par].out = t++;
        par = tree[par].par;
    }
    return num;
}
int main(){
    while(readIn() > 0){
        fun();
        printf("\n");
    }
    return 0;
}

