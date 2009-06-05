#include<iostream>
using namespace std;
enum {
    SIZ = 1028,
    MAXV = 99999999,
    ALP = 'Z' - 'A' + 1,
};
int num, len;
char gen[SIZ][SIZ];
char ans[SIZ];
int tmp[SIZ][ALP+1];

int compute(int p){
    int i,j,l=num;
    for(i=0; i<num; i++){
        for(j=0; j<ALP; j++){
            tmp[i][j] = (gen[i][p]!=(j+'A'));
        }
        tmp[i][ALP] = 0;
    }
    while(l>1){
        for(i=0; i<l; i+=2){
            tmp[l][ALP] = MAXV;
            for(j=0; j<ALP; j++){
                tmp[l][j] = tmp[i][j] + tmp[i+1][j]; // same
                // different
                int t=min(tmp[i][j]+tmp[i+1][ALP]+1,tmp[i][ALP]+tmp[i+1][j]+1);
                tmp[l][j] = min(t, tmp[l][j]);
                tmp[l][ALP] = min(tmp[l][ALP], tmp[l][j]);
            }
            for(j=0; j<=ALP;j++){
                tmp[i/2][j] = tmp[l][j];
            }
        }
        l/=2;
    }
    for(i=0; i<ALP; i++){
        if(tmp[0][i] == tmp[0][ALP]){
            ans[p] = i + 'A';
        }
    }
    return tmp[0][ALP];
}
void fun(){
    if(num == 1){
        printf("%s 0\n", gen[0]);
        return;
    }
    int j, sum = 0;
    for(j=0; j<len; j++){
        sum += compute(j);
    }
    ans[len] = 0;
    printf("%s %d\n", ans, sum);
}
int readIn(){
    scanf("%d%d",&num, &len);
    for(int i=0; i<num; i++){
        scanf("%s", gen[i]);
    }
    return num;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}
