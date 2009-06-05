#include<iostream>
using namespace std;
enum {
    SIZ = 1008,
};
int num, total;
int mon[SIZ];

int getMon(char *s){
    int ret = 0;
    while(*s && *s!= '.'){
        ret *= 10;
        ret += *s - '0';
        s++;
    }
    s++;
    while(*s){
        ret *= 10;
        ret += *s - '0';
        s++;
    }
    return ret;
}
int readIn(){
    static char str[20];
    scanf(" %d",&num);
    total = 0;
    for(int i=0; i<num; i++){
        scanf(" %s", str);
        mon[i] = getMon(str);
        total += mon[i];
    }
    return num;
}

void fun(){
    int avg, rem;
    avg = total / num;
    rem = total % num;
    total = 0;
    for(int i=0; i<num; i++){
        if(mon[i] <= avg){
            continue;
        }
        if(rem){
            rem --;
            mon[i] --;
        }
        total += mon[i] - avg;
    }
    printf("$%d.", total/100);
    total %= 100;
    printf("%02d\n", total);
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

