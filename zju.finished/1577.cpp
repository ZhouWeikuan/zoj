#include<iostream>
#include<cmath>


// 增加了L%G不为0的情况，即不存在的情况！
using namespace std;
int prime[50000] = {2,3,5,7};
int num = 4;
void calc(int n){
	int i = prime[num-1], p ;
	if(i>=n)
		return;
	for(i+=2; i<=n ;i +=2){
		int lim = (int)sqrt((double)i)+1;
		p = 1;
		for(int j=0;j<lim;j++){
			if(i%prime[j]==0){
				p = 0;
				break;
			}
		}
		if(p){
			prime[num++] = i;
		}
	}
	//printf("%d primes up to %d\n",num,n);
}
int G,L;
int fun(int n){
	calc(n);
	int cnt = 0, i = 0;

	while(n > 1){
		if(n%prime[i] ==0){
			cnt++;
			do{
				n /= prime[i];
			}while(n%prime[i]==0);
		}
		i++;
	}
	return 1<<cnt;
}

int main(){
	
	while(cin>>G>>L){
        if(L %G == 0)
		    cout<<fun(L/G)<<endl;
        else 
            cout<<0<<endl;
	}

	return 0;
}
