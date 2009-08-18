#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
enum {
    LEN = 17,
    SIZ = 25004,
};
struct Node {
    int len, ord;
    char str[LEN];
};
int num, ans;
Node wrd[SIZ];

struct cmp {
    bool operator()(const int&a, const int&b)const {
        if (wrd[a].ord != wrd[b].ord)
            return wrd[a].ord > wrd[b].ord;
        return a > b;
    }
};

set<int, cmp> lad[LEN];
set<int, cmp>::iterator it;

bool distSame(char *s, char *e){
    while(*s && *e && *s==*e){
        ++s, ++e;
    }
    if (!*s) return true;
    return strcmp(s+1, e+1)==0;
}

// len(s) < len(e)
bool distDiff(char *s, char *e){
    while(*s && *s==*e)
        ++s,++e;
    return strcmp(s,e+1)==0;
}

void update(Node &o, int a, int pos){
    int p;
    for (it=lad[pos].begin(); it!=lad[pos].end(); ++it){
        p = *it;
        if (a == pos){
            if (distSame(o.str, wrd[p].str)){
                o.ord = max(o.ord, wrd[p].ord+1);
                break;
            }
        } else if (a < pos) {
            if (distDiff(o.str, wrd[p].str)){
                o.ord = max(o.ord, wrd[p].ord+1);
                break;
            }
        } else if (a > pos){
            if (distDiff(wrd[p].str, o.str)){
                o.ord = max(o.ord, wrd[p].ord+1);
                break;
            }
        }
    }
}

int main(){
    ans = 0;
    num = 0;
    while(scanf("%s", wrd[num].str) > 0){
        wrd[num].len = strlen(wrd[num].str);
        wrd[num].ord = 1;
        if (wrd[num].len > 1){
            update(wrd[num], wrd[num].len, wrd[num].len-1);
        }
        update(wrd[num], wrd[num].len, wrd[num].len);
        if (wrd[num].len+1 < LEN)
            update(wrd[num], wrd[num].len, wrd[num].len+1);
        lad[wrd[num].len].insert(num);
        ans = max(ans, wrd[num].ord);
        ++num;
    }
    printf("%d\n", ans);
    return 0;
}

