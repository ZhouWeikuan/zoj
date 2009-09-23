#include<iostream>
#include<vector>
#include<set>
using namespace std;
enum {
    SIZ = 1004,
    LEN = 12,
};

int cow[SIZ][LEN];
int idx;
struct cmp {
    bool operator () (int a, int b) const {
        if (cow[a][idx] != cow[b][idx])
            return cow[a][idx] < cow[b][idx];
        return a < b;
    }
};

struct Node {
    int len;
    set<int, cmp> tab[LEN];
    Node(){
    }
    void reset(int l){
        len = l;
        for (int i=0; i<len; ++i){
            idx = i;
            tab[i].clear();
        }
    }
    void remove(int p){
        for (int i=0; i<len; ++i){
            idx = i;
            tab[i].erase(p);
        }
    }
    void insert(int p){
        for (int i=0; i<len; ++i){
            idx = i;
            tab[i].insert(p);
        }
    }
    pair<int, int> getTop(int d){// return (number, index)
        d %= len; 
        pair<int, int> one;
        set<int, cmp>::iterator it = tab[d].begin();
        one.first = cow[*it][d], one.second = *it;
        ++it;
        if (it!=tab[d].end() && cow[*it][d] == one.first){
            one.second = -1;
        }
        return one;
    }
    bool empty(){
        return tab[0].empty();
    }
};

Node tree[LEN];
int ptr[LEN], num, cownum;

int gcd(int a, int b){
    int t;
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int lcm(){
    int r = 1;
    for (int i=0; i<num; ++i){
        r *= ptr[i]/gcd(r, ptr[i]);
    }
    return r;
}


void fun(){
    int curDay = 0, lastDay = -1;
    pair<int, int> res, one;
    const int LIM = lcm() + 1;
    while(num && curDay - lastDay < LIM) {
        int i, j;
        res = tree[ptr[0]].getTop(curDay);
        j = 0;
        for (i=1; i<num; ++i){
            one = tree[ptr[i]].getTop(curDay);
            if (res.first < one.first){
                ;
            } else if (res.first > one.first){
                res.first = one.first;
                res.second = one.second;
                j = i;
            } else {
                res.second = -1;
            }
        }

        if (res.second != -1){
            tree[ptr[j]].remove(res.second);
            --cownum;
            if (tree[ptr[j]].empty()){
                for (i=j+1; i<num; ++i){
                    ptr[i-1] = ptr[i];
                }
                --num;
            }
            lastDay = curDay;
        }
        
        ++curDay;
    }
    ++lastDay;
    printf("%d %d\n", cownum, lastDay);
}

int readIn(){
    int i, d, j;
    for (i=0; i<LEN; ++i){
        tree[i].reset(i);
    }
    scanf("%d", &cownum);
    for (i=0; i<cownum; ++i){
        scanf("%d", &d);
        for (j=0; j<d; ++j){
            scanf("%d", &cow[i][j]);
        }
        tree[d].insert(i);
    }

    num = 0;
    for (i=0; i<LEN; ++i){
        if (tree[i].empty()) continue;
        ptr[num++] = i;
    }
}

int main(){
    int tn;
    scanf("%d", &tn);
    while(tn-- > 0){
        readIn();
        fun();
    }

    return 0;
}

