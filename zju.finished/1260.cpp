#include<iostream>
using namespace std;
// this need improvement
enum {
    SIZ = 108,
    MaxN = 999999,
};
struct Node {
    int s, n;
    int v;
    int cmp;
};
struct Ran{
    int l, r;
    bool undef;
    bool operator !=(const Ran&rhs)const{
        return l!=rhs.l||r!=rhs.r;
    }
    void great(int t){
        t++;
        l = adjust(l + t);
        r = MaxN;
    }
    void less(int t){
        t--;
        l = -MaxN;
        r= adjust(r+t);
    }
    void inter(const Ran&rhs){
        l = max(l, rhs.l);
        r = min(r, rhs.r);
    }
    int adjust(int t){
        if(t < -MaxN)  t = -MaxN;
        else if(t > MaxN)  t = MaxN;
        return t;
    }
};
int num, cnt;
Ran sum[SIZ];
Node tree[SIZ];

int fun(){
    int k;
    bool flag;
    for(k=1; k<=num; k++){
        sum[k].undef = true;
    }
    sum[0].l = 0; sum[0].r = 0; sum[0].undef = false;
    Ran one;
    flag = true;
    while( flag ){
        flag = false;
        for(int i=0; i<cnt; i++){
            if(sum[tree[i].s].undef && sum[tree[i].n].undef){
                continue;
            }
            if(sum[tree[i].s].undef){
                flag = true;
                one = sum[tree[i].n];
                if(tree[i].cmp == 1){
                    one.less(-tree[i].v);
                } else {
                    one.great(-tree[i].v);
                }
                sum[tree[i].s] = one;
            } else if(sum[tree[i].n].undef){
                flag = true;
                one = sum[tree[i].s];
                if(tree[i].cmp ==1){
                    one.great(tree[i].v);
                } else {
                    one.less(tree[i].v);
                }
                sum[tree[i].n] = one;
            } else { // detect conflicts.
                one = sum[tree[i].s];
                if(tree[i].cmp ==1){
                    one.great(tree[i].v);
                } else {
                    one.less(tree[i].v);
                }
                one.inter(sum[tree[i].n]);
                if(one.r < one.l) return 0;
                if(sum[tree[i].n] != one){
                    sum[tree[i].n] = one;
                    flag = true;
                }

                one = sum[tree[i].n];
                if(tree[i].cmp == 1){
                    one.less(-tree[i].v);
                } else {
                    one.great(-tree[i].v);
                }
                one.inter(sum[tree[i].s]);
                if(one != sum[tree[i].s]){
                    sum[tree[i].s] = one;
                    flag = true;
                }
            }
        }
        if(flag == false){
            for(k=1;k<=num;k++){
                if(sum[k].undef){
                    flag = true;
                    sum[k].undef = false;
                    sum[k].l = sum[k].r = 0;
                    break;
                }
            }
        }
    }
    return 1;
}
int readIn(){
    scanf("%d", &num);
    if(num == 0) return 0;
    scanf("%d", &cnt);
    memset(tree, 0, sizeof(tree));
    char str[4];
    for(int i=0; i<cnt; i++){
        scanf("%d%d%s%d", &tree[i].s, &tree[i].n, str, &tree[i].v);
        tree[i].s--;
        if(str[0] =='g'){
            tree[i].cmp = 1;
        } else {
            tree[i].cmp = 0;
        }
        tree[i].n += tree[i].s + 1;
    }
    return 1;
}
int main(){
    const char * ans[2] = {
        "successful conspiracy",
        "lamentable kingdom"
    };

    while(readIn() > 0){
        printf("%s\n", ans[fun()]);
    }
    return 0;
}

