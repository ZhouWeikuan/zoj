#include<iostream>
#include<string>
#include<map>
using namespace std;
enum {
    SIZ = 2008,
};
map<string, int> tab;
char buf[100];
struct Node{
    char  r;
    string u;
    string t;
    void read(){
        scanf("%s ", buf);
        u = buf;
        tab.insert(make_pair(u, 50));
        scanf("%s ", buf);
        r = buf[0];
        fgets(buf, 100, stdin);
        t = buf;
    }
};
typedef bool (*cmp_t)(const Node&, const Node&b);
bool same_title(const Node&a, const Node&b){
    return a.t == b.t;
}
bool same_userid(const Node&a, const Node&b){
    return a.u == b.u;
}
int num, pos;
Node tree[SIZ];
int ptr[SIZ];

int operate(int idx){
    if(idx > pos) return 0;
    int pnt;
    cmp_t cmp;
    if(buf[1] == '1'){
        cmp = same_title;
    } else {
        cmp = same_userid;
    }
    if(buf[2] == '1'){
        pnt = 1;
    } else {
        pnt = 2;
    }
    if(buf[3]=='y') idx = 0;
    else --idx;
    int i,j=idx;
    const Node &o = tree[ptr[idx]];
    for(i=idx; i<pos; i++){
        if(!cmp(o, tree[ptr[i]])){
            ptr[j++] = ptr[i];
        } else {
            tab[tree[ptr[i]].u] -= pnt;
        }
    }
    i = pos - j;
    pos = j;
    return i;
}

void fun(){
    int op, idx;
    scanf("%d", &op);
    for( ; op>0; op--){
        scanf("%s", buf);
        if(isdigit(buf[0])){
            idx = atoi(buf);
            scanf("%s", buf);
            printf("%d\n", operate(idx));
        } else {
            string s(buf);
            map<string, int>::iterator it=tab.find(s);
            if(it==tab.end()){
                printf("not exist\n");
            } else {
                printf("%d\n", it->second);
            }
        }
    }
}

int readIn(){
    scanf("%d", &num);
    if(num==0) return 0;
    tab.clear();
    for(int i=0; i<num; i++){
        tree[i].read();
        ptr[i] = i;
    }
    pos = num;
    return num;
}

int main(){
    while(readIn()>0){
        fun();
        printf("\n");
    }
    return 0;
}

