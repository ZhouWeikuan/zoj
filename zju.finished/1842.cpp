#include<cstdio>
#include<map>
#include<cmath>

using namespace std;
enum {
    SIZ = 5000,
    MAX = 1000004,
};
unsigned lim = 0x7fffffff;
unsigned pr[SIZ] = {2, 3}; // 只要取sqrt(lim)下的质数就行了，再上面的数对lim没影响
int num = 2;
char dat[MAX];
unsigned L, U;

void fun(){
    int s, i, pre;
    memset(dat, 1, sizeof(dat[0]) * (U - L + 3));
    for(i=0; i<num&&pr[i]*pr[i]<=U; i++){
        s = (L/pr[i])*pr[i];
        if(s < L) s+= pr[i];
        if(s ==pr[i]) s+=pr[i];
        while(s <= U){
            if(dat[s-L]){
                dat[s-L] = 0;
            }
            s+=pr[i];
        }
    }
    int a, b, c, d;
    s = U - L + 1;
    pre = -1;
    b = lim; d = 0;
    for(i=0; i<s; i++){
        if(dat[i] == 0) continue;
        if(pre != -1) {
            int v = L + i - pre;
            if(v < b ){
                b = v;
                a = pre;
            }
            if(v > d ){
                d = v;
                c = pre;
            }
        }
        pre = L + i;
    }
    if(b == lim){
        printf("There are no adjacent primes.\n");
        return;
    }
    printf("%d,%d are closest, %d,%d are most distant.\n",a, a+b, c, c+d);
}
void init_primes(){
	int i, p, j;
	for(i=5; i*i<= lim;i+=2){
        p = 1;
        for(j=1;pr[j]*pr[j]<=i; j++){
            if(i%pr[j]==0){
                p=0;break;
            }
        }
        if(p)   pr[num++] = i;
	}
}
int main(){
    unsigned ret;
    init_primes();
    while(scanf("%u%u", &L, &U) > 0){
        if(L <= 2) L=2;
        fun();
    }
	return 0;
}

