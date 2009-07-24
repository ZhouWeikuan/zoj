#include<iostream>
#include<vector>
#include<set>
using namespace std;
enum {
    LEN = 18,
    SIZ = 25004,
};
int num;
vector<int> ed[SIZ][LEN];
string str[SIZ];
int tab[2][LEN];
set<int> dmp[2];

int fun(){
    return 0;
    int d = 0, i;
    set<int> *cur=&dmp[0], *nex=&dmp[1], *tmp;
    for (i=0; i<num; ++i){
        cur->insert(i);
    }
    for (;!cur->empty();){
        ++d;
        nex->clear();
        for (set<int>::iterator it=cur->begin();
                it != cur->end(); ++it){
            nex->insert(ed[*it][d].begin(), ed[*it][d].end());
        }
        tmp = cur, cur = nex, nex = tmp;
    }

    return d;
}

int editDis(const string&a, const string &b){
    int * cur = tab[0], *nex = tab[1], *tmp;
    int i, j, d;
    int an = a.length(), bn = b.length();
    for (i=an; i>=0; --i)
        cur[i] = an - i;
    for (i=bn-1; i>=0; --i){
        nex[an] = bn - i;
        for (j=an-1; j>=0; --j){
            nex[j] = (a[i]!=b[j]) + cur[j+1];
            nex[j] = min(nex[j], 1 + cur[j]);
            nex[j] = min(nex[j], 1 + nex[j+1]);
        }
        tmp = cur; cur = nex; nex = tmp;
    }

    return cur[0];
}

int main(){
    char buf[LEN];
    int i, d;
    num = 0;
    while(scanf("%s ", buf) > 0){
        str[num] = buf;
        for (i=0; i<num; ++i){
            d = editDis(str[i], str[num]);
            // printf("%s <> %s -> %d\n", str[i].c_str(), str[num].c_str(), d);
            ed[i][d].push_back(num);
            ed[num][d].push_back(i);
        }

        ++num;
    }
    printf("%d\n", fun());

    return 0;
}

