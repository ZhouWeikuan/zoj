#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 计算子树的最大所需数目，按大到小排序，以确定子树剩下根时的所需数目
enum {
    SIZ = 208,
};
struct Node {
    int cnt;
    vector<int> cld;
};
int num;
Node tree[SIZ];

void calc(int r){
    if(tree[r].cld.size() == 0){
        tree[r].cnt = 1;
        return;
    }
    vector<int> v;
    for(vector<int>::iterator it = tree[r].cld.begin();
            it!=tree[r].cld.end(); ++it){
        calc(*it);
        v.push_back(tree[*it].cnt);
    }
    sort(v.begin(), v.end(), greater<int>());
    int m = 0, t;
    for(int i=0; i<v.size(); i++){
        t = i + v[i];
        if(m < t){
            m = t;
        }
    }
    tree[r].cnt = m;
}

void readIn(){
    int i, p, r, t;
    for(i=0; i<num; i++){
        scanf("%d%d", &p, &r);
        tree[p].cld.clear();
        while(r--){
            scanf("%d",&t);
            tree[p].cld.push_back(t);
        }
    }
}
int fun(){
    calc(1);
    return tree[1].cnt;
}
int main(){
    int tstcase;
    scanf("%d", &tstcase);
    while(tstcase --){
        scanf("%d", &num);
        readIn();
        printf("%d\n", fun());
    }
    return 0;
}

