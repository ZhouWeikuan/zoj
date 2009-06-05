#include<iostream>
using namespace std;
enum {
    SIZ = 100008,
};
int num;
int dat[SIZ];
int perm[SIZ];

// merge *a@m, *b@n to *p@num
unsigned long long merge(int *p, int *a, int *b, int m, int n){
    unsigned long long cnt = 0;
    while(m>0&&n>0){
        if(*a<=*b){
            *p++ = *a++;
            m--;
        }else {
            *p++ = *b++;
            cnt += m;
            n--;
        }
    }
    while(m>0){
        *p++ = *a++;
        m--;
    }
    while(n>0){
        *p++ = *b++;
        n--;
    }
    return cnt;
}

void inverseNumber(){
    unsigned long long cnt = 0;
    int i, j, s, l, dl;
    int *pre=dat, *cur=perm, *tmp;
    for(l=1,dl=2; l<num; l=dl,dl*=2){
        for(s=0; s+dl<=num; s+=dl){
            cnt += merge(&cur[s], &pre[s], &pre[s+l], l, l);
        }
        if(s+l <= num){
            cnt += merge(&cur[s], &pre[s], &pre[s+l], l, num-s-l);
        } else if(s < num){
            cnt += merge(&cur[s], &pre[s], &pre[num], num-s, 0);
        }
        tmp=cur, cur=pre, pre=tmp;
    }
    printf("%llu\n", cnt);
}

int main(){
    while( readIn() > 0 ){
        fun();
    }
    return 0;
}

