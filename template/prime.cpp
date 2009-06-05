#include<cstdio>
#include<map>
#include<cmath>

using namespace std;
enum {
    SIZ = 200,
};
map<unsigned, unsigned> tab;
map<unsigned, unsigned>::iterator iter;
int primes[SIZ] = { 2, 3};
int pnum = 2;

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
	//printf("%d primes up to %d\n", pnum, n);
}

int N,K;

int bin_search(int val, int low, int high){
    int mid;
    while(low < high){
        mid = (low + high)/2;
        if(primes[mid] == val){
            return mid;
        } else if(val > primes[mid]){
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return -1;
}

unsigned calc(int psum, int left, int s){
    if( psum < primes[s])
        return 0;
    if(left == 1){
        if( bin_search(psum, s, pnum) >= 0)
            return 1;
        return 0;
    }
    unsigned key,ret = 0;
    key = (psum<<16)+(left<<8) + s;
    iter = tab.find(key);
    if(iter != tab.end() ){
        return iter->second;
    }
    
    int lim = psum / left + 1;
    while(primes[s] < lim){
        ret += calc(psum - primes[s], left-1, s+1);
        s++;
    }
    return tab[key] = ret;
}

int main(){
    unsigned ret;
    init_primes(1200);

    scanf("%d%d", &N, &K);
    while(N + K){
        ret = calc(N,K,0);
        printf("%u\n", ret);

        scanf("%d%d", &N, &K);
    }

	return 0;
}
