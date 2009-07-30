#include<iostream>
#include<string>
using namespace std;
enum {
    SIZ = 104,
};
int avail[] = {
    1, /*0*/
    1, /*thousand*/
    1, /*million*/
    1, /*billion*/
    1, /*trillion*/
    1, /*quadrillion*/
    1, /*quintillion*/
    0, /*sextillion*/
    0, /*septillion*/
    1, /*octillion*/
};
int tab[] = {
    0, 2, 4, 6, 30, 32, 34, 36, 40, 42, 44, 46, 50, 52, 54, 56, 60, 62, 64, 66, 
};
int tsize = sizeof(tab)/sizeof(tab[0]);
/*
0, zero,    10, ten         2X twenty-X
1, one      11, eleven      3X thirty-X
2, two      12, twelve      4X forty-X
3, three    13, thirteen    5x fifty-X
4, four     14, fourteen    6x sixty-X
5, five     15, fifteen     7x seventy-x
6, six      16, sixteen     8x eighty-x
7, seven    17, seventeen   9x ninety
8, eight    18, eighteen
9, nine     19, nineteen */

unsigned int no;
char buf[10];

void fun(){
    int pos = 0;
    long long num = tsize;
    while(no >= num){
        ++pos;
        while(!avail[pos]){
            ++pos;
        }
        num *= (tsize);
    }
    string s;
    long long base, a;
    while(pos > 0){
        base = num / (tsize);
        a = no / base;
        if (s.empty()){
            sprintf(buf, "%d,", tab[a]); 
        } else {
            sprintf(buf, "%03d,", tab[a]); 
        }
        s += buf;

        no %= base;
        num /= (tsize);
        --pos;
        while(!avail[pos]){
            s += "000,";
            --pos;
        }
    }
    a = no;
    if (s.empty()){
        sprintf(buf, "%d", tab[a]); 
    } else {
        sprintf(buf, "%03d", tab[a]); 
    }
    s += buf;
    printf("%s\n", s.c_str());
}

int main(){
    /*
    for (int i=1; i<=840; ++i){
        no = i;
        fun();
    }
    return 0;
    */
    scanf("%d", &no);
    while(no){
        fun();
        scanf("%d", &no);
    }

    return 0;
}

