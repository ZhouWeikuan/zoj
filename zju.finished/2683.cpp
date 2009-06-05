#include<iostream>
#include<queue>
using namespace std;
/* everyone should run at least one day!!! */
enum {
    R = 2,
    D = 158,
    N = 54,
};
int num, day;
int r[N][R];
int mat[2][D];
int dis;

int fun(){
    if(num * 3 < day || num > day) return -1;
    day -= num;
    int i, j, k;
    int *pre, *cur, *tmp;
    pre = mat[0], cur = mat[1];
    memset(pre, -1, sizeof(mat[0]));
    pre[0] = 0;
    for(i=0; i<num; i++){
        memset(cur, -1, sizeof(mat[0]));
        for(j=0; j<= day; j++){
            if(cur[j] < pre[j]) 
                cur[j] = pre[j];
            for(k=1; k<= 2; k++){
                if(j+k<=day && cur[j+k] < pre[j] + r[i][k-1]){
                    cur[j+k] = pre[j] + r[i][k-1];
                }
            }
        }
        tmp = cur, cur = pre, pre = tmp;
    }
    dis += pre[day];
    return dis;
}
void readIn(){
    int a, i;
    scanf("%d%d",&num, &day);
    dis = 0;
    for(i=0; i<num; i++){
        scanf("%d%d%d",&a, &r[i][0], &r[i][1]);
        dis += a;
        r[i][0] -= a;
        r[i][1] -= a;
    }
}
int main(){
    int tst;
    scanf("%d", &tst);
    while( tst--){
        readIn();
        printf("%d\n", fun());
    }
    return 0;
}

