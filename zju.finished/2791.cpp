#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 104,
};
const char *unit = "ixcm";
char buf[SIZ];

int getUnit(char c){
    int ret = 1;
    for(int i=0; unit[i]&&unit[i]!=c; ++i, ret*=10)
        ;
    return ret;
}

int parse(char *s){
    int ret = 0, d=1;
    for(;*s;++s){
        if (isdigit(*s)){
            d = *s - '0';
        } else {
            d *= getUnit(*s);
            ret += d;
            d = 1;
        }
    }
    return ret;
}

void output(int val){
    int u = 1000, d;
    for(int i=3; i>=0; --i, u/=10){
        d = val / u;
        if (d){
            if (d > 1){
                printf("%d", d);
            }
            printf("%c", unit[i]);
            val -= d * u;
        }
    }
    printf("\n");
}

void fun(){
    int a, b;
    char *p;
    static const char *sps=" \t\n";
    fgets(buf, SIZ, stdin);
    p = strtok(buf, sps);
    a = parse(p);
    p = strtok(NULL, sps);
    b = parse(p);
    a += b;
    output(a);
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst-- > 0){
        fun();
    }

    return 0;
}

