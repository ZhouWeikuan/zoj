#include<iostream>
using namespace std;
enum {
    SIZ = 300,
};
int num;
int dat[SIZ], tmp[SIZ];

void fun(){
    int half, i, j;
    int *s= dat, *d=&dat[1], *o=tmp, *t;
    for(half =1; half<num; half*=2){
        for(i=0; i<half; i++){
            o[2*i]  = (s[i] + d[i]) / 2;
            o[2*i+1]= (s[i] - d[i]) / 2;
        }
        t = s, s = o, o = t;
        d += half;
    }
    printf("%d", s[0]);
    for(i=1; i<num; i++){
        printf(" %d", s[i]);
    }
    printf("\n");
}
int readIn(){
    scanf("%d",&num);
    for(int i=0; i<num; i++){
        scanf("%d", &dat[i]);
    }
    return num;
}
int main(){
    while(readIn()>0){
        fun();
    }
    return 0;
}

