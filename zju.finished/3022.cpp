#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 104,
};
const double eps = 1e-8;
char buf[SIZ];
double tab[2][20];
double *cur, *nex;
int num;

void dfsC(double v, int w, int r, int d){
    if (d==0){
        nex[w] += v;
        return;
    }
    // correct one
    if (w > 0){
        dfsC(v * w/(r+w), w-1, r, d-1); 
    }
    // keep
    if (r > 0){
        dfsC(v * r/(r+w), w, r-1, d-1);
    }
}

void dfsM(double v, int w, int r, int d){
    if (d==0){
        nex[num-r] += v;
        return;
    }
    // mistake one
    if (r > 0){
        dfsM(v*r/(r+w),  w, r-1, d-1);
    }
    // keep 
    if (w > 0){
        dfsM(v*w/(r+w), w-1, r, d-1);
    }
}

void Correct(double *cur, double *nex, int cnt){
    int i;
    if (cnt > num) cnt = num;
    memset(nex, 0, sizeof(tab[0]));
    for (i=0; i<=num; ++i){
        if (cur[i] < eps) continue;
        dfsC(cur[i], i, num-i, cnt);
    }
}

void Mistake(double *cur, double *nex, int cnt){
    int i;
    if (cnt > num) cnt = num;
    memset(nex, 0, sizeof(tab[0]));
    for (i=0; i<=num; ++i){
        if (cur[i] < eps) continue;
        dfsM(cur[i], i, num-i, cnt);
    }
}

void fun(){
    double *tmp;
    cur=tab[0]; nex=tab[1];
    int cnt = 0;
    cur[0] = 1.0;
    scanf("%s", buf);
    while(buf[0]!='E'){
        if (buf[0] == 'W'){ // Watashi
            cnt = 1;
            scanf("%s", buf);
            while(buf[0] == 'W'){
                ++cnt;
                scanf("%s", buf);
            }
            Mistake(cur, nex, cnt);
        } else { // Kimi
            cnt = 1;
            scanf("%s", buf);
            while(buf[0] == 'K'){
                ++cnt;
                scanf("%s", buf);
            }
            Correct(cur, nex, cnt);
        }
        tmp=cur, cur=nex, nex=tmp;
    }
    printf("%.2lf\n", cur[0]);
}

int readIn(){
    if (scanf("%d",&num)<0)
        return 0;
    memset(tab, 0, sizeof(tab));
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

