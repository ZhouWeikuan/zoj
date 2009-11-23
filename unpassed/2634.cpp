#include<iostream>
#include<iomanip>
#include<algorithm>
#include<iterator>
#include<cstdio>
#include<set>
// MLE
// 双向搜索？
using namespace std;
enum {
    SIZ = 10,
};
struct Node {
    int val;
    set<int> tab;
};
int M;
Node mat[SIZ][SIZ];

void dump(Node &o){
    copy(o.tab.begin(), o.tab.end(), ostream_iterator<int>(cout,","));
    printf("\n");
}

void update(Node &fro, Node &to, int v){
    int t;
    for(set<int>::iterator it=fro.tab.begin(); 
            it != fro.tab.end(); ++it){
        t = *it + v;
        if (t > M) continue;
        to.tab.insert(*it+v);
    }
}

void fun(){
    int r, c, s, nr;
    // c == 0
    for (s=0, r=0; r<8; ++r){
        s += mat[r][0].val;
        mat[r][0].tab.insert(s);
        if (r>0) update(mat[r][0], mat[r-1][1], mat[r-1][1].val);
        update(mat[r][0], mat[r][1], mat[r][1].val);
        if (r<7) update(mat[r][0], mat[r+1][1], mat[r+1][1].val);
        mat[r][0].tab.clear();
    }
    // c>0 && c< 7
    for (c=1; c<7; ++c){
        for (r=0; r<8; ++r){
            if (r>0) update(mat[r][c], mat[r-1][c+1], mat[r-1][c+1].val);
            update(mat[r][c], mat[r][c+1], mat[r][c+1].val);
            if (r<7) update(mat[r][c], mat[r+1][c+1], mat[r+1][c+1].val);
            for (s=0, nr=r-1; nr>=0; --nr){
                s += mat[nr][c].val;
                if (nr>0) update(mat[r][c], mat[nr-1][c+1], mat[nr-1][c+1].val + s);
                update(mat[r][c], mat[nr][c+1], mat[nr][c+1].val + s);
                if (nr<7) update(mat[r][c], mat[nr+1][c+1], mat[nr+1][c+1].val + s);
            }
            for (s=0, nr=r+1; nr<8; ++nr){
                s += mat[nr][c].val;
                if (nr>0) update(mat[r][c], mat[nr-1][c+1], mat[nr-1][c+1].val + s);
                update(mat[r][c], mat[nr][c+1], mat[nr][c+1].val + s);
                if (nr<7) update(mat[r][c], mat[nr+1][c+1], mat[nr+1][c+1].val + s);
            }
            mat[r][c].tab.clear();
        }
    }

    // c == 7
    for (r=0; r<7; ++r){
        for (s=0,nr = r + 1; nr < 8; ++nr){
            s += mat[nr][7].val;
        }
        update(mat[r][c], mat[7][7], mat[7][7].val + s);
        mat[r][c].tab.clear();
    }
    if (mat[7][7].tab.find(M) != mat[7][7].tab.end()){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

void readIn(){
    scanf("%d", &M);
    for (int i=0; i<8; ++i){
        for (int j=0; j<8; ++j){
            scanf("%d", &mat[i][j].val);
            mat[i][j].tab.clear();
        }
    }
}

int main(){
    int tn;
    scanf("%d", &tn);
    while(tn-- > 0){
        readIn();
        fun();
    }

    return 0;
}

