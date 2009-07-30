#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
enum {
    SIZ = 104,
};

using namespace std;
struct Node {
    int pos, wid, pri;
    bool operator < (const Node&o) const {
        if (wid != o.wid)
            return wid < o.wid;
        return pri > o.pri;
    }
};

int num, dev;
int price[SIZ];
Node tree[SIZ*SIZ];

void fun(){
    double ans = 0, sum = 0;
    memset(price, 0, sizeof(price));
    for (int i=dev-1; i>=0; --i){
        if (price[tree[i].pos] == 0){
            price[tree[i].pos] = tree[i].pri;
            sum += tree[i].pri;
            --num;
        } else if(price[tree[i].pos] > tree[i].pri) {
            sum -= price[tree[i].pos];
            sum += tree[i].pri;
            price[tree[i].pos] = tree[i].pri;
        }
        if (num == 0){
            double v = tree[i].wid / sum;
            if ( v > ans)
                ans = v;
        }
    }
    printf("%.3lf\n", ans);
}

void readIn(){
    scanf("%d", &num);
    dev = 0;
    int n;
    for (int i=0; i<num; ++i){
        scanf("%d", &n);
        while(n--){
            scanf("%d%d", &tree[dev].wid, &tree[dev].pri);
            tree[dev].pos = i;
            ++dev;
        }
    }
    sort(tree, tree+dev);
}

int main(){
    int tst;

    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
    }

    return 0;
}

