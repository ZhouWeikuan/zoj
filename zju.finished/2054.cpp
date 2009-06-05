#include<iostream>
using namespace std;
enum {
    SIZ = 10000,
};
struct Rect {
    int x, y;
};
int P, L;
int num;
Rect r[SIZ];

void init(){
    num = -1;
}
void add(int v){
    if(num == -1 || r[num].y + 1 != v){
        num++;
        r[num].x = r[num].y = v;
    } else {
        r[num].y ++;
    }
}
bool binSearch(int n){
    int h,l,m;
    int c = L;
    h = n - 1, l = 0;
    while(l<=h){
        m = (h + l)/2;
        if(--c==0){
            return m==P;
        }
        if(m == P)
            return false;
        if(m < P){
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return false;
}
void fun(){
    init();
    int lim = (1<<(L))*(P) + (1<<(L+1)) - 2;
    lim     = min(int(SIZ), lim);
    for(int n = P+1; n<= lim; n++){
        if(binSearch(n)){
            add(n);
        }
    }
    num++;
    printf("%d\n", num);
    for(int i=0; i<num; i++){
        printf("%d %d\n", r[i].x, r[i].y);
    }
}
int main(){
    int tst, n=0;
    scanf("%d", &tst);
    while(tst--){
        if(n++) printf("\n");
        scanf("%d%d",&P, &L);
        fun();
    }
    return 0;
}

