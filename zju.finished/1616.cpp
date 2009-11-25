#include<iostream>
#include<algorithm>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
enum {
    SIZ = 16,
};
set<string> tab;
set<int> nex[SIZ];
const char *ans[2] = {
    "No",
    "Yes"
};

void insert(int a, int b, int c){
    string s;
    s += (char) a;
    s += (char) b;
    s += (char) c;
    tab.insert(s);
}

int find(int a, int b){
    set<int>::iterator ia=nex[a].begin(), ib=nex[b].begin();
    while(ia!=nex[a].end() || ib!=nex[b].end()){
        if (*ia < *ib){
            ++ia;
        } else if (*ia > *ib){
            ++ib;
        } else {
            int t = *ia;
            nex[a].erase(t);
            nex[b].erase(t);
            return t;
        }
    }
    return -1;
}

void init(){
    insert(1,1,1);
    int i, j;
    for (i=1; i<SIZ; ++i){
        nex[i].clear();
        for (j=i+1; j<SIZ; ++j){
            nex[i].insert(j);
        }
    }

    int b, c;
    for (i=1; i<SIZ; ++i){
        while(!nex[i].empty()){
            b = *nex[i].begin(); nex[i].erase(nex[i].begin());
            c = find(i, b);
            if (c!= -1)
                insert(i, b, c);
        }
    }
}

void fun(int a, int b, int c){
    int arr[] = {a, b, c};
    sort(arr, arr+3);
    string s;
    s += (char)arr[0];
    s += (char)arr[1];
    s += (char)arr[2];
    set<string>::iterator it = tab.find(s);
    printf("%s\n", ans[it==tab.end()]);
}

int main(){
    int num;
    int a, b, c;
    init();
    while( scanf("%d", &num) > 0){
        if (num == 1){
            scanf("%d", &a);
            // printf("%d ", a);
            printf("%s\n", ans[a!=1]);
        } else if (num == 2){
            scanf("%d%d", &a, &b);
            // printf("%d %d ", a, b);
            printf("%s\n", ans[a==1||a!=b]);
        } else {
            scanf("%d%d%d", &a, &b, &c);
            // printf("%d %d %d ", a, b, c);
            fun(a, b, c);
        }
    }
    // fprintf(stderr, "%d\n", tab.size());
    return 0;
}

