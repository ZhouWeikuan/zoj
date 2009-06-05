#include<iostream>
#include<vector>
using namespace std;
enum {
    LOW = -99999999, //
};
int num, len;
int bonus[1000];
char nex[10008][100]; //
int val[10008][100];
 
void fun(){
    if(len <= 2){
        for(int i=0; i<len; i++){
            printf("0");
        }
        printf("\n");
        return;
    }
    int v, p, lp;
    memset(val, 0, sizeof(val[0])*2);   
    for(lp=2; lp<len; lp++){
        p = 0;
        for(int h=0; h<100; h++){
            val[lp][h] = LOW;           
            for(int s=0; s<10; s++){
                v = bonus[p] + val[lp-1][p%100];
                if(val[lp][h] < v){
                    val[lp][h] = v;
                    nex[lp][h] = p % 100;
                }               
                p++;
            }
        }
    }
    v = LOW; p = 0;
    lp = len - 1;
    for(int i=0; i<100; i++){
        if(val[lp][i] > v){
            v = val[lp][i];
            p = i;
        }
    }
    for(lp=len-1; lp>=2; lp--){
        printf("%d", p/10);
        p = nex[lp][p];
    }
    printf("%02d\n", p);
}
 
void readIn(){
    int i;
    int a, b;
    memset(bonus, 0, sizeof(bonus));
    for(i=0; i<num; i++){
        scanf("%d%d",&a,&b);
        bonus[a] = b;
    }
}
int main(){   
    while( scanf("%d%d", &num, &len) > 0){
        readIn();
        fun();
    }
   
    return 0;
}

