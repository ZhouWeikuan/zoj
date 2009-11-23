#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
enum {
    SIZ = 104,
};

template<int N>
class union_set {
    int par[N];
    int num;
  public:
    void init(int n);
    int getPar(int a);
    bool same(int a, int b);
    void connect(int a, int b);
};

template<int N>
void union_set<N>::init(int n){
    num = n;
    for(int i=0;i<num;i++){
        par[i] = i;
    }
}

template<int N>
int union_set<N>::getPar(int a){
    int p = par[a];
    while(p != par[p]){
        p = par[p];
    }
    return par[a] = p;
}

template<int N>
bool union_set<N>::same(int a, int b){
    a = getPar(a); b = getPar(b);
    return (a == b);
}

template<int N>
void union_set<N>::connect(int a, int b){
    a = getPar(a); b = getPar(b);
    if(a < b){
        par[b] = a;
    } else if(a > b){
        par[a] = b;
    } 
}

union_set<SIZ> us;

struct Driver {
    int ln; // line no.
    int stn; // station
};

int linenum, drinum;
vector<int> line[SIZ];
Driver dr[SIZ];

int gcd(int a, int b){
    int t;
    if( a < b){
        t = a, a = b, b = t;
    }
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

bool check(Driver &a, Driver &b){
    if (a.ln == b.ln){
        if (a.stn == b.stn){
            return true;
        }
        return false;
    }
    int g = gcd(line[a.ln].size(), line[b.ln].size());
    for (int i=0; i<line[a.ln].size(); ++i){
        for (int j=0; j<line[b.ln].size(); ++j){
            if (line[a.ln][i] != line[b.ln][j])
                continue;
            int d = i - a.stn - (j - b.stn);
            if (d < 0) d = -d;
            if (d % g == 0){
                return true;
            }
        }
    }
    return false;
}

bool fun(){
    for (int i=0; i<drinum; ++i){
        for (int j=i+1; j<drinum; ++j){
            if (check(dr[i], dr[j])){
                us.connect(i, j);
            }
        }
    }
    for (int i=0; i<drinum; ++i){
        if (0!=us.getPar(i)){
            return false;
        }
    }
    return true;
}

int findPos(int l, int s){
    for (int i=0; i<line[l].size(); ++i){
        if (line[l][i] == s)
            return i;
    }
    return -1;
}

char readInt(int &t){
    char dem;
    scanf("%d%c", &t, &dem);
    return dem;
}

int readIn(){
    int t, d;
    scanf("%d%d%d", &linenum, &drinum, &t);
    if (linenum + drinum + t == 0)
        return 0;
    us.init(drinum);
    char dem;
    for (int i=0; i<linenum; ++i){
        line[i].clear();
        do {
            dem = readInt(t);
            line[i].push_back(t);
        } while(dem != '\n');
        do {
            readInt(t);
            dem = readInt(d);
            --d;
            dr[d].ln = i;
            dr[d].stn = findPos(i, t);
        } while(dem != '\n');
    }
    return 1;
}

int main(){
    const char * ans[2] = { "No", "Yes" };
    while(readIn() > 0){
        bool t = fun();
        printf("%s\n", ans[t]);
    }

    return 0;
}

