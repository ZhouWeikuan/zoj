#include<iostream>
#include<vector>

using namespace std;

struct Node {
    unsigned l, a, b;
};
vector<unsigned> ptr[21];
unsigned num, pos, lvl;
unsigned cop[208];
unsigned pri[208];
Node res[108];
unsigned * tab[21];

void update(unsigned l, unsigned p, unsigned v){
    if(tab[l][p] <= v) return;
    tab[l][p] = v;    
    for(unsigned i=0; i<ptr[l].size(); i++){
        if(p>=res[ptr[l][i]].a * l && p<=res[ptr[l][i]].b*l && res[ptr[l][i]].l > v){
            res[ptr[l][i]].l = v;
        }
    }
}
void fun(){
    unsigned i, j, k, lim;
    for(i=1; i<=lvl; i++){
        memset(tab[i], -1, sizeof(unsigned)*(i*1008));
    }
    for(i=0; i<num; i++){
        for(j=lvl-1; j>=1; j--){
            lim = j * 1000;
            for(k=1; k< lim; k++){
                if(tab[j][k] == -1) continue;
                update(j+1, k+cop[i], tab[j][k]+pri[i]);
            }
        }
        update(1, cop[i], pri[i]);
    }
    for(i=0; i<pos; i++){
        if(res[i].l == -1){
            printf("impossible\n");
        } else {
            printf("%u\n", res[i].l);
        }
    }
}

int readIn(){
    if(scanf("%u", &num)< 0) return 0;
    unsigned i;
    for(i=1; i<=20; i++){
        ptr[i].clear();
    }
    for(i=0; i<num; i++){
        scanf("%u%u", &cop[i], &pri[i]);
    }
    scanf("%u", &pos);
    lvl = 0;
    for(i=0; i<pos; i++){
        scanf("%u%u%u", &res[i].l, &res[i].a, &res[i].b);
        ptr[res[i].l].push_back(i);
        lvl = max(lvl, res[i].l);
        res[i].l = -1;
    }
    return 1;
}

int main(){
    int i;
    for(i=1; i<= 20; i++){
        tab[i] = (unsigned *)malloc(sizeof(unsigned)*(i*1008));
    }
    i = 0;    
    while(readIn() > 0){
        if(i++) printf("\n");
        fun();
    }
    return 0;
}
