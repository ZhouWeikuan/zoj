#include<iostream>
#include<set>
using namespace std;
enum {
    SIZ = 102,
    Enter = 0,
    Exit = 1,
    NonDisjoint = 0,
    NonContained = 1,
    NonCovering = 2,
    Ok = 3,
};
struct Rect{
    int x[2];
    int y[2];
};
struct Event {
    int val;
    int type;
    int ptr;
    bool operator<(const Event &rhs)const{
        if(val != rhs.val)
            return val<rhs.val;
        return type>rhs.type;
    }
};
int H,W,num;
Rect tree[SIZ];
Event X[SIZ*2], Y[SIZ*2];
int xnum,ynum;
int ret;

inline void update(int v){
    if(ret > v)
        ret = v;
}
void calc(set<int> &s){
    ynum = 0;
    int t,i;
    for(set<int>::iterator it = s.begin();
            it!=s.end();
            ++it){
        t = *it;
        for(int j=0;j<2;j++){
            Y[ynum].val = tree[t].y[j]; 
            Y[ynum].type = j;
            Y[ynum].ptr = t;
            ynum++;
        }
    }
    sort(Y, Y + ynum);
    if(Y[0].val > 0 || Y[ynum-1].val < H)
        update(NonCovering);
    int lasty = 0;
    int cnt = 0;
    for(i=0;i<ynum;i++){
        if(Y[i].type == Enter){
            if(++cnt > 1){
                update(NonDisjoint);
            }
            if(Y[i].val != lasty)
                update(NonCovering);
        } else {
            --cnt;
            lasty = Y[i].val;
        }
    }
}
void fun(){
    if(X[0].val > 0 || X[xnum-1].val < W){
        update(NonCovering);
    }
    int lastx = 0;
    set<int> cur;
    for(int i=0;i<xnum;i++){
        if(X[i].type == Enter){
            if(X[i].val != lastx){
                update(NonCovering);
            }
            cur.insert(X[i].ptr);
        } else {// Exit
            if(lastx != X[i].val)
                calc(cur);
            cur.erase(X[i].ptr);
            lastx = X[i].val;
        }
    }
}

void readIn(){
    cin>>W>>H>>num;
    int t;
    ret = Ok;
    xnum = ynum = 0;
    for(int i=0;i<num;i++){
        cin>> tree[i].x[0]>>tree[i].y[0]>>tree[i].x[1]>>tree[i].y[1];
        if(tree[i].x[0] > tree[i].x[1]){
            t = tree[i].x[0];
            tree[i].x[0] = tree[i].x[1];
            tree[i].x[1] = t;
        }
        if(tree[i].y[0] > tree[i].y[1]){
            t = tree[i].y[0];
            tree[i].y[0] = tree[i].y[1];
            tree[i].y[1] = t;
        }
        if(tree[i].x[0] < 0 || tree[i].x[1] > W 
                || tree[i].y[0] < 0 || tree[i].y[1] > H){
            update(NonContained);
        }
        for(int j=0;j<2;j++){
            X[xnum].val = tree[i].x[j];
            X[xnum].type = j;
            X[xnum].ptr = i;
            xnum++;
        }
    }
    sort(X, X+xnum);
}

int main(){
    const char *ans[4] = {
        "NONDISJOINT","NONCONTAINED","NONCOVERING","OK"
    };
    int tstcase;
    cin>>tstcase;
    while(tstcase--){
        readIn();
        fun();
        cout<<ans[ret]<<endl;
    }

    return 0;
}
