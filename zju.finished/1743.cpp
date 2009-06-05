#include<iostream>
using namespace std;
// take time to review it!
enum {
    DAT = 366,
    NUM = 1008,
};
struct Rent{
    int s,e,v;
    bool operator<(const Rent&rhs)const{
        return e<rhs.e;
    }
};
int num;
Rent r[NUM];
int tab[DAT][DAT];

void fun(){
    int i,j,t,s, a, b;
    memset(tab, 0, sizeof(tab));
    s = 0;
    for(i=0; i<DAT; i++){
        for(; s<num&&r[s].e==i;s++){
            for(j=0; j<=i; j++){
                tab[i][j] = max(tab[i][j], tab[r[s].s][j]+r[s].v);
            }
            for(b=s-1;b>=0&&r[b].e==i;b--){
                tab[i][i] = max(tab[i][i], tab[r[s].s][r[b].s]+r[s].v+r[b].v);
            }
        }
        for(j=0; j<=i; j++){
            if(i) tab[i][j] = max(tab[i][j], tab[i-1][j]);
            if(j) tab[i][j] = max(tab[i][j], tab[i][j-1]);
            tab[j][i] = tab[i][j];
        }
    }
    printf("%d\n", tab[DAT-1][DAT-1]);
}
int readIn(){
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        scanf("%d%d%d", &r[i].s, &r[i].e, &r[i].v);
        r[i].s--;
    }
    sort(r, r+num);
    return num;
}
int main(){
    while( readIn() > 0){
        fun();
    }
    return 0;
}

