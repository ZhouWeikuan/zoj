#include<cstdio>

using namespace std;
enum {
    SIZ = 16,
};
double tab[2][SIZ];
double mat[SIZ][SIZ];
char buf[SIZ][80];

int main(){
    int i,j,t;
    for(i=0;i<SIZ;i++){
        scanf("%s", buf[i]);
    }
    for(i=0;i<SIZ;i++){
        for(j=0;j<SIZ;j++){
            scanf("%lf", &mat[i][j]);
            mat[i][j] /= 100;
        }
    }
    double *pred,*now, *tmp;
    pred = tab[0]; now=tab[1];
    for(i=0;i<SIZ;i++){
        pred[i] = 1.0;
    }
    for(t=1;t<SIZ;t*=2){
        for(i=0;i<SIZ;i+= 2*t){
            int a,b;
            for(a=i;a < i+t;a++){
                now[a] = 0;
                for(b=i+t; b<i+2*t; b++){
                    now[a] += pred[a] * pred[b] * mat[a][b];
                }
            }
            for(a=i+t;a < i+2*t;a++){
                now[a] = 0;
                for(b=i; b<i+t; b++){
                    now[a] += pred[a] * pred[b] * mat[a][b];
                }
            }
        }
        tmp = pred; pred=now; now=tmp;
    }
    for(i=0; i<SIZ; i++){
        printf("%-10s p=%.2lf%%\n", buf[i], pred[i] * 100);
    }

	return 0;
}
