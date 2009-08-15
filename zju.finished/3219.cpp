#include<iostream>
using namespace std;
enum {
    SIZ = 104,
};

const double eps = 1e-7;
double p;
unsigned A, B, C, D, S;
double tab[SIZ];

void fun(){
    double win, lose;
    win = lose = 0;
    while(win + lose < 0.9999){
        for (int i=0; i<=S; ++i){
            if (tab[i] < eps) continue;
            A = i, B = S-A;
            // A lose to B with p
            if (A >= C){
                tab[A-C] += p * tab[i];
            } else {
                lose += p * tab[i];
            }
            // A get from B with 1-p
            if (B >= D){
                tab[A+D] += (1-p)*tab[i];
            } else {
                win += (1-p)*tab[i];
            }
            tab[i] = 0;
        }
    }
    printf("%.2lf\n", win);
}

int main(){
    int tst;

    scanf("%d", &tst);
    while(tst-- > 0){
        memset(tab, 0, sizeof(tab));
        scanf("%u%u%u%u%lf", &A, &B, &C, &D, &p);
        tab[A] = 1.0;
        S = A + B;
        fun();
    }

    return 0;
}

