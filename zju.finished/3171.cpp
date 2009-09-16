#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
enum {
    SIZ = 10004,
};

uint64_t cnt[5];
char dat[SIZ];

void fun(){
    memset(cnt, 0, sizeof(cnt));
    for (int i=0; dat[i]; ++i){
        dat[i] = tolower(dat[i]);
        switch(dat[i]){
        case 's':
            ++cnt[0];
            break;
        case 'e':
            cnt[1] += cnt[0];
            cnt[3] += cnt[2];
            break;
        case 'v':
            cnt[2] += cnt[1];
            break;
        case 'n':
            cnt[4] += cnt[3];
            break;
        default:
            break;
        }
    }
    printf("%llu\n", cnt[4]);
}

int main(){

    while(scanf("%s", dat) > 0){
        fun();
    }

    return 0;
}

