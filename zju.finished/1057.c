#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int A,B;
int pos;
int stack[2][24];

void fun(int s , int e){
    if(s == e){
		return;
	}
	if(s + e == 3){
		if(s < e){
			A += 6;
		} else {
			B += 6;
		}
		return;
	}
	
	if(s < e){
		if(e -s == 1){
			A += (s+e);
		} else {
			B += e;
		}
	} else {
		if(s -e ==1){
			B += (s+ e);
		} else {			
			A += s;
		}
	}
}

int main(){ 
	int i;   
    int j;
    int tstcase = 0;
    
    scanf("%d ", &pos);
    while(pos){
		if(tstcase ){
			printf("\n");
		}
		tstcase ++;
		A = 0, B = 0;
		for(i=0;i<2;i++){
			for(j=0;j<pos;j++){
				scanf("%d ", &stack[i][j]);
			}
		}
		for(i=0;i<pos;i++){
			fun(stack[0][i], stack[1][i]);
		}
		printf("A has %d points. B has %d points.\n", A, B);
		
		scanf("%d ", &pos);	
	}
    
    return 0;
}
