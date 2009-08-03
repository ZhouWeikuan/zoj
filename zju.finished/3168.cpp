#include<iostream>
#include<algorithm>
using namespace std;
enum {
    SIZ = 104,
};

int getVal(char c){
    if (c == 'Z') return 0;
    if (c == 'O') return 1;
    if (c == 'J') return 2;
    if (c == '7') return 3;
    return 4;
}

struct cmp {
    bool operator()(const char&a, const char&b) const {
        return getVal(a) < getVal(b);
    }
};

char dat[1004];

int main(){
    int len;
    while(scanf("%s", dat)> 0){
        len = strlen(dat);
        stable_sort(dat, dat+len, cmp());
        printf("%s\n", dat);
    }

    return 0;
}

