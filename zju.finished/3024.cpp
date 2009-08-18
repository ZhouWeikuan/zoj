#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
enum {
    SIZ = 300004,
};

int prm[SIZ] = {6}, num=1;
int val;

void init(){
    int d[2] = {1,6};
    for (int n=1; ; ++n){
        for (int i=0; i<2; ++i){
            int v = 7*n + d[i];
            if (v >= SIZ) return;
            bool f = true;
            for (int p=0; p<num&&prm[p]*prm[p]<=v; ++p){
                if (v % prm[p] == 0){
                    f = false;
                    break;
                }
            }
            if (f){
                prm[num++] = v;
            }
        }
    }
}

void fun(){
    set<int> v;
    printf("%d:", val);
    for(int i=2; i*i <= val; ++i){
        if (val % i == 0){
            if (binary_search(prm, prm+num, i))
                v.insert(i);
            int t = val/i;
            if (binary_search(prm, prm+num, t))
                v.insert(t);
        }
    }
    if (v.empty()){
        v.insert(val);
    }
    for (set<int>::iterator it=v.begin(); it!=v.end(); ++it){
        printf(" %d", *it);
    }
    printf("\n");
}

int main(){
    init();
    while(scanf("%d", &val) > 0 && val > 1){
        fun();
    }

    return 0;
}

