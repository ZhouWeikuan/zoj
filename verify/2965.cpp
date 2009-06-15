#include<iostream>
using namespace std;
enum {
    SIZ = 100,
};

unsigned dat[SIZ];

bool valid(int v){
    if (v % 7 == 0) return true;
    while(v){
        if (v%10 == 7) return true;
        v /= 10;
    }
    return false;
}

void init(){
    memset(dat, -1, sizeof(dat));
    int s = 0;
    for (int i=1; i<1000; i++){
        if (valid(i)){
            ++s;
            if (dat[s] > i - s + 1){
                dat[s] = i - s + 1;
            }
        } else {
            s = 0;
        }
    }
}

int main(){
    init();
    int tst, n;

    scanf("%d ", &tst);
    while(tst-- > 0){
        scanf("%d ", &n);
        printf("%d\n", dat[n]);
    }

    return 0;
}

