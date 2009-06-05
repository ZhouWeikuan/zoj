#include<iostream>
enum {
    SIZ = 320,
    MOD = 1000000000,
};
unsigned long long mat[SIZ][SIZ];
int len;
char buf[SIZ];

void fun(){
    len = strlen(buf);
    if(len % 2 == 0 || buf[0]!=buf[len-1]){
        printf("0\n");
        return;
    }        
    int i,j,l;
    memset(mat, 0, sizeof(mat));
    for(i=0; i<len; i++)
        mat[i][i] = 1;
    for(l=2; l<len; l+=2){
        for(i=0; i<len; i++){
            if(buf[i] != buf[i+l]) continue;
            mat[i][i+l] = mat[i+1][i+l-1];
            for(j=2; j<l; j+=2 ){
                if(buf[i] != buf[i+j]) continue;
                mat[i][i+l] += mat[i+1][i+j-1]*mat[i+j][i+l];
                mat[i][i+l] %= MOD;
            }
            mat[i][i+l] %= MOD;
        }
    }
    printf("%llu\n", mat[0][len-1]);
}

int main(){
    
    while(scanf("%s", buf) > 0){
        fun();
    }
    return 0;
}

