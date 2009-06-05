#include<stdio.h>

enum {
	Size = 110,	
};

int square[Size];
int N,M;
int casenum;

void init(){
	int i;
	for(i=0;i<Size;i++){
		square[i] = i * i;
	}	
}

int fun(){
	int i,j;
	int num = 0;
	int t;
    casenum ++;
    
    for(i=1;i<N-1;i++){
		for(j=i+1;j<N;j++){
			t = i * j;
			if( (square[i] + square[j] + M)%t==0 ){
				num ++;
			}
		}
	}
    printf("Case %d: %d\n",casenum,num);
}

int main(){
    int tstblk;
    
    init();
    
    scanf("%d ", &tstblk);
    while(tstblk --){
		scanf("%d %d ", &N, &M);
		casenum = 0;
		while(N || M){
			fun();
			scanf("%d %d ", &N, &M);
		}
		
		if(tstblk) {
			printf("\n");
		}
	}
    
    return 0;
}
