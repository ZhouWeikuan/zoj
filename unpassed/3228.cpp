#include<iostream>
#include<map>
#include<vector>
// TLE
using namespace std;
enum {
    SIZ   = 100004,
    LEN   = 7,
    BASE  = 26,
};

char dat[SIZ];
char pat[LEN];
map<int, vector<int> > tab[LEN];
int rem[LEN];

void init(){
    int v=1;
    rem[1] = 1;
    for (int i=2; i<LEN; ++i){
        v *= BASE;
        rem[i] = v;
    }
}

int noOverlap(int pos, int val, bool dup){
    map<int, vector<int> > ::iterator it=tab[pos].find(val);
    if (it == tab[pos].end()) return 0;
    vector<int> & v = it->second;
    if (dup) return (v.size()+pos-1)/pos;
    int last = -1000;
    val = 0;
    for (int i=0; i<v.size(); ++i){
        if (v[i] - last < pos)
            continue;
        ++val;
        last = v[i];
    }
    return val;
}

int hasOverlap(int pos, int val){
    map<int, vector<int> > ::iterator it=tab[pos].find(val);
    if (it == tab[pos].end()) return 0;
    vector<int> & v = it->second;
    return v.size();
}

void fun(){
    int n, a;
    int pos, v;
    scanf("%d", &n);
    while(n--){
        scanf("%d%s", &a, pat);
        v = 0;
        bool dup = true;
        for (pos=0; pat[pos]; ++pos){
            v *= BASE;
            v += pat[pos] - 'a';
            if (pos && pat[pos]!=pat[pos-1])
                dup = false;
        }

        if (a){
            printf("%d\n", noOverlap(pos, v, dup));
        } else {
            printf("%d\n", hasOverlap(pos, v));
        }
    }
}

void prepro(){
    int len = 0;
    int val[LEN] = {0};
    int i;
    for (i=1; i<LEN; ++i)
        tab[i].clear();
    for(len=0;dat[len];++len){
        for (i=1; i<LEN; ++i){
            if (len >= i){
                val[i] -= rem[i] * (dat[len-i]-'a');
            }
            val[i] *= BASE;
            val[i] += dat[len] - 'a';
            if (len + 1 >= i){
                tab[i][val[i]].push_back(len);
            }
        }
    }
}

int main(){
    int tst=1;
    init();
    while(scanf("%s", dat) > 0){
        printf("Case %d\n", tst++);
        prepro();
        fun();
        printf("\n");
    }

    return 0;
}

