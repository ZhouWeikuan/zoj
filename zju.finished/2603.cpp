#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
enum {
    SIZ = 16,
};
struct Node {
    unsigned short val, no;
};

int num;
vector<Node> col[SIZ];
bool first;

void move(Node &o){
    if (first){
        printf("%d", o.val);
        first = false;
    } else {
        printf(" %d", o.val);
    }
}

void solve(int n){
    int base = (1<<n);
    int i, v;
    for (i=0; i<col[n].size(); ++i){
        col[n][i].no -= base;
    }
    Node o;
    for (i=col[n].size()-1; i>=0; --i){
        v = n;
        o = col[n][i];
        while(v>=0 && o.no <= (1<<v)){
            if (v < num)
                move(o); // move out
            --v;
            if (v >= 0)
                move(o); // move in
        }
            
        if (v >= 0){
            col[v].push_back(o);
        }
    }
    col[n].clear();
    for (i=0; i<n; ++i){
        solve(i);
    }
}

void fun(){
    first = true;
    solve(num);
    printf("\n");
}

int readIn(){
    scanf("%d", &num);
    if (num == 0) return 0;
    int lim = 1<<num;
    col[num].clear();
    Node o;
    for (int i=0; i<lim; ++i){
        scanf("%u", &o.val);
        o.no = o.val + (1<<num);
        col[num].push_back(o);
    }
    reverse(col[num].begin(), col[num].end());

    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

