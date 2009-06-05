    
#include<iostream>
using namespace std;
enum {
    SIZ = 1000008,
};
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	void operator=(const char *);
	int operator %(int);
};
template<int N>
void BigNum<N>::operator=(const char *s){
	len = strlen(s);
	int t = len;
	while(t){
		d[len -t] = s[t-1] -'0';
		t --;
	}
}
template<int N>
int BigNum<N>::operator % (int dm){
	int carry = 0;
	int i;
	for(i=len-1;i>=0;i--){
		carry *= 10;
		carry += d[i];
		carry %= dm;
	}
	return carry;
}

char L[108];
int K;
int primes[78500] = {2, 3};
int pnum = 2;
BigNum<108> lhs;

void init_primes(int n){
	int i = primes[pnum-1], p ;
	if(i>=n)
		return;
	int lim = 3, j;
	for(i+=2; i<=n ;i+=2){
        while(lim*lim <= i){
            lim+=2;
        }
		p = 1;
		for(j=0;primes[j]<lim;j++){
			if(i%primes[j]==0){
				p = 0;
				break;
			}
		}
		if(p){
			primes[pnum++] = i;
		}
	}
    //printf("%d\n", pnum);
}
int readIn(){
    scanf("%s %d ", L, &K);
    return K;
}

// find a p, that primes[p] <= K and p is max;
int find_max(){
    int low = 0, high = pnum;
    int mid;
    while(low < high){
        mid = (low + high) / 2;
        if(primes[mid] < K){
            low = mid + 1;
        } else if(primes[mid] >= K){
            high = mid;
        }
    }
    while(mid>=0 && primes[mid] >= K){
        mid--;
    }
    return mid;
}

void fun(){
    int p = find_max();
    int t, i;
    bool state = true;
    lhs = L;
    for(i=0; i<= p; i++){
        t = lhs % primes[i];
        if(t == 0){
            state = false;
            break;
        }
    }
    if(state){
        printf("GOOD\n");
    } else {
        printf("BAD %d\n", primes[i]);
    }
}
int main(){
    init_primes(1000008);
    while(readIn() > 0){
        fun();
    }

    return 0;
}

