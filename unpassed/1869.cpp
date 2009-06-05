#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
enum {
    SIZ = 1004,
    UP  = 0x01,
    DN  = 0x02,
    OV  = 0x03,
};
template<int N>
class union_set {
    int par[N];
    int num;
  public:
    void init(int n);
    int getPar(int a);
    bool same(int a, int b);
    int connect(int a, int b);
};

template<int N>
void union_set<N>::init(int n){
    num = n;
    for(int i=0;i<num;i++){
        par[i] = i;
    }
}

template<int N>
int union_set<N>::getPar(int a){
    int p = par[a];
    while(p != par[p]){
        p = par[p];
    }
    return par[a] = p;
}

template<int N>
bool union_set<N>::same(int a, int b){
    a = getPar(a); b = getPar(b);
    return (a == b);
}

template<int N>
int union_set<N>::connect(int a, int b){
    a = getPar(a); b = getPar(b);
    if(a < b){
        par[b] = a;
        return a;
    } else if(a > b){
        par[a] = b;
        return b;
    } 
}

struct Circle {
    double x, y, r;
    unsigned flag;

    double getLpoint(double x0){
        double t = r*r - (x-x0)*(x-x0);
        t = y - sqrt(t);
        return t;
    }

    double dis(const Circle&r){
        return sqrt((x-r.x)*(x-r.x) + (y-r.y)*(y-r.y));
    }

    bool touch(const Circle&r){
        return dis(r)<=max(this->r, r.r);
    }

    bool exLeft(){
        return x-r<=0;
    }
    bool exRight(){
        return x+r>=1000;
    }
    bool exLow(){
        return y-r<=0;
    }
    bool exHigh(){
        return y+r>=1000;
    }

};

int num;
union_set<SIZ> us;
Circle snake[SIZ];
vector<int> tl, tr;

struct cmp{
    bool operator()(const int &l, const int &r){
        return snake[l].y < snake[r].y;
    }
};

double check(vector<int> &tv, double line){
    double ret = 1000.0, v;
    int par = -1, t, p;
    sort(tv.begin(), tv.end(), cmp());
    for(int i=0; i<tv.size(); i++){
        t = tv[i];
        if( (snake[t].flag & UP) == 0) // don't touch up
            continue;
        p = us.getPar(t);
        if( p!=par && par >= 0)
            break;
        par = p;
        v = snake[t].getLpoint(line);
        if(v<0)
            v = 0;
        ret = min(ret, v);
    }

    return ret;
}

bool fun(){
    int i, j, p;
    for(i=1; i<num; i++){
        for(j=0; j<i; j++){
            if(!us.same(i,j)&&snake[i].touch(snake[j])){
                snake[i].flag |= snake[j].flag;
                p = us.connect(i,j);
                snake[p].flag |= snake[i].flag;
                if(snake[p].flag == OV){
                    return false;
                }
            }
        }
    }

    double fro = check(tl, 0.0);
    double end = check(tr, 1000.0);
    printf("Bill enters at (0.00, %.2lf) and leaves at (1000.00, %.2lf).\n",
            fro, end);
    return true;
}

int readIn(){
    if(scanf("%d",&num)<0)
        return 0;
    tl.clear();
    tr.clear();
    us.init(num);
    for(int i=0; i<num; i++){
        snake[i].flag = 0;
        scanf("%lf%lf%lf ", &snake[i].x, &snake[i].y, &snake[i].r);
        if(snake[i].exHigh()){
            snake[i].flag |= UP;
        }
        if(snake[i].exLow()){
            snake[i].flag |= DN;
        }
        if(snake[i].exLeft()){
            tl.push_back(i);
        }
        if(snake[i].exRight()){
            tr.push_back(i);
        }
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        if(!fun()){
            printf("Bill will be bitten.\n");
        }
    }

    return 0;
}

