#include<iostream>
using namespace std;
enum {
    SIZ = 104,
    TO  = 0,
    FRO = 1,
};
int base, type, len;
char input[SIZ];
char output[SIZ];

void convTo() {
    int sign = 1;
    int src = atoi(input), rem;
    int pos = src >= 0?1:-1;
    if (pos < 0){
        src = -src;
    }
    len = 0;
    while(src){
        rem = (base + src % base)%base;
        if (sign * pos < 0 && rem){
            rem = base - rem;
            src += rem;
        } else {
            src -= rem;
        }
        output[len++] = '0' + rem;
        src /= base;
        sign = -sign;
    }
    if (len == 0){
        output[len++] = '0';
    }
    output[len] = 0;
    reverse(output, output + len);
    printf("%s\n", output);
}

void convFrom() {
    int d = 0;
    char *p = input;
    while(*p){
        d *= -base;
        d += *p - '0';
        ++p;
    }
    printf("%d\n", d);
}

void fun(){
    if (type == TO){
        convTo();
    } else {
        convFrom();
    }
}

void parseBase(){
    char *p = index(input, '-');
    *p = 0;
    base = atoi(p+1);
    if (strcmp(input, "to") == 0) {
        type = TO;
    } else {
        type = FRO;
    }
}

int main(){

    scanf("%s ", input);
    while(strcmp(input, "end") != 0){
        parseBase();
        scanf("%s ", input);
        fun();
        scanf("%s ", input);
    }

    return 0;
}

