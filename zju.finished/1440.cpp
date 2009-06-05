#include<iostream>
using namespace std;
enum {
    SIZ = 100008,
};
int num;
int dat[SIZ];
int perm[SIZ];
struct Cmp{
    bool operator()(int a, int b)const{
        return dat[a] < dat[b];
    }
}cmp;

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

int binsearch(int h, int v){
    int l=0, m;
    while(l<h){
        m = (l+h)/2;
        if(v < perm[m]){
            h = m;
        }else {
            l = m + 1;
        }
    }
    return l;
}

void bonesort(){
    int cnt = 0, i, t;
    sort(perm, perm+num, cmp);
    for(i=0; i<num; i++){
        if(perm[i] < 0) continue;
        t = perm[i];
        while(i!=t){
            perm[i] = perm[t];
            perm[t] = -1;
            t = perm[i];
        }
        perm[i] = -1;
        cnt++;
    }
    cnt = num - cnt;
    printf("%d\n", cnt);
}

void fun(){
    bonesort();
    inverseNumber();
}

int readIn(){
    if(scanf("%d", &num)<0) return 0;
    for(int i=0; i<num; i++){
        scanf("%d", &dat[i]);
        perm[i] = i;
    }
    return 1;
}

int main(){
    while( readIn() > 0 ){
        fun();
    }
    return 0;
}

