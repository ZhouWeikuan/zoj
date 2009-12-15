#include<iostream>
#include<cstdio>
#include<map>
#include<set>
using namespace std;
enum {
    SIZ = 18,
    LIM = 1<<SIZ,
};

struct Node {
    int d[2];
    Node(){}
    Node(int a, int b){d[0] = a, d[1] = b;}
    bool operator < ( const Node &o) const {
        if (d[0] != o.d[0])
            return d[0] < o.d[0];
        return d[1] < o.d[1];
    }
};
int pos;
int ans[LIM] = {0};
map<Node, int> tab;
set<Node> nei[SIZ];

int getNode(int a, int b){
    int ret;
    Node o(a, b); 
    map<Node, int>::iterator it = tab.find(o);
    if (it == tab.end()){
        tab.insert(make_pair(o, pos));
        ret = pos++;
        // printf("%d %d -> %d\n", a, b);
    } else {
        ret = it->second;
    }
    return ret;
}

void crTri(int a, int b, int c){
    int e0 = getNode(a, b);
    int e1 = getNode(b, c);
    int e2 = getNode(a, c);
    Node o;
    o.d[0] = e1, o.d[1] = e2;
    nei[e0].insert(o);
    o.d[0] = e0, o.d[1] = e2;
    nei[e1].insert(o);
    o.d[0] = e0, o.d[1] = e1;
    nei[e2].insert(o);
}

int getCount(int p, int n){
    int ret = 0;
    for (set<Node>::iterator it = nei[n].begin();
            it != nei[n].end(); ++it){
        if ( p&(1<<(*it).d[0]) && p&(1<<(*it).d[1])){
            ++ ret;
        }
    }
    return ret;
}

void init(){
    pos = 0;
    crTri(1, 2, 3); crTri(2, 4, 5); crTri(2, 3, 5);
    crTri(3, 5, 6); crTri(4, 7, 8); crTri(4, 5, 8);
    crTri(5, 8, 9); crTri(5, 6, 9); crTri(6, 9, 10);
    int d, md;
    for (int i=LIM-1; i>=0; --i){
        md = -LIM;
        for (int j=0, m=1; j<SIZ; ++j, m<<=1){
            if (i & m) continue;
            d = getCount(i, j);
            int t = ans[i|m];
            if (d){
                d += t;
            } else {
                d -= t;
            }
            md = max(d, md);
        }
        if (md == -LIM){
            ans[i] = 0;
        } else {
            ans[i] = md;
        }
    }
}

void fun(){
    int num, a, b;
    int s = 0, d = 0;
    bool player = true;
    scanf("%d", &num);
    for (int i=0; i<num; ++i){
        scanf("%d%d", &a, &b);
        a = getNode(a, b);
        int t = getCount(s, a);
        if (t){
            if (player){
                d += t;
            } else {
                d -= t;
            }
        } else {
            player = !player;
        }
        s |= 1<<a;
    }

    const char * out[2] = { "B wins.", "A wins."};
    if (player){
        d += ans[s];
    } else {
        d -= ans[s];
    }
    printf("%s\n", out[d>0]);
}

int main(){
    init();
    int gn=1, sts;
    scanf("%d", &gn);
    while(gn--){
        int no = 1, cnt;
        scanf("%d", &cnt);
        while(cnt --){
            printf("Game %d: ", no++);
            fun();
        }
        if (gn) printf("\n");
    }

    return 0;
}

