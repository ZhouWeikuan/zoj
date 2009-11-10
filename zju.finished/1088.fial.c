#include<stdio.h>
#include<stdlib.h>

enum {
	Size = 154,	
};

int modular[Size] = {0,0,1,2};
char mask[Size];

void init(){
    int i,j,k,t;
    
    for(i=4;i<151;i++){
		for(j=2;j>0;j++){
			if(j%i==0 || i%j==0){
				continue;
			}
			memset(mask,0,sizeof(char) * Size);
			k = 0;
			t = j;
			while(k < i){
				t = t % i;
				if(t==1){
					break;
				}
				if(mask[t] != 0)
					break;
				mask[t] = 1;
				t *= j;
				k++;
			}
			if(k==i-1){
				modular[i] = j;
				break;
			}
		}
	}
}

int main(){
    int num;
    
    init();
    scanf("%d ", &num);
    while(num){
		printf("%d\n", modular[num]);
		scanf("%d ", &num);
	}
    
    return 0;
}
