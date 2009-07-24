#include<iostream>
using namespace std;
enum {
    SIZ = 104,
};

const char rStr[] = "IVXLCDM";
const int  rVal[] = {1, 5, 10, 50, 100, 500, 1000};
char buf[SIZ];

int getVal(char s){
    int i;
    for (i=0; rStr[i]&&rStr[i]!=s; ++i)
        ;
    if (rStr[i])
        return rVal[i];
    return -1;
}

char getChar(int v){
    int i;
    for (i=0; rVal[i] && rVal[i] < v; ++i)
        ;
    return rStr[i];
}

int fromRoman(char *s){
    int ret = 0;
    int pre = -1, cur;
    while(*s == 'M'){
        ret += 1000;
        ++s;
    }
    while(*s){
        cur = getVal(*s++);
        if (pre == -1){
            pre = cur;
        } else {
            if (pre < cur){
                cur -= pre;
                ret += cur;
                pre = -1;
            } else {
                ret += pre;
                pre = cur;
            }
        }
    }
    if (pre != -1)
        ret += pre;
    return ret;
}

char * toRoman(int v){
    char *s = buf;
    int r;
    while(v >= 1000){
        *s ++ = 'M';
        v -= 1000;
    }
    for (int unit=100; unit > 0; unit/=10){ 
        while (v >= unit){
            r = v / unit;
            if (r == 9){
                *s ++ = getChar(unit);
                *s ++ = getChar(10*unit);
            } else if (r >= 5){
                *s ++ = getChar(5*unit);
                r -= 5;
                while(r--){
                    *s ++ = getChar(unit);
                }
            } else if (r == 4){
                *s ++ = getChar(unit);
                *s ++ = getChar(5*unit);
            } else {
                while(r--)
                    *s ++ = getChar(unit);
            }

            v %= unit;
        }
    }
    *s = 0;

    return buf;
}

int readIn(){
    int n;
    int r = 0, v;
    scanf("%d ", &n);
    while(n--){
        scanf("%s ", buf);
        v = fromRoman(buf);
        r += v;
    }
    return r;
}

int main(){
    int tst = 1;
    int v;
    while((v=readIn()) > 0){
        printf("Case %s: ", toRoman(tst++));
        printf("%s\n", toRoman(v));
    }

    return 0;
}

