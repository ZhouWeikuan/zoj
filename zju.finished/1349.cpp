#include<iostream>
#include<iomanip>
/*
 *  网上抄袭，绑定A和B的差值，因为A和B出现的值不是独立的
 */
using namespace std;
enum {
    SIZ = 160,
};
double score[7] = {0};
double rate[2][SIZ];
int tab[3][3] = {
    {4, 5, 6},
    {2, 3, 4},
    {0, 3, 4}
};
double prob[3] = {0.25,0.5,0.25};
int cur,pred;
void init(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            score[tab[i][j]] += prob[i]*prob[j];
        }
    }
}
void output(int r, double *s, int lim, int val){
    double pA=0, pB =0, tie = 0;
    int i,j;
    for(i=0;i<lim;i++){
        if(i<val){
            pB += s[i];
        } else if(i==val){
            tie += s[i];
        } else {
            pA += s[i];
        }
    }
    pA *= 100; pB *= 100, tie *= 100;
    printf("%5d   %7.4lf%%  %7.4lf%%  %7.4lf%%\n", 
            r, pA, pB, tie);
}

void increase(int lim){
    int i,j;
    memset(rate[cur], 0, sizeof(rate[cur]));
    for(i=0;i<lim;i++){
        for(j=0;j<7;j++){
            rate[cur][j + i] += rate[pred][i] * score[j];
        }
    }
}
int main(){
    init();
    int lim = 6, val=3;
    cur = 1, pred = 0;
    printf("Round   A wins    B wins    Tie\n");
    for(int i=0;i<7;i++){
        rate[pred][i] = score[i];
    }
    output(1, rate[pred], lim + 1, val);
    for(int i=2;i<=20;i++){
        increase(lim+1);
        lim += 6;
        val += 3;
        output(i, rate[cur],lim+1, val);
        pred = cur; cur = 1 - pred;
    }
    return 0;
}

