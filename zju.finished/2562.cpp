#include<iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
/**
    搜索质数在其中的分布：这可是我自己想的:)
        1. 质数从小到大，中间不能有空，大的数目一定不多于小的质数
        2. 对于其中一个质数的分布，当增加某一个质数的个数时
            假设它以前的数目为x，则新的除数为olddiv * (x+2) / (x+1);
            因为这个质数的个数从0到x，对于olddiv的数目有均等的机会。
*/
enum {
    SIZ = 108,
};

unsigned long long lim, save;
int nd;
int sum[SIZ] = { 0 };
int primes[SIZ] = {2,3}, pnum =2, knum;

void init_primes(int n){
	int i = primes[pnum-1], p ;
	if(i>=n)
		return;
	for(i+=2; i<=n ;i +=2){
		int lim = (int)sqrt((double)i)+1;
		p = 1;
		for(int j=0;primes[j]<lim;j++){
			if(i%primes[j]==0){
				p = 0;
				break;
			}
		}
		if(p){
			primes[pnum++] = i;
		}
	}
}

// ind, index of primes
// s, sum of primes to mult
// div,  number of divisors
// mult , the multplied results;
int insert(int ind, int div, unsigned long long mult){
    if(mult > lim )
        return 1;
    if(ind > 0 && sum[ind] > sum[ind-1])
        return 0;

    if(div > nd){
        nd = div; save = mult;
    } else if(div == nd && mult < save){
        save = mult;
    }
    int d;
    for( ;ind<knum; ++ind){
        d = div * (sum[ind] + 2) / (sum[ind]  + 1);
        sum[ind]++;
        if( insert(ind, d, mult*primes[ind])){
            sum[ind]--;
            break;
        }
        sum[ind]--;
    }
    return 0;
}
    
void fun(){
    memset(sum, 0, sizeof(sum));
    nd = 0;
    save = 1;
    while(save <= lim){
        save *= primes[nd];
        nd++;
    }
    knum = nd - 1;
    nd = 0;
    save = 0;
    insert(0, 1, 1);
}

int main(){
    init_primes(100);

    while(cin>>lim){
        fun();
        cout<<save<<endl;
    }

    return 0;
}

