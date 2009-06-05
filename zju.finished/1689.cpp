#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 9600,
    Max_M = 100000,
};
int primes[SIZ] = { 1,2, 3};
int pnum = 3;
void init_primes(int n){
	int i = primes[pnum-1], p ;
	if(i>=n)
		return;
	for(i+=2; i<=n ;i +=2){
		int lim = (int)sqrt((double)i)+1;
		p = 1;
		for(int j=1;primes[j]<lim;j++){
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

int m,a,b;
// find a biggest prime that is <= v 
int find(int v){
    int low =0, high = v;
    int mid = (low + high) / 2;
    while(low < high){
        if(primes[mid ] < v){
            low = mid + 1;
        } else if(primes[mid] == v){
            break;
        } else {
            high = mid;
        }
        mid = (low+high)/2;
    }
    while(primes[mid]> v){
        mid--;
    }
    return primes[mid];
}

int fun(){
    int y = 0,x =1,t;
    int sx,sy, val=0;
    for(int i=0;i<pnum;i++){
        x = primes[i];
        y = b * x / a;
        t = m / x;
        if(y > t)
            y = t;
        y = find(y);
        if(y < x)
            break;
        t = x * y;
        if(val < t){
            val = t;
            sx =x;
            sy= y;
        }
    }
    cout<<sx<<" "<<sy<<endl;
}

int main(){
    init_primes(Max_M);
    cin>>m>>a>>b;
    while(m){
        fun();
        cin>>m>>a>>b;
    }

    return 0;
}
