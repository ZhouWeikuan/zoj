#include<iostream> 

using namespace std;
enum {
    SIZ = 100,
};

int primes[SIZ] = {2,3,5,7};
int num = 4;

void init(){
	int flag;
	for(int n=9; num<SIZ; n+=2){
		flag = 0;
		for(int i=0; primes[i]*primes[i]<= n;i++){
			if(n % primes[i] == 0){
				flag = 1;
				break;
			}
		}
		if(flag ==0){
			primes[num++] = n;
		}
	}
}

int main(){
	int i;
	init();
	scanf("%d",&i);
	return 0;
}
