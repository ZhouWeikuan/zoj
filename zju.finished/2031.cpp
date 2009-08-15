#include<iostream>
#include<set>
using namespace std;
enum {
    SIZ = 10004,
};

struct Node {
    int pos;
    char author[12];
    char type;
};
int num;
Node tree[SIZ];
int ptr[SIZ];
unsigned step[SIZ];

struct author_cmp {
    bool operator ()(const int&a, const int&b)const{
        return strcmp(tree[a].author, tree[b].author) < 0;
    }
};

struct set_cmp {
    bool operator ()(const int&a, const int&b)const{
        if (step[a] != step[b])
            return step[a] < step[b];
        return a < b;
    }
}scmp;

set<int, set_cmp> tab;
int src, dst;

void update(int p, int s, char t){
    unsigned v = step[s] + 1;
    v += (tree[s].type!=t);
    if (step[p] == -1 || step[p] > v){
        if (step[p] != -1)
            tab.erase(p);
        step[p] = v;
        tab.insert(p);
        tree[p].type = t;
    }
}

unsigned fun(){
    tab.clear();
    step[src] = 0;
    tab.insert(src);
    int nex;
    while(!tab.empty()){
        src = *tab.begin(); tab.erase(tab.begin());
        if (src == dst){
            return step[dst];
        }
        nex = (src+1)%num;
        update(nex, src, 0);

        nex = (src-1+num)%num;
        update(nex, src, 0);

        nex = ptr[(tree[src].pos+1)%num];
        update(nex, src, 1);

        nex = ptr[(num+tree[src].pos-1)%num];
        update(nex, src, 1);
    }
    return -1;
}

int readIn(){
    if (scanf("%d%d%d", &num,&src,&dst) < 0)
        return 0;
    --src, --dst;
    memset(step, -1, sizeof(step));
    for (int i=0; i<num; ++i){
        ptr[i] = i;
        tree[i].type = 0;
        scanf("%s", tree[i].author); // ignore the title
        scanf("%s", tree[i].author);
    }
    sort(ptr, ptr+num, author_cmp());
    for (int i=0; i<num; ++i){
        tree[ptr[i]].pos = i;
    }
    return 1;
}

int main(){
    
    while(readIn() > 0){
        unsigned v = fun();
        printf("%u\n", v);
    }

    return 0;
}

