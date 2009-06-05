#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 2008, // 
};
char buf[SIZ];
int len;

void div2(){
    int i, carry=0;
    for(i=0; i<len; i++){
        carry *= 10;
        carry   +=  buf[i];
        buf[i]  =   carry/2;
        carry   %=  2;
    }
}
void output(){
    int i;
    for(i=0; i<len && buf[i] == 0; i++)
        ;
    for(; i<len; i++){
        printf("%d", buf[i]);
    }
    printf("\n");
}

void sub(int m){
    int i=len-1;
    while(m && i>=0){
        buf[i] -= m;
        if(buf[i] < 0){
            m = 1;
            buf[i] += 10;
        } else {
            m = 0;
        }
        i--;
    }
}

void fun(){
    for(len=0; buf[len]; len++){
        buf[len] -= '0';
    }
    if(buf[len-1]%2 == 1){  // odd
        div2();
        output();
        return;
    }
    div2();
    if(buf[len-1] % 2 == 0){  // even
        sub(1);
    } else {    // odd
        sub(2);
    }
    output();
}

int main(){
    int tstcase;
    scanf("%d", &tstcase);
    while( tstcase--){        
        scanf("%s", buf);
        fun();
        if(tstcase)
            printf("\n");
    }
    
    return 0;
}

