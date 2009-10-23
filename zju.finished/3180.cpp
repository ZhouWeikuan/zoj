#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
enum {
    SIZ = 10,
};

struct Node {
    int dat[3];
    void read(){
        scanf("%d%d%d", &dat[0], &dat[1], &dat[2]);
        make();
    }
    void make(){
        sort(dat+0, dat+3);
    }
    bool equal(const Node &o){
        return dat[0]==o.dat[0] && dat[1]==o.dat[1] && dat[2]==o.dat[2];
    }
};

int num;
Node tree[SIZ];
Node dst, src;

void insert(const Node &o){
    for (int i=0; i<num; ++i){
        if (tree[i].equal(o)) return;
    }
    tree[num++] = o;
}

bool fun(){
    if (src.equal(dst)) return true;
    if (src.dat[0] > dst.dat[0] || dst.dat[0] + dst.dat[1] - 1!=dst.dat[2])
        return false;
    num = 0;
    tree[num++] = src;
    src.dat[2] = src.dat[1] + src.dat[0] - 1;
    src.make();
    insert(src);
    
    src=tree[0];
    src.dat[1] = src.dat[2] + src.dat[0] - 1;
    src.make();
    insert(src);

    src=tree[0];
    src.dat[0] = src.dat[2] + src.dat[1] - 1;
    src.make();
    insert(src);

    while(dst.dat[0] >= tree[0].dat[0]){
        for (int i=0; i<num; ++i){
            if (tree[i].equal(dst))
                return true;
        }
        dst.dat[2] = dst.dat[1] - dst.dat[0] + 1;
        dst.make();
    }
    
    return false;
}

void readIn(){
    dst.read(); 
    src.read();
}

int main(){
    const char *ans[2] = {
        "No", "Yes"
    };
    int tn;
    scanf("%d", &tn);
    while(tn-- > 0){
        readIn();
        bool t = fun();
        printf("%s\n", ans[t]);
    }

    return 0;
}

