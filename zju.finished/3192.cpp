#include<iostream>
#include<set>
#include<cstdio>
using namespace std;
enum {
    SIZ = 10004,
};
struct Node {
    int len, pole;
    bool operator < (const Node &o) const {
        return pole < o.pole;
    }
};

int num;
Node tree[SIZ];

void fun(){
    int l,r;
    int ret = 1;
    l = r = tree[0].pole;
    for (int i=1; i<num; ++i){
        if (r <= tree[i].pole){ // choose the current
            l = r;
            r = max(l+tree[i].len, tree[i].pole);
            ++ret;
        } else { // replace the previous
            int t = max(tree[i].pole, l+tree[i].len);
            r = min(t, r);
        }
    }
    printf("%d\n", ret);
}

void readIn(){
    for (int i=0; i<num; ++i){
        scanf("%d%d", &tree[i].len, &tree[i].pole);
    }
    sort(tree, tree+num);
}

int main(){
    scanf("%d", &num);
    while(num > 0){
        readIn();
        fun();
        scanf("%d", &num);
    }

    return 0;
}

