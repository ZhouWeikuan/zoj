#include<iostream>
#include<queue>
#include<ext/hash_map>
// 输出顺序？按照boy的字典序？按照boy出现的顺序？
using namespace std;
using namespace __gnu_cxx;
enum {
    SIZ = 502,
};
struct Node {
    char name[24];
    int s;
    int m;
    int prefer[SIZ];
};
struct eqstr{
    bool operator()(const char*l, const char*r)const {
        return strcmp(l,r)==0;
    }
};
Node boy[SIZ],girl[SIZ];
int gnext,num;
typedef hash_map<const char*, int, hash<const char*>, eqstr> hash_type;
hash_type bset(SIZ*2),gset(SIZ*2);
char buf[24];

int query(hash_type &h, const char *s){
    hash_type::iterator it = h.find(s);
    if(it!=h.end())
        return it->second;
    strcpy(girl[gnext].name, s);
    h[girl[gnext].name] = gnext;
    return gnext++;
}
void readIn(){
    gnext = 0;
    bset.clear(); gset.clear();
    int b,g;
    for(b=0;b<num;b++){
        scanf("%s", boy[b].name);
        boy[b].m = -1;
        boy[b].s = 0;
        bset[boy[b].name] = b;
        for(int i=0;i<num;i++){
            scanf("%s", buf);
            g = query(gset, buf);
            boy[b].prefer[i] = g;//对于boy,按照喜好度把girl放在prefer中
        }
    }
    for(int i=0;i<num;i++){
        scanf("%s", buf);
        g = query(gset,buf);
        girl[g].m = -1;
        girl[g].s = 0;
        for(int j=0;j<num;j++){
            scanf("%s", buf);
            b = query(bset, buf);
            girl[g].prefer[b] = j; //对于girl,存放对每个boy的喜好度
        }
    }
}
void fun(){
    queue<int> q;
    int b,g;
    int i,j;
    for(i=0;i<num;i++){
        q.push(i);
    }
    while(!q.empty()){
        i = q.front(); q.pop();
        for(j=boy[i].s; j<num;j++){
            g = boy[i].prefer[j];
            b = girl[g].m;
            if(b ==-1||girl[g].prefer[b] > girl[g].prefer[i]){
                girl[g].m = i;
                boy[i].m = g;
                if(b>=0)
                    q.push(b);
                break;
            }
        }
        boy[i].s = j + 1;
    }
    for(i=0; i<num;++i){
        b = i; g = boy[b].m; 
        printf("%s %s\n", boy[b].name, girl[g].name);
    }
    printf("\n");
}
int main(){
    while(scanf("%d",&num) > 0){
        readIn();
        fun();
    }
    return 0;
}

