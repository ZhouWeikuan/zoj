#include<iostream>
#include<cstring>
#include<cstdlib>
#include<set>
using namespace std;
int mDays[13]={
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
bool isLeap(int y){
    if (y%400==0) return true;
    if (y%100==0) return false;
    if (y%4==0) return true;
    return false;
}
int toInt(int y, int m, int d){
    --d;
    if (m > 2) d += isLeap(y);
    while(m > 1){
        --m;
        d += mDays[m];
    }
    while (y > 1700){
        --y;
        d += 365 + isLeap(y);
    }
    return d;
}

void toDate(int num, int &y, int &m, int &d){
    y = 1700, m = 1, d = 0;
    while (num >= 365 + isLeap(y)){
        num -= 365 + isLeap(y);
        ++y;
    }
    while (num >= mDays[m] + (m==2&&isLeap(y)) ){
        num -= mDays[m] + (m==2&&isLeap(y));
        ++m;
    }
    d = num + 1;
}
int parse(char *s){
    int d = atoi(&s[6]); s[6]=0;
    int m = atoi(&s[4]); s[4]=0;
    int y = atoi(&s[0]); 
    return toInt(y, m, d);
}

struct Node {
    int l, h;
    bool merge(const Node&o){ // assume this.l <= o.l
        if (o.l <= h+1){
            h = max(h, o.h);
            return true;
        }
        return false;
    }
    bool valid(){
        return l<=h;
    }
    bool inter(const Node&o, Node&b){
        if (o.h<l||o.l>h) return false;
        b.h = h;
        b.l = o.h + 1;
        h = min(h, o.l-1);
        return true;
    }
    bool operator <(const Node&o)const{
        if (l!=o.l)
            return l < o.l;
        return h < o.h;
    }
};

int NX, NR;
set<Node> has, rec;
char buf[20];

void output(const Node &o){
    int y, m, d;
    toDate(o.l, y, m, d);
    printf("%d/%d/%d", m, d, y);
    if (o.h != o.l){
        toDate(o.h, y, m, d);
        printf(" to %d/%d/%d", m, d, y);
    }
    printf("\n");
}

void fun(){
    Node o, b;
    int ans = 0;
    while(!rec.empty()){
        o = *rec.begin(); rec.erase(rec.begin());
        for(set<Node>::iterator it=has.begin();
                o.valid()&&it!=has.end(); ++it){
            if (o.inter(*it, b)){
                if (b.valid()){
                    rec.insert(b);
                }
            }
        }
        if (o.valid()){
            ++ans;
            output(o);
        }
    }
    if (ans==0){
        printf("No additional quotes are required.\n");
    }
}

void conv(set<Node> &a, set<Node>&b){
    Node o;
    b.clear();
    while(!a.empty()){
        o = *a.begin(); a.erase(a.begin());
        for (set<Node>::iterator it=a.begin(); 
                it!=a.end();){
            if (o.merge(*it)){
                a.erase(it++);
            } else {
                ++it;
            }
        }
        b.insert(o);
    }
}

void readIn(){
    Node o;
    set<Node> th, tr;
    for (int i=0; i<NX; ++i){
        scanf("%s", buf);
        o.l = parse(buf);
        scanf("%s", buf);
        o.h = parse(buf);
        th.insert(o);
    }
    for (int i=0; i<NR; ++i){
        scanf("%s", buf);
        o.l = parse(buf);
        scanf("%s", buf);
        o.h = parse(buf);
        tr.insert(o);
    }
    conv(th, has);
    conv(tr, rec);
}

int main(){
    int tn = 0;
    scanf("%d%d", &NX, &NR);
    while(NX + NR){
        if (tn) printf("\n");
        printf("Case %d:\n", ++tn);
        readIn();
        fun();
        scanf("%d%d", &NX, &NR);
    }

    return 0;
}

