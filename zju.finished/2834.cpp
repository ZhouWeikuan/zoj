#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
enum {
    SIZ = 1004,
};

struct Node {
    int tim, par;
    int full, half, tot;
    vector<int> cld;
};

int num;
Node tree[SIZ];
vector<int> root;


extern void calc(int);
inline int calcHalf(int p){
    if (tree[p].half != -1) return tree[p].half;
    calc(p);
    return tree[p].half;
}

inline int calcFull(int p){
    if (tree[p].full != -1) return tree[p].full;
    calc(p);
    return tree[p].full;
}

inline int calcTot(int p){
    if (tree[p].tot != -1) return tree[p].tot;
    calc(p);
    return tree[p].tot;
}

inline int distF(int p){
    return calcFull(p) - calcHalf(p);
}
int inline distT(int p){
    return calcTot(p) - calcHalf(p);
}

struct xxcmp{
    bool operator ()(const int&a, const int&b) const {
        return distT(a) > distT(b);
    }
}tot_cmp;

struct yycmp{
    bool operator ()(const int&a, const int&b) const {
        return distF(a) > distF(b);
    }
}ful_cmp;


void calc(int p){
    if (tree[p].cld.size() == 0){
        tree[p].half = 0;
        tree[p].full = tree[p].tim;
        tree[p].tot = tree[p].tim;
        return;
    } 
    // half[i] = one total + other halves,  for all children
    // full[i] = himself + one total + one full + other halves, for all children
    // tot[i]  = himself and all children
    if (tree[p].cld.size() == 1){
        tree[p].half = calcTot(tree[p].cld[0]);
        tree[p].full = tree[p].tim + calcTot(tree[p].cld[0]);
        tree[p].tot = tree[p].tim + calcTot(tree[p].cld[0]);
        return;
    }
    int i, a, b, sum = 0;
    // update total
    tree[p].tot = tree[p].tim;
    for (i=0; i<tree[p].cld.size(); ++i){
        sum += calcHalf(tree[p].cld[i]);
        tree[p].tot += calcTot(tree[p].cld[i]);
    }
    // update half
    tree[p].half = sum;
    for (i=0; i<tree[p].cld.size(); ++i){
        sum += distT(tree[p].cld[i]);
        tree[p].half = max(sum, tree[p].half);
        sum -= distT(tree[p].cld[i]);
    }

    tree[p].full = sum;
    int v = sum;
    sort(tree[p].cld.begin(), tree[p].cld.end(), tot_cmp);
    v += distT(tree[p].cld[0]);
    sort(tree[p].cld.begin()+1, tree[p].cld.end(), ful_cmp);
    v += distF(tree[p].cld[1]);
    tree[p].full = max(tree[p].full, v);

    v = sum;
    sort(tree[p].cld.begin(), tree[p].cld.end(), ful_cmp);
    v += distF(tree[p].cld[0]);
    sort(tree[p].cld.begin()+1, tree[p].cld.end(), tot_cmp);
    v += distT(tree[p].cld[1]);
    tree[p].full = max(tree[p].full, v);

    tree[p].full += tree[p].tim;
}

void fun(){
    int sum = 0;
    for (int i=0; i<root.size(); ++i){
        calc(root[i]);
        int v = calcFull(root[i]);
        sum += v;
    }
    printf("%d\n", sum);
}

int readIn(){
    scanf("%d", &num);
    if (num == 0) return 0;
    root.clear();
    int i, p;
    for (i=0; i<num; ++i){
        tree[i].cld.clear();
        tree[i].half = tree[i].full = tree[i].tot = -1;
        scanf("%d", &tree[i].tim);
    }
    for (i=0; i<num; ++i){
        scanf("%d", &p);
        if (p < 0) {
            root.push_back(i);
            continue;
        }
        tree[p].cld.push_back(i);
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

