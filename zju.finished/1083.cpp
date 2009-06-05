#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;
enum {
    SIZ = 32,
};
struct Node {
    int l,r,u,d;
    bool enable;
    set<int> ptr;
    set<int> next;
};
Node tab[SIZ];
set<string> result;

void init(){
    for(int i=0;i<SIZ;i++){
        tab[i].u=tab[i].l=tab[i].r=tab[i].d = -1;
        tab[i].enable = false;
        tab[i].ptr.clear();
        tab[i].next.clear();
    }
}
int h,w,m;
int dat[SIZ][SIZ];
char buf[SIZ];
int top;

void readIn(){
    int i,j;
    char t;
    m = 0;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin>>t;
            if(t == '.'){
                dat[i][j] = -1;
                continue;
            }
            t -= 'A';
            if(m < t)
                m = t;
            dat[i][j] = t;
            tab[t].enable = true;
            if(tab[t].u == -1 || tab[t].u < i){
                tab[t].u = i;
            }
            if(tab[t].d == -1 || tab[t].d > i){
                tab[t].d = i;
            }
            if(tab[t].l == -1 || tab[t].l > j){
                tab[t].l = j;
            }
            if(tab[t].r == -1 || tab[t].r < j){
                tab[t].r = j;
            }
        }
    }
    m++;
}
void print_set(set<int> &s){
    set<int>::iterator it;
    for(it=s.begin(); it!=s.end(); it++){
        cout<<" "<<char(*it + 'A');
    }
    cout<<endl;
}
void print(int cur){
    cout<<"Number of "<<char(cur+'A')<<" depends: "<<tab[cur].ptr.size()<<endl;
    print_set(tab[cur].ptr);
    cout<<"Number of "<<char(cur+'A')<<" points: "<<tab[cur].next.size()<<endl;
    print_set(tab[cur].next);
}

void parse(){
    int i,j;
    int l,h;
    for(i=0;i<m;i++){
        if(tab[i].enable == false)
            continue;
        l = tab[i].d;
        h = tab[i].u;
        for(j=tab[i].l; j<= tab[i].r;j++){
            if(dat[l][j] != i){
                tab[i].ptr.insert(dat[l][j]);
                tab[dat[l][j]].next.insert(i);
            }
            if(dat[h][j] != i){
                tab[i].ptr.insert(dat[h][j]);
                tab[dat[h][j]].next.insert(i);
            }
        }
        l = tab[i].l;
        h = tab[i].r;
        for(j=tab[i].d;j<=tab[i].u;j++){
            if(dat[j][l] != i){
                tab[i].ptr.insert(dat[j][l]);
                tab[dat[j][l]].next.insert(i);
            }
            if(dat[j][h]!=i){
                tab[i].ptr.insert(dat[j][h]);
                tab[dat[j][h]].next.insert(i);
            }
        }
    }
    /*
    for(i=0;i<m;i++){
        print(i);
    }*/
}

void clear(int i, vector<int> &v){
    set<int> & s = tab[i].next;
    for(set<int>::iterator it=s.begin(); it!=s.end(); it++){
        v.push_back(*it);
        tab[*it].ptr.erase(i);
    }
    s.clear();
}

void restore(int i, vector<int> &v){
    set<int> &s = tab[i].next;
    int t;
    while(v.size()){
        t = v.back(); v.pop_back();
        s.insert(t);
        tab[t].ptr.insert(i);
    }
}

void trace(){
    if(top == m){
        buf[top] = 0;
        reverse(buf, buf+top);
        string s(buf);
        result.insert(s);
        reverse(buf, buf+top);
        return;
    }
    vector<int> v;
    for(int i=0; i<m;i++){
        if(tab[i].enable == false || tab[i].ptr.size() != 0)
            continue;
        clear(i,v);
        tab[i].enable = false;
        buf[top++] = 'A' + i;
        trace();
        --top;
        tab[i].enable = true;
        restore(i,v);
    }
}

int main(){
    while(cin>>h>>w){
        init();
        readIn();
        parse();
        top = 0;
        trace();
        for(set<string>::iterator it=result.begin(); it!=result.end();it++){
            cout<<(*it)<<endl;
        }
        result.clear();
    }
    
    return 0;
}
