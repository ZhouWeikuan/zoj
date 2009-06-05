#include<iostream>
using namespace std;
int num;
int a, s, b;
int getV(char c){
    if(c<='9') return c-'0';
    return c-'A'+10;
}
char setV(int d){
    d &= 0x0f;
    if(d<=9) return d+'0';
    return d+'a'-10;
}
void fun(){
    char buf[4];
    int i;
    a = b = s = 0;
    for(i=0; i<num; i++){
        if(i){
            if(i%16==0) printf("\n");
            else if(i%2==0) printf(" ");
        }
        scanf("%s", buf);
        a = getV(buf[0])*16 + getV(buf[1]);
        b = a - s;
        if(b < -8){
            b = -8;
        } else if(b > 7){
            b = 7;
        }
        s += b;
        printf("%c", setV(b));
    }
    printf("\n");
}
int main(){
    while(scanf("%d", &num) > 0){
        printf("%d\n", num/2);
        fun();
    }
    return 0;
}
