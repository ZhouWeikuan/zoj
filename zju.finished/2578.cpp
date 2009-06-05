#include<iostream>
#include<cctype>
using namespace std;
enum {
    SIZ = 32008,
    LEN = 256,
};
struct Node {
    double pos;
    int sign;
    char name[LEN];
};
int num;
double L, V;
Node tree[SIZ];

inline bool update(double &v, double t){
    if(v < t){
        v = t;
        return true;
    }
    return false;
}
int readIn(int &t, double &v){
    scanf("%d",&num);
    if(num == 0) return 0;
    scanf("%lf%lf",&L,&V);
    char ch;
    v = 0;
    for(int i=0; i<num; i++){
        scanf(" %c%lf%s",&ch, &tree[i].pos, tree[i].name);
        if(toupper(ch) == 'P'){
            tree[i].sign = 1;
            if(update(v, (L-tree[i].pos)/V)){
                t = i;
            }
        }else {
            tree[i].sign = -1;
            if( update(v, (tree[i].pos)/V) ){
                t = i;
            }
        }
    }
    return num;
}
int fun(int cur){
    int sign = tree[cur].sign;
    if(sign > 0){
        for(int i=cur+1; i<num;i++){
            if(tree[i].sign != sign){
                cur++;
            }
        }
    } else {
        for(int i=cur-1; i>=0;i--){
            if(tree[i].sign != sign){
                cur--;
            }
        }
    }
    return cur;
}
int main(){
    int t;
    double v;

    while(readIn(t, v) > 0){
        t = fun(t);
        v *= 100;
        v = (double)(int)(v);
        v /= 100;
        printf("%13.2lf %s\n", v, tree[t].name);
    }
    return 0;
}

