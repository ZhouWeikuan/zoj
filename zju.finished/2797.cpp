#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
enum {
    SIZ = 104,
};

int num;
double prob[SIZ];
bool mark[SIZ];
double mat[SIZ][SIZ];

int findMin(){
    int i, p=0;
    for (i=1; i<=num; ++i){
        if(mark[i]) continue;
        if (p==0||prob[p]<prob[i])
            p = i;
    }
    return p;
}

int expand(int s){
    int i;
    double p;
    mark[s] = true;
    for (i=1; i<=num; ++i){
        if(mark[i]) continue;
        p = prob[s] * mat[s][i];
        if ( p > prob[i])
            prob[i] = p;
    }
    return 0;
}

void fun(){
    memset(prob, 0, sizeof(prob));
    memset(mark, false, sizeof(mark));
    prob[1] = 1.00;
    int left = num - 1;
    while(left){
        --left;
        int s = findMin();
        expand(s);
    }
    prob[num] *= 100;
    printf("%.6lf percent\n", prob[num]);
}

int readIn(){
    scanf("%d", &num);
    if (num == 0) return 0;
    int m, a, b, p;
    scanf("%d", &m);
    memset(mat, 0, sizeof(mat));
    while(m--){
        scanf("%d%d%d",&a,&b,&p);
        mat[a][b] = p;
        mat[a][b] /= 100;
        mat[b][a] = mat[a][b];
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

