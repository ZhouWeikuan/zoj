#include<iostream>
#include<queue>
#include<set>
using namespace std;
enum {
    SIZ = 204,
};
int num;
multiset<int> str;
multiset<int>::iterator it;
int deg[SIZ]; // positive for in, negative for out
int pred[SIZ];

int path(int e){
    int i, r;
    queue<int> q;
    memset(pred, -1, sizeof(pred));
    pred[e] = e;
    q.push(e);
    bool flag = false;
    while(!q.empty()){
        e = q.front(); q.pop();
        if(deg[e] < 0){
            flag = true;
            break;
        }
        for(i=0; i<num; i++){
            r = (e<<16)|i;
            if(pred[i]!=-1 || str.find(r) == str.end())
                continue;
            pred[i] = e;
            q.push(i);
        }
    }
    if(flag == false) return -1;
    r = e;
    while(pred[e] != e){
        i = pred[e];
        it = str.find((i<<16)|e);
        str.erase(it);
        str.insert((e<<16)|i);
        e = i;
    }
    return r;
}

bool fun(){
    int i, j;
    set<int> s;
    for(i=0; i<num; i++){
        if(deg[i] % 2 != 0) return false;
        if(deg[i] > 0) s.insert(i);
    }
    while(s.size() ){
        i = *s.begin();
        s.erase(i);
        while(deg[i] > 0){
            j = path(i);
            if(j < 0) return false;
            deg[i] -= 2;
            deg[j] += 2;
            if(deg[j] > 0){
                s.insert(j);
            }
        }
    }
    return true;
}

void readIn(){
    int p, a, b, v;
    scanf("%d%d", &num, &p);
    memset(deg, 0, sizeof(deg));
    str.clear();
    for(;p--;){
        scanf("%d%d%d", &a, &b, &v);
        a--, b--;
        deg[a] --;
        deg[b] ++;
        if(v == 0){
            str.insert((b<<16)|a);
        }
    }
}
int main(){
    int tst;
    const char *ans[2] = {"impossible", "possible"};
    scanf("%d", &tst);
    while(tst--){
        readIn();
        printf("%s\n", ans[fun()]);
    }

    return 0;
}

