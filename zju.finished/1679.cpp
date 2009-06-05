#include<iostream>
#include<cmath>
// 利用了多种技巧提高
using namespace std;
enum {
    SIZ = 42,
};
const long double PI = 3.14159265358979323846;
long double opt[SIZ][SIZ][SIZ];
long double side[SIZ][SIZ][SIZ];
long double line[SIZ][SIZ];
long double pnt[SIZ];
int num, m;

long double calc(int a, int b, int c){
    long double p = (line[a][b] + line[b][c] + line[a][c])/2;
    p = (p*(p-line[a][b])) *((p-line[b][c])*(p-line[a][c]));
    p = sqrt(p);
    return p;
}
void fun(){
    int i,j,k,l;
    long double t, val=0;
    for(i=0; i<num; i++){
        for(j=i+2;j<num;j++){
            for(l=i+1;l<j;l++){
                side[i][l][j] = calc(i,l,j);
                if(side[i][l][j] > val){
                    val = side[i][l][j];
                }
            }
        }
    }
    for(k=3; k<= m; k++){
    for(i=0; i<num; i++){
        for(j=i+k-1;j<num;j++){
            opt[i][j][k] = 0;
            for(l=i+k-2;l<j; l++){
                t = opt[i][l][k-1] + side[i][l][j];
                if(opt[i][j][k] < t)
                    opt[i][j][k] = t;
            }
            if(k==m && opt[i][j][k] > val){
                val = opt[i][j][k];
            }
        }
    }
    }
    printf("%.6LF\n", val);
}
int readIn(){
    scanf("%d%d",&num,&m);
    int i,j;
    long double x,y;
    for(i=0; i<num; i++){
        scanf("%LF", &pnt[i]);
    }
    for(i=0; i<num; i++){
        for(j=i+1; j<num; j++){
            x = fabs(pnt[i] - pnt[j]);
            if(x > 0.5) x = 1-x;
            x *= PI; 
            line[i][j] = line[j][i] = 2 * sin(x);
        }
    }
    return num;
}
int main(){

    while(readIn() > 0){
        fun();
    }
    return 0;
}

