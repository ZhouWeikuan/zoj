#include<iostream>
#include<vector>
using namespace std;
//Wrong Answer
enum {
    SIZ = 208,
};
unsigned bn, cn, lvl;
struct Node{
    unsigned l,a,b;
};
Node cli[108];
Node bric[SIZ]; 
unsigned *tab[22];
vector<int> ptr[22];

void update(int l, unsigned c, unsigned v){
    if(tab[l][c] <= v) return;
    tab[l][c] = v;
    c /= l;
    for(vector<int>::iterator i=ptr[l].begin(); 
            i!=ptr[l].end(); ++i){
        if(cli[*i].a <= c && cli[*i].b >= c && cli[*i].l > v){
            cli[*i].l = v;
        }
    }
}
void fun(){
    unsigned i,j,k,lim;
    for(i=1; i<=lvl; i++){
        memset(tab[i], -1, sizeof(unsigned)*(i*1000));
    }
    for(i=0; i<bn; i++){
        for(j=lvl-1; j>=1; --j){
            lim = j * 1000;
            for(k=0; k<lim; k++){
                if(tab[j][k] == -1) continue;
                update(j+1, k+bric[i].a, bric[i].b + tab[j][k]);
            }
        }
        update(1, bric[i].a, bric[i].b);
    }
    for(i=0; i<cn; i++){
        if(cli[i].l != -1){
            printf("%u\n", cli[i].l);
        } else {
            printf("impossible\n");
        }
    }
}
int readIn(){
    if(scanf("%u", &bn)<0) return 0;
    unsigned i;
    for(i=1; i<=20; i++){
        ptr[i].clear();
    }
    for(i=0; i<bn ;i++){
        scanf("%u%u", &bric[i].a, &bric[i].b);
    }
    scanf("%u",&cn);
    lvl = 0;
    for(i=0; i<cn; i++){
        scanf("%u%u%u", &cli[i].l, &cli[i].a, &cli[i].b);
        ptr[cli[i].l].push_back(i);
        lvl = max(lvl, cli[i].l);
        cli[i].l = -1;
    }
    return 1;
}

int main(){
    int i;
    for(i=1; i<=20; i++){
        tab[i] = (unsigned *)malloc(sizeof(unsigned)*(i*1000));
    }
    while(readIn()>0){
        fun();
    }
    return 0;
}

