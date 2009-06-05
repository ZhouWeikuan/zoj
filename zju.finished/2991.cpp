#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
enum {
    SIZ = 104,
};

struct Node {
    int sign;
    int val;
    void flip(){
        sign = 1 - sign;
    }
    void swap(Node &o){
        int t=o.sign; o.sign = sign; sign = t;
        t = o.val; o.val = val; val = t;
    }
};
vector<Node> v;
vector<int> s;

void dump(int n){
    printf("%d->", n);
    for(int i=0; i<v.size(); i++){
        printf(" %s%d", v[i].sign?"+":"-", v[i].val);
    }
    printf("\n");
}

void reverse(int m){
    int p,i;
    for(p=0; v[p].val!=m; ++p)
        ;
    if(p==v.size()-1 && v[p].sign)
        return;
    if (p != 0){
        s.push_back(p);
        reverse(v.begin(), v.begin()+(p+1));
        for(i=0; i<=p; ++i){
            v[i].flip();
        }
        //dump(p+1);
    }
    if(v[0].sign){
        if(v.size()==1)
            return;
        v[0].flip();
        s.push_back(0);
        //dump(1);
    }
    p = v.size() -1;
    s.push_back(p);
    reverse(v.begin(), v.begin()+(p+1));
    for(i=0; i<=p; ++i){
        v[i].flip();
    }
    //dump(p+1);
}

void output(){
    static int n = 1;
    printf("%d %d", n++, s.size());
    for(int i=0; i<s.size(); i++){
        printf(" %d", s[i]+1);
    }
    printf("\n");
}

void fun(){
    for(int i=v.size(); i>0; --i){
        reverse(i);
        v.pop_back();
    }
    output();
}

int readIn(){
    Node o;
    v.clear();
    s.clear();
    int n, m;
    char ch;
    scanf("%d ", &n);
    while(n--){
        scanf(" %c%d ",&ch,&m);
        o.sign = (ch=='+');
        o.val = m;
        v.push_back(o);
    }
    return 1;
}

int main(){
    int N;
    scanf("%d ", &N);
    while(N--){
        readIn();
        fun();
    }

    return 0;
}

