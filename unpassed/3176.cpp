#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 104,
    RND = 0x01,
    TRC = 0x02,
};
const double eps = 1e-7;
const double UNIT = 0.005;
struct Range{
    int l, h;
    void merge(const Range &o){
        l = max(l, o.l);
        h = min(h, o.h);
    }
    int getType(int v){
        if (h<l) return 0;
        int r = 0;
        double t0 = 100.0* ((double)v)/l;
        double t1 = 100.0* ((double)v)/h;
        if ((int)t0 != (int)t1){
            return (RND|TRC);
        }
        t0 -= (int)t0, t1-=(int)t1;
        if (t0 <= UNIT + eps){
            return TRC;
        } else {
            return RND;
        }
    }
    void init(int v, double p){
        if (p >0){
            h = v / (p - UNIT);
            double np = 100 * double(v)/(h+1);
            np -= (int)np; np/=100;
            if (np <= UNIT + eps){
                ++h;
            }
        } else {
            h = 999999999;
        }
        l = v / (p + UNIT - eps);
        p = 100 * double(v)/l;
        p -= (int)p;
        p /= 100;
        if (p >= UNIT){
            ++l;
        }
    }
};

int num;
pair<int, double> tree[1004];
Range ran, tmp;

void fun(){
    int sum = 0x03, r = 0;
    for (int i=0; i<num; ++i){
        r = ran.getType(tree[i].first);
        sum &= r;
    }
    const char *ans[4] = {
        "Neither",
        "Rounding",
        "Truncation",
        "Either"
    };
    printf("%s\n", ans[sum]);
}

void readIn(){
    scanf("%d", &num);
    char ch;
    for (int i=0; i<num; ++i){
        scanf("%d%lf%c ", &tree[i].first, &tree[i].second, &ch);
        tree[i].second /= 100;
        tmp.init(tree[i].first, tree[i].second);
        if (i==0){
            ran = tmp;
        } else {
            ran.merge(tmp);
        }
    }
}

int main(){
    int tst;
    scanf("%d", &tst);
    while(tst-- > 0){
        readIn();
        fun();
    }

    return 0;
}

