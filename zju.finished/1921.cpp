#include<cstdio>

using namespace std;
enum {
    SIZ = 102,
};
char tab[2][SIZ][SIZ];
typedef char (*Mat)[SIZ];
int r,c,n;
char win[128] = {0};

void init(){
    win['P'] = 'S';
    win['S'] = 'R';
    win['R'] = 'P';
}

void readIn(Mat p){
    for(int i=0;i<r;i++){
        scanf("%s", p[i]);
    }
}

void sim(Mat a, Mat b){
    int i,j;
    char t;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            t = a[i][j];
            if ( (i>0 && a[i-1][j] == win[t])
                ||(i<r-1 && a[i+1][j] == win[t])
                ||(j>0 && a[i][j-1] == win[t])
                ||(j < c-1 && a[i][j+1] == win[t])
               ){
                b[i][j] = win[t];
            } else {
                b[i][j] = t;
            }
        }
    }
}

void fun(){
    Mat pa,pb, p;
    pa = tab[0]; pb= tab[1]; 
    readIn(pa);
    while(n--){
        sim(pa, pb);
        p = pb; pb=pa; pa=p;
    }
    for(n=0;n<r;n++){
        printf("%s\n", pa[n]);
    }
}

int main(){
    init();
    int tstcase;

    scanf("%d",&tstcase);
    while(tstcase --){
        scanf("%d%d%d", &r, &c, &n);
        fun();
        if(tstcase )
            printf("\n");
    }

	return 0;
}
