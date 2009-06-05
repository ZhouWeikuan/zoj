#include<iostream>
#include<iomanip>
using namespace std;
enum {
    SIZ = 102,
};
double tab[SIZ][SIZ][SIZ]; // 如果压缩一下，空间占用会减少
int Dir[SIZ][SIZ]; // 从某点可出发的数目
int N;

void calc(){
    int t;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            t=0;
            t+= i>0;
            t+= j>0;
            t+= i<N-1;
            t+= j<N-1;
            Dir[i][j] = t;
        }
    }
}

double fun(){
    calc();
    memset(tab[0],0,sizeof(tab[0]));
    tab[0][N/2][N/2] = 1.0;
    double ret = 0;
    for(int i=1;i<=N;i++){
        for(int a=0;a<N;a++){
            for(int b=0;b<N;b++){
                tab[i][a][b] = 0;
                if(a > 0){
                    tab[i][a][b] += tab[i-1][a-1][b] / Dir[a-1][b];
                }
                if(b > 0){
                    tab[i][a][b] += tab[i-1][a][b-1] / Dir[a][b-1];
                }
                if(a < N-1){
                    tab[i][a][b] += tab[i-1][a+1][b] / Dir[a+1][b];
                }
                if(b < N -1){
                    tab[i][a][b] += tab[i-1][a][b+1] / Dir[a][b+1];
                }
            }
        }

        ret += tab[i][N/2][i-1];
        tab[i][N/2][i-1] = 0; //本点已计算，消除本点产生的影响 
    }
    return ret;
}

int main(){
    
    while(cin>>N){
        printf("%.4lf\n", fun());
    }

    return 0;
}

