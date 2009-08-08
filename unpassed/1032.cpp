#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
enum {
    SIZ = 104,
    LIM = -99999,
};
struct Node {
    int x, y;
    bool operator < (const Node&o)const {
        if (x!=o.x){
            return x < o.x;
        }
        return y<o.y;
    }
};
int num, line, sum;
Node pnt[SIZ];
double area;
map<int, vector<Node> > tab;

int merge(vector<Node>& x){
    sort(x.begin(), x.end());
    int r = 0;
    int d = 0, lastx = -LIM;
    for (int i=0; i<x.size(); ++i){
        if (x[i].y == 0){ // enter;
            if (++d == 1){
                lastx = x[i].x;
            }
        } else { // leave;
            if (d){
                --d;
                if (d == 0){
                    r += (x[i].x - lastx + 1);
                    lastx = x[i].x;
                }
            }
        }
    }
    if (d){
        r += (x.back().x-lastx + 1);
    }
    return r;
}

void fun(){
    static int tst = 0;
    for (map<int,vector<Node> >::iterator it=tab.begin();
            it!=tab.end(); ++it){
        sum += merge(it->second);
    }
    printf("Scenario #%d:\n", ++tst); 
    printf("%d %d %.1lf\n\n", sum-line, line, area);
}

double calc(const Node&a, const Node&b){
    double t = b.y*a.x-b.x*a.y;
    t/=2;
    return t;
}

void update(int x, Node o){
    tab[x].push_back(o);
}

int count(int p, Node s, Node e){
    int t;
    Node o;
    bool rev = false;
    if (s.x==e.x){
        if (s.y > e.y){
            rev = true;
            swap(s, e);
        }
        t = o.y - o.x + 1;
        p = (p + 1)%num;
        if (pnt[p].x < e.x){ 
            o.x = e.y;
            if (rev){
            } else {
                o.y = 1;
            }
            update(s.x, nx);
        }
        p = (p + num - 3) % num;
        if (pnt[p].x < s.x){
            o.y = 0;
            update(s.x, o);
        }
        return t;
    }
    if (s.x > e.x){
        swap(s, e);
        rev = true;
    }
    t = 0;
    for (int x=0; x+s.x<=e.x; ++x){
        o.y = s.y + x*(e.y-s.y)/(e.x-s.x);
        if (x*(e.y-s.y)%(e.x-s.x)!=0){
            if (rev){
                --o.y;
            } else {
                ++o.y;
            }
        } else {
            ++t;
        }
        if (rev){
            o.x = o.y;
            o.y = 1;
        } else {
            o.x = o.y;
            o.y = 0;
        }
        update(x+s.x, o);
    }
    return t;
}

void readIn(){
    scanf("%d",&num);
    sum = line = 0;
    area = 0;
    tab.clear();
    pnt[0].x = pnt[0].y = 0;
    for (int i=1; i<=num; ++i){
        scanf("%d%d", &pnt[i].x, &pnt[i].y);
        pnt[i].x += pnt[i-1].x;
        pnt[i].y += pnt[i-1].y;
        if (i){
            line += count(i, pnt[i-1], pnt[i]);
            area += calc(pnt[i-1], pnt[i]);
        }
    }
    line -= num;
}

int main(){
    int tst;

    scanf("%d",&tst);
    while(tst--){
        readIn();
        fun();
    }

    return 0;
}

