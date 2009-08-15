#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

unsigned int sum;
bool vis[1000002];
vector<int> mon;

bool fun(){
    memset(vis, false, sizeof(vis[0])*(sum+1));
    vis[0] = true;
    for (int i=0; i<=sum; ++i){
        if (vis[i]==false) continue;
        if (i && vis[sum%i]){
            return true;
        }
        for (int j=0; j<mon.size(); ++j){
            int t = i + mon[j];
            if (t > sum) continue;
            if (!vis[t]){
                vis[t] = true;
            }
        }
    }
    return false;
}

void gen(set<int> &tab, int v){
    tab.insert(v);
    while(v%2==0){
        v /= 2;
        tab.insert(v);
    }
}

void readIn(){
    double v;
    int n, t;
    set<int> tab;
    scanf("%lf", &v);
    sum = v * 100;
    scanf("%d", &n);
    while(n-- > 0){
        scanf("%d", &t);
        t *= 100;
        gen(tab, t);
    }
    mon.resize(tab.size());
    copy(tab.begin(), tab.end(), mon.begin());
}

int main(){
    int tst;
    const char *ans[] = {"no", "yes"};
    scanf("%d", &tst);
    while(tst--> 0){
        readIn();
        printf("%s\n", ans[fun()]);
    }

    return 0;
}

