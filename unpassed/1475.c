#include<stdio.h>

enum {
	Size = 201,
};

int rank[Size] = {1,1};

int calc(int n, int k){
	int t = n - k;
	if(k > t){
		k = t;		
	}
	
	int sum = 1;
	for(t = 1; t <= k ; t++){
		sum *= (n - k + t);
		sum /= t;
	}
	return sum;
}

void init(){
    int i,j;
    int sum;
    for(i=2;i<Size;i++){
		sum = 0;
		for(j=1;j<=i;j++){
			sum += calc(i,j)*rank[i-j];
		}
		rank[i] = sum;
	}
}

int main(){
    int num;
    
    init();
    
    scanf("%d ", &num);
    while(num > 0){
		printf("%d\n", rank[num]);
		
		scanf("%d ", &num);
	}
    
    return 0;
}
