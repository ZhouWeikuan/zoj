#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 60,	
};

int perm[Size];
int inv[Size];
int num;

void convP2I(){
	int i,j,t;
	
	for(i=1;i<=num;i++){
		t = 0;
		for(j=0; perm[j]!= i;j++){
			if(perm[j] > i)
				t++;
		}
		inv[i-1] = t;
	}
}

void convI2P(){
	int i,j,t;
	memset(perm, 0, sizeof(int) *num);
	
	for(i=1;i<=num;i++){
		t = 0;
		for(j=0; perm[j]!= 0;j++)
			;
		for(;j<num;j++){
			if(t == inv[i-1])
				break;	
			if(perm[j] ==  0)
				t++;			
		}
		for(; perm[j]!= 0;j++)
			;
		perm[j] = i;
	}
}

int main(){
	char c;
	int i;

	scanf("%d ", &num);
	while(num ){
		scanf("%c ", &c);
		if(c =='P'){
			for(i=0;i<num;i++){
				scanf("%d ", &perm[i]);
			}
			convP2I();
			printf("%d", inv[0]);	
			for(i=1;i<num;i++){
				printf(" %d", inv[i]);	
			}
			printf("\n");
		} else {
			for(i=0;i<num;i++){
				scanf("%d ", &inv[i]);
			}
			convI2P();
			printf("%d", perm[0]);	
			for(i=1;i<num;i++){
				printf(" %d", perm[i]);	
			}
			printf("\n");
		}
		scanf("%d ", &num);
	}	
	return 0;
}
