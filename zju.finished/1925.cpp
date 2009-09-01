#include<iostream>
using namespace std;
enum {
    SIZ = 1004,
};
// assume there is already Nl diminos on the left, and Nr diminos on the right
// we should insert the last one to the middle, so that Nl+Nr+1 successive dimonos are ready
//
//                     / the last one don't fail, Ps * (1)
// The left steps(Ls) =- the last one fails left, Pl * (1 + E(l) + Ls)
//                     \ the last one fail right, Pr * (1 + E(r) + Ls)
//
// so E(Nl + Nr + 1) = Ls + E(Nl) + E(Nr)
// I think it can be optimised if Pl =/= Pr, but not try yet.

const double MAXN = 1e30;
int n;
double ps, pl, pr;
double e[SIZ];

void fun(){
    double v;
    e[0] = 0;
    for (int i=1; i<=n; ++i){
        e[i] = MAXN;
        for (int j=0; j<i; ++j){
            v = (ps + pl*(1+e[j]) + pr*(1+e[i-j-1]))/ps;
            v += e[j] + e[i-j-1];
            e[i] = min(e[i], v);
        }
    }
    printf("%.2lf\n", e[n]);
}

int readIn(){
    scanf("%d", &n);
    if (n <= 0) return 0;
    scanf("%lf%lf", &pl, &pr);
    ps = 1 - pl - pr;
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

