#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
enum {
    SIZ = 104,
};

struct Node {
    int maxnum;
    set<int> mem;
};

int num, val;
int matnum, sqnum;
set<int> match[SIZ];
Node square[SIZ];

struct myGreater{
    bool operator()(const int&a, const int&b){
        return match[a].size() > match[b].size();
    }
};

inline int getV(int x, int y){
    if (x>=num || y>num) return -1;
    return x*(2*num+1)+y+1+num;
}
inline int getH(int x, int y){
    if (x>num || y>=num) return -1;
    return x*(2*num+1)+y+1;
}

void init(){
    int i, j, a;
    for (i=0; i<SIZ; ++i)
        match[i].clear();
    for (i=0; i<SIZ; ++i){
        square[i].maxnum = 0;
        square[i].mem.clear();
    }
    matnum = getH(num, num-1) + 1;
    sqnum = 0;
    for (a=0; a<num; ++a){
        for (i=0; i+a<num; ++i){
            for (j=0; j+a<num; ++j){
                int k, t;
                for (k=0; k<=a; ++k){ // horizonally
                    t = getH(i, j+k);
                    square[sqnum].mem.insert(t);
                    match[t].insert(sqnum);

                    t = getH(i+a+1, j+k);
                    square[sqnum].mem.insert(t);
                    match[t].insert(sqnum);

                    t = getV(i+k, j);
                    square[sqnum].mem.insert(t);
                    match[t].insert(sqnum);

                    t = getV(i+k, j+a+1);
                    square[sqnum].mem.insert(t);
                    match[t].insert(sqnum);

                }
                ++sqnum;
            }
        }
    }
    for (i=0; i<SIZ; ++i){
        square[i].maxnum = square[i].mem.size();
    }
}

void removeMatch(int m){
    for (set<int>::iterator it=match[m].begin(); 
            it != match[m].end(); ++it){
        square[*it].mem.erase(m);
    }
}

void restoreMatch(int m){
    for (set<int>::iterator it=match[m].begin(); 
            it != match[m].end(); ++it){
        square[*it].mem.insert(m);
    }
}

void check(int d){
    if (d >= val) return;
    int i;
    for(i=0; i<sqnum&&square[i].mem.size()<square[i].maxnum; ++i){
        ;
    }
    if (i==sqnum){
        if (d < val)
            val = d;
        return;
    }
    vector<int> v(square[i].mem.begin(), square[i].mem.end());
    sort(v.begin(), v.end(), myGreater());
    for(i=0; i<v.size(); ++i){
        removeMatch(v[i]);
        check(d+1);
        restoreMatch(v[i]);
    }
}

void fun(){
    check(0);
    printf("%d\n", val);
}

void readIn(){
    int n, v;
    scanf("%d%d ", &num, &n);
    init();
    while(n--){
        scanf("%d ", &v);
        removeMatch(v);
    }
    val = SIZ;
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst--){
        readIn();
        fun();
    }

    return 0;
}

