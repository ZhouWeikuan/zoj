#include<iostream>
#include<set>
using namespace std;

int n, m;
int sa, sb;
set<int> a;
set<int> b;

void fun(){
    int d = sb - sa;
    if (d%2!=0){
        printf("-1\n");
        return;
    }
    d /= 2;
    for(set<int>::iterator it=a.begin();
            it!=a.end(); ++it){
        if (b.find(*it + d)!=b.end()){
            printf("%d %d\n", *it, *it+d);
            return;
        }
    }
    printf("-1\n");
}

void readIn(){
    int v;
    a.clear(); b.clear();
    sa = sb = 0;
    for (int i=0; i<n; i++){
        scanf("%d ", &v);
        a.insert(v);
        sa += v;
    }
    for (int i=0; i<m; i++){
        scanf("%d ", &v);
        b.insert(v);
        sb += v;
    }
}

int main(){

    scanf("%d%d ", &n, &m);
    while(n > 0 || m > 0){
        readIn();
        fun();
        scanf("%d%d ", &n, &m);
    }

    return 0;
}

