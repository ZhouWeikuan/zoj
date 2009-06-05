#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stack[120];
int problem[120];
int hard[120];
int pos;

int hardstack[120];
int hardpos;
int N,P;

int fun(){
	int i,j;
	int min;
	int max;
	int t;
    scanf("%d %d ", &N, &P);
    memset(problem,0,sizeof(problem));
    memset(hard,0,sizeof(hard));
    pos = 0;
    hardpos = 0;
    
    for(i=0;i<N;i++){
		min = 1001;
		max = -1;
		for(j=0;j<P;j++){
			scanf("%d ", &t);
			if(t < min){
				pos = 0;
				stack[pos++] = j;
				min = t;
			} else if(t == min){
				stack[pos++] = j;
			}
			
			if(t > max){
				hardpos = 0;
				hardstack[hardpos++] = j;
				max = t;
			} else if(t == max){
				hardstack[hardpos++] = j;
			}
		}
		for(j=0;j<pos;j++){
			problem[stack[j]] ++;
		}
		for(j=0;j<hardpos;j++){
			hard[hardstack[j]] ++;
		}
	}
	
	t = N/2;
	j = 0;
	for(i=0;i<P;i++){
		if(!hard[i] && problem[i] > t){
			if(j)
				printf(" ");
			printf("%d", i+1);
			j ++;
		}
	}
	if(j==0)
		printf("0");
	printf("\n");
}

int main(){
    int tstcase;
    
    scanf("%d ", &tstcase);
    while(tstcase --){
		fun();		
		if(tstcase)
			printf("\n");
	}
    
    
    return 0;
}
