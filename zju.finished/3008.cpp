#include<cstdio>
#include<map>
#include<vector>
#include<cmath>

using namespace std;

enum {
    SIZ = 1300,
};

int primes[SIZ] = { 2, 3};
int pnum = 2;

void init_primes(int n){
	int i = primes[pnum-1], p;
	if(i>=n)
		return;
	for(i+=2; i<=n ;i +=2){
		p = 1;
		for(int j=0;primes[j]*primes[j]<=i;j++){
			if(i%primes[j]==0){
				p = 0;
				break;
			}
		}
		if(p){
			primes[pnum++] = i;
		}
	}
	// printf("%d primes up to %d\n", pnum, n);
}

int N,M;
map<int, int> tab;
vector<long long> vec;

void parse()
{
    tab.clear();
    int n = N, k;
    for (int i=0; i<pnum && primes[i]<=n; i++){
        k = 0;
        while(n%primes[i]==0){
            n /= primes[i];
            ++k;
        }
        if (k)
        {
            tab[primes[i]] = k * M;
        }
    }
    if (n != 1)
    {
        tab[n] = M;
    }
}

void fun(){
    parse();
    vec.resize(1);
    vec[0] = 1;
    int k;
    long long s;
    for(map<int,int>::iterator it=tab.begin(); it!=tab.end(); ++it){
        int n = vec.size();
        for(int i=0; i<n; i++){
            for(s=vec[i]*it->first, k=1; k<=it->second&&s<=N; k++, s*=it->first)
            {
                vec.push_back(s);
            }
        }
    }
    printf("%d\n", vec.size());
}

int main(){
    init_primes(10000);

    while(scanf("%d%d ", &N, &M) > 0){
        fun();
    }

	return 0;
}

