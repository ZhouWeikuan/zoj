#include<iostream>
using namespace std;
enum {
    SIZ = 20008,
};
struct Doll{
    int w,h;
    bool operator<(const Doll&rhs)const{
        if(w!=rhs.w) return w<rhs.w;
        return h>rhs.h;
    }
};
int num;
Doll dol[SIZ];
int hel[SIZ], top;
// hel is in reverse order
// find the first pos hel[p] < v;
int findPos(int v){
    int low = 0, hi = top, mid;
    while(low < hi){
        mid = (low + hi)/2;
        if(hel[mid] >= v){
            low = mid + 1;
        } else {
            hi  = mid;
        }
    }
    return low;
}
void fun(){
    int p;
    top = 0;
    for(int i=0; i<num; i++){
        p = findPos(dol[i].h);
        hel[p] = dol[i].h;
        top += (p == top);
    }
    printf("%d\n", top);
}
void readIn(){
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        scanf("%d%d", &dol[i].w, &dol[i].h);
    }
    sort(dol, dol+num);
}
int main(){
    int tst;
    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
    }
    return 0;
}

