#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 104,
};
struct Node {
    vector<int> f;
    vector<string> s;
};

int num;
Node tree[SIZ];
bool use[SIZ];
int val[2];
string sta[3];

int getStatus(int n){
    if (n < val[0]){
        return 0;
    } else if (n < val[1]){
        return 1;
    }
    return 2;
}

void solve(int src){
    vector<int> v;
    v.push_back(src);
    memset(use, false, sizeof(use));
    use[src] = true;
    while(!v.empty()){
        src = v.back(); v.pop_back();
        int s = getStatus(tree[src].f.size());
        tree[src].s.push_back(sta[s]);
        for (int i=0; i<tree[src].f.size(); ++i){
            if (!use[tree[src].f[i]]){
                use[tree[src].f[i]] = true;
                v.push_back(tree[src].f[i]);
            }
        }
    }
    for (int i=0; i<num; ++i){
        if (!use[i]){
            tree[i].s.push_back(sta[0]);
        }
    }
}

void fun(){
    char name[SIZ];
    int src;
    scanf("%d", &src);
    while(src != 0){
        --src;
        scanf("%d%d",&val[0], &val[1]);
        scanf("%s", name); sta[0] = name;
        scanf("%s", name); sta[1] = name;
        scanf("%s", name); sta[2] = name;
        solve(src);
        scanf("%d", &src);
    }
    for (int i=0; i<num; ++i){
        scanf("%s", name);
        printf("%s: ", name);
        for (int j=0; j<tree[i].s.size(); ++j){
            printf("%s ", tree[i].s[j].c_str());
        }
        printf("\n");
    }
}

int readIn(){
    if (scanf("%d",&num)<0 || num==0) return 0;
    int n, t;
    for (int i=0; i<num; ++i){
        tree[i].f.clear();
        tree[i].s.clear();
        scanf("%d",&n);
        while(n > 0){
            --n;
            tree[i].f.push_back(n);
            scanf("%d",&n);
        }
    }

    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

