#include<iostream>
using namespace std;
enum {
    SIZ = 160,
};
struct Node {
    int l, r, p;
};
int next;
Node tree[SIZ];
char dat[SIZ];

int gcd(int a, int b){
    int t;
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int calc(int p){
    if (p == -1) return 1;
    int a = calc(tree[p].l);
    int b = calc(tree[p].r);
    int t = gcd(a, b);
    a *= b/t; a*=2;
    return a;
}

void fun(){
    int cur = -1;
    for (int i=0; dat[i]; ++i){
        if (dat[i] == '['){
            if (cur < 0){
            } else if (tree[cur].l == -1){
                tree[cur].l = next;
                tree[next].p = cur;
            } else if (tree[cur].r == -1){
                tree[cur].r = next;
                tree[next].p = cur;
            } else {
                int *p = 0;
                *p = 1;
                // can't be here.
            }
            cur = next;
            ++next;
        } else {
            cur = tree[cur].p;
        }
    }
    cur = calc(0);
    if (next <= 0)
        cur = 1;
    static int tn = 1;
    printf("%d %d\n", tn++, cur);
}

void readIn(){
    memset(tree, -1, sizeof(tree));
    next = 0;
    gets(dat);
}

int main(){
    int tn;
    scanf("%d", &tn);
    gets(dat);
    while(tn--){
        readIn();
        fun();
    }

    return 0;
}

