#include<cstdio>

// 递推，不在数组的开始，就在数组的结束。 
using namespace std;
enum {
	SIZ = 50008,	
};
int N,M;
int save[SIZ]; 

inline unsigned calc(unsigned k){
	k *= (k-1);
	k /= 2;
	return k;
}
int fun(){
	int *ptr = save;    
	int i;
	unsigned t, k;
	for(i=1;i<=N;i++){
		k = N - i;
		t = calc(k);
		if(t >= M){
			ptr[0] = i;
			ptr ++;
		} else {
			M -= k;
			ptr[k] = i;
		}
	}
	
	printf("%d", save[0]);
	for(i=1; i< N;i ++){
		printf(" %d", save[i]);
	}
	printf("\n");
	return 0;
}

int main(){  
  	
  	scanf("%d%d", &N, &M);
  	while(N > 0){
		fun();
		scanf("%d%d", &N, &M);
	}
	  
    return 0;
}
