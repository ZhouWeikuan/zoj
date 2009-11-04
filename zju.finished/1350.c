#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 102,	
};

int table[Size];
char cell[Size];

int fun(int n){
    if(table[n] != -1)
    	return table[n];
    int i,j;
    
    memset(cell,0,sizeof(char)*Size);
    
    for(i=2;i<=n;i++){
		for(j=i;j<=n;j+=i){
			cell[j] = 1 - cell[j];
		}
	}
	j = 0;
	for(i=1;i<=n;i++){
		j += cell[i];
	}
	table[n] = n - j;
	return table[n];
}

int main(){
    int num;
    int tstcase;
    memset(table,-1,sizeof(int)*Size);    
    
    scanf("%d",&tstcase);
    while(tstcase --){
		scanf("%d",&num);
		printf("%d\n", fun(num));		
	}
    
    return 0;
}
