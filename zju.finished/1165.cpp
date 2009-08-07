#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
using namespace std;
enum {
    SIZ = 308,
};
int gcd(int a, int b){
    int t;
    if(a < b){
        t = a; a = b; b = t;
    }
    while(b != 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

struct Point {
    int x, y;
    int cmp(const Point&o)const{
        if (x!=o.x) return x-o.x;
        return y-o.y;
    }
    bool operator<(const Point&o)const{
        return cmp(o) < 0;
    }
};
struct Seg {
    Point pos; // position
    Point slp; // slope
    int ptr;
    int cmp(const Seg&o)const {
        if (slp.y==0||o.slp.y==0){ // non-limited 
            if (slp.y==0)
                return o.slp.y==0?0:1;
            return -1;
        }
        return slp.x*o.slp.y - slp.y*o.slp.x;
    }
    bool operator <(const Seg &o)const{
        return cmp(o) < 0;
    }
    void subtract(const Point &o){
        slp.x = pos.x - o.x;
        slp.y = pos.y - o.y;
        if (slp.y < 0) { 
            slp.x = -slp.x;
            slp.y = -slp.y;
        }
        if (slp.y && slp.x){
            int d = gcd(slp.y, slp.x>0?slp.x:-slp.x);
            slp.y /= d;
            slp.x /= d;
        }
    }
};
struct vcmp {
    bool operator()(const vector<Point>&a, const vector<Point>&b)const {
        int i, j;
        for (i=0, j=0; i<a.size()&&j<b.size(); ++i,++j){
            int t = a[i].cmp(b[i]);
            if (t!=0) return t<0;
        }
        if (j<b.size()) return true;
        return false;
    }
};

int num;
Seg seg[SIZ];
bool mat[SIZ][SIZ];
set<vector<Point>, vcmp> res;
set<vector<Point>, vcmp>::iterator it;

void mark(int s, int e, int v){
    int i,j;
    for (i=s; i<e; ++i){
        mat[seg[i].ptr][v] = true;
        mat[v][seg[i].ptr] = true;
        for (j=i+1; j<e; ++j){
            mat[seg[i].ptr][seg[j].ptr] = true;
            mat[seg[j].ptr][seg[i].ptr] = true;
        }
    }
}

void collect(int s, int e, Seg &g){
    if (e-s<2) return;
    vector<Point> v;
    mark(s, e, g.ptr);
    while(s<e){
        v.push_back(seg[s].pos);
        ++s;
    }
    v.push_back(g.pos);
    sort(v.begin(), v.end());
    res.insert(v);
}

void fun(){
    int i, p;
    memset(mat, false, sizeof(mat));
    res.clear();
    while(num-- >= 3){
        p = 0;
        for(i=0; i<num; ++i){
            if (mat[seg[i].ptr][seg[num].ptr]){
                if (p!=i){
                    swap(seg[i], seg[p]);
                }
                ++p;
                continue;
            }
            seg[i].subtract(seg[num].pos);
        }
        sort(seg+p, seg+num);
        for (i=p+1; i<num; ++i){
            int t = seg[i].cmp(seg[p]);
            if (t > 0){
                collect(p, i, seg[num]);
                p = i;
            }
        }
        collect(p, i, seg[num]);
    }
}

void output(){
    if (res.empty()){
        printf("No lines were found\n");
        return;
    }
    int i;
    printf("The following lines were found:\n");
    for (it=res.begin(); it!=res.end(); ++it){
        for (i=0; i<(*it).size(); ++i){
            printf("(%4d,%4d)", (*it)[i].x, (*it)[i].y);
        }
        printf("\n");
    }
}

int readIn(){
    num = 0;
    scanf("%d%d",&seg[num].pos.x, &seg[num].pos.y);
    while(seg[num].pos.x != 0 || seg[num].pos.y != 0){
        seg[num].ptr = num;
        ++num;
        scanf("%d%d",&seg[num].pos.x, &seg[num].pos.y);
    }
    return num;
}

int main(){
    while( readIn() > 0 ){
        fun();
        output();
    }
    return 0;
}

