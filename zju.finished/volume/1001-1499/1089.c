#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 16,	
};

int num;
int lotto[Size];
int perm[Size];

int fun(){	
	int i;
	for(i=0;i<6;i++){
        perm[i] = i;
    }
    
    while(1 ){
        printf("%d", lotto[perm[0]]);
        for(i=1;i<6;i++){
            printf(" %d", lotto[perm[i]]);
        }
        printf("\n");
        i = 5;
        perm[i]++;
        while(i>0 && perm[i] > num - (6-i)){
            i--;
            perm[i] ++;
        }
        if(i==0 && perm[0] > num - 6){
            break;
        }
        i++;
        for(;i<6;i++){
            perm[i] = perm[i-1] + 1;
        }
    }
}

int main(){
	int i;
	int tstcase = 0;
	
	scanf("%d", &num);
	while(num){
        if(tstcase!=0)
            printf("\n");
        tstcase ++;
        for(i=0;i<num;i++){
            scanf("%d", &lotto[i]);
        }
        fun();
       	scanf("%d", &num);
    }
	
	return 0;
}
