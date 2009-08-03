#include<iostream>
#include<algorithm>
#include<queue>
//WA
using namespace std;
enum {
    SIZ = 50008,
};
struct Node {
    int i,o,s,e;
};
struct Elem{
    int r,c;
    bool operator<(const Elem &e)const{
        if(r != e.r) return r<e.r;
        return c<e.c;
    }
};
int num, pos, sign;
int ptr[SIZ];
Node tree[SIZ];
Elem stak[SIZ*2];

void fun(){
    pos = sign = 0;
    tree[0].i = 0;
    stak[pos].r = 0;
    stak[pos].c = 0;
    int r,c;
    while(pos >=0){
        r = stak[pos].r;
        c = stak[pos].c;
        if(tree[r].e == c){
            tree[r].o = ++sign;
            pos--;
            continue;
        }
        stak[pos].c++;
        r = ptr[c];
        c = tree[r].s;
        tree[r].i = ++sign;
        stak[++pos].r = r;
        stak[pos].c = c;
    }
}
void readIn(){
    int i, mid;
    pos = 2 * (num -1);
    for(i=0; i<pos; i+=2){
        tree[i].o = 0;
        scanf("%d%d",&stak[i].r, &stak[i].c);
        stak[i+1].r = stak[i].c;
        stak[i+1].c = stak[i].r;
    }
    if (num <= 2) return;
    tree[i].o = 0;
    sort(stak, stak+pos);
    sign = 0;
    queue<int> q;
    q.push(0);
    tree[0].o = 1;
    int low, high;
    while(!q.empty()){
        i = q.front(); q.pop();
        low = 0, high = pos;
        while(low <= high){
            mid = (low + high)/2;
            if(stak[mid].r < i){
                low = mid + 1;
            } else if(stak[mid].r >= i){
                high = mid - 1;
            }
        }
        mid = low;
        tree[i].s = sign;
        for(; stak[mid].r==i; mid++){
            low = stak[mid].c;
            if(tree[low].o != 0 ) 
                continue;
            tree[low].o = 1;
            ptr[sign++] = low;
            q.push(low);
        }
        tree[i].e = sign;
    }
}
inline bool embrace(int p, int c){
    return tree[p].i<=tree[c].i&&tree[p].o>=tree[c].o;
}
int check(int p, int a, int b){
    int s, e, m;
    s = tree[p].s; e = tree[p].e;
    while(s <= e){
        m = (s + e)/2;
        if(tree[ptr[m]].o < tree[a].i){
            e = m - 1;
        } else if(tree[ptr[m]].i > tree[a].o){
            s = m + 1;
        } else {
            break;
        }
    }
    s = m;
    if(embrace(ptr[s], a)&&embrace(ptr[s], b)){
        return 0;
    }
    return 1;
}
void query(){
    int q, a, b, c, t;
    static const char *ans[2] = {"No","Yes"};
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&a,&b,&c);
        if (a==c || b == c)
            t = 1;
        else if(embrace(c, a)){
            if(embrace(c, b)){
                t = check(c, a, b);
            } else {
                t = 1;
            }
        } else if(embrace(c, b)){
            t = 1;
        } else {
            t = 0;
        }
        printf("%s\n", ans[t]);
    }
}
int main(){
    int tstcase=0;
    while(scanf("%d",&num) > 0){
        if(tstcase++){
            printf("\n");
        }
        readIn();
        fun();
        printf("Case %d:\n", tstcase);
        query();
    }
    return 0;
}

