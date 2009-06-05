#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stack[2][104];
int *sa, *sb;
int N,K;

void insert(int e){
	int t;
	int v;
	
	for(v=0;v<K;v++){
		if(sa[v] == 0)
			continue;
		sa[v] = 0;
		
		t = (v + e + K) % K;		
		sb[t] = 1;	
		
		t = (K + v - e) % K;		
		sb[t] = 1;
	}
		
	int *p = sa;
	sa = sb;
	sb = p;
}

int fun(){
    int ele,i;
	  
    sa = stack[0], sb= stack[1];
    
    scanf("%d", &ele);
    ele %= K;
    ele = (ele + K) % K;
    sa[ele] = 1;
    
    for(i=1;i<N;i++){
		scanf("%d", &ele);
		ele %= K;
		ele = (ele + K) % K;
		insert(ele);
	}
	
	ele = (sa[0]==1);
	memset(sa,0,sizeof(int) * 104);
	return ele;
}

int main(){
    int tstcase;   
	
    scanf("%d", &tstcase);
    while(tstcase --){
		scanf("%d %d ", &N, &K);
		if( fun() ){
			printf("Divisible\n");
		} else {
			printf("Not divisible\n");
		}
				
		if(tstcase)
			printf("\n");
	}
    
    return 0;
}
