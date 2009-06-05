#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
	int first;
	int second;	
}Comp;

int N, M;
Comp  node[1000];
int matrix[32][32];
int lessnum[32];

void trace(){
	char sorted[32];
	int i;
	for(i=0;i<N;i++){
		sorted[N - lessnum[i]-1] = 'A' + i;
	}
	sorted[N] = 0;
	printf("%s.\n", sorted);
}

int fun(){
    memset(matrix,0,sizeof(matrix));
    memset(lessnum,0,sizeof(lessnum));
    
    int i,j,k;
    int num = 0;
    int lim = N * (N-1) / 2;
    int flag = 0;			/* 0 -- unknown, 1 -- sorted, 2 --- inconsistant */
    int a, b;
    for(i=0;i<M;i++){
		a = node[i].first;
		b = node[i].second;
		if(matrix[b][a]){
			flag = 2;
			break;
		}
		if(! matrix[a][b]){
			matrix[a][b]  = 1; 
			num ++;
			lessnum[a]++;
		}
		for(k=0;k<N;k++){
			if(matrix[k][a] && !matrix[k][b]){
				if(matrix[b][k]){
					flag = 2;
					goto outer;
				}
				matrix[k][b] = 1;
				lessnum[k]++;
				num ++;
			}
			if(matrix[b][k] && ! matrix[a][k]){
				if(matrix[k][a]){
					flag = 2;
					goto outer;
				}
				matrix[a][k] = 1;
				num ++;
				lessnum[a]++;
			}
		}
		if(num >= lim){
			flag = 1;
			break;
		}
	}
outer:
	i++;
	switch(flag ){
		case 0:
			printf("Sorted sequence cannot be determined.\n");
			break;
		case 1:
			printf("Sorted sequence determined after %d relations: ", i);
			trace();
			break;
		case 2:
		default:
			printf("Inconsistency found after %d relations.\n", i);
			break;	
	}
}

int main(){
    int i;
    char a,b;
    char c;
    
    scanf("%d %d ", &N, &M);
    while( N ){
		for(i=0;i<M;i++){
			scanf("%c%c%c ", &a,&c,&b);
			node[i].first = a-'A';
			node[i].second = b-'A';
		}	
		fun();	
		scanf("%d %d ", &N, &M);
	}
	    
    return 0;
}
