#include<iostream>
#include<cstdio>
#include<cctype>
// wrong answer
using namespace std;
enum {
    SIZ = 204,
    LIM = 0x7fffffff,
};
int len;
char buf[SIZ];
char tab[SIZ];

int getFirst(int val, int len){
    int ord = 1, cnt = 9;
    int fir = 1;
    for (int i=1; i<len; ++i){
        ord += i*cnt;
        cnt *= 10;
        fir *= 10;
    }
    ord += len * (val - fir);
    return ord;
}

// get the value from [s, e)
int getVal(int s, int e){
    int t = 0;
    for ( ; s<e; ++s){
        t *= 10;
        if (isdigit(buf[s])){
            t += buf[s] - '0';
        } else {
            t += 1;
        }
    }
    return t;
}

// to check whether it will be a inc
// from [s, e)
bool inc(int s, int e){
    for (; s<e; ++s){
        if (buf[s] != '9')
            return false;
    }
    return true;
}

bool sameDigits(int a, int b){
    a = sprintf(tab, "%d", a);
    b = sprintf(tab, "%d", b);
    return a==b;
}

int match(int pos, int off, int base){
    if (off == 0 && buf[0] == '0') return -1;
    int suff = getVal(0, off);
    int head = getVal(off, pos);
    int first = -1;
    if (off){// adjust head if necessary
        if (inc(0, off)){
            head -= 1;
            if (head ==0 || !sameDigits(head, head+1)){
                head *= 10;
                head +=9;
            }
            first = head * base + suff;
        } else {
            first = head * base + suff;
        }
    } else {
        first = head;
    }
    suff = first + 1;
    for (int t = off?off:pos; t < len; ++suff, t += head){
        head = sprintf(tab, "%d", suff);
        if (t + head <= len){
            off = head;
        } else {
            off = len - t;
        }
        if (strncmp(&buf[t], tab, off) != 0){
            return -1;
        }
    }
    
    return first;
}

void fun(){
    len = strlen(buf);
    int ans = LIM, soff=0;
    for (int pos=1; ; ++pos){
        int base = 1;
        for (int off=0; off<pos; ++off){
            int t = match(pos, off, base);
            if (t >= 0 && ans > t){
                ans = t;
                soff = off?(pos-off):0;
            }
            base *= 10;
        }
        if (ans != LIM){
            int p = getFirst(ans, pos);
            p += soff;
            // printf("%s %d %d\n", buf, ans, p);
            printf("%d\n", p);
            return;
        }
    }
}

int readIn(){
    return scanf("%s", buf) > 0;
}

int main(){
    while(readIn() > 0){
        fun();
    }

    return 0;
}

