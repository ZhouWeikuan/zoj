#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 108,	
};

int num;
int matrix[Size][Size];
int vector[Size];

int calc(){
	int i;
	int ret = 0;
	int pos = 0;
	
	for(i=0;i<num;i++){
		if(vector[i]){
			pos ++;
		} else {
			ret += pos *(pos +1)/2;
			pos = 0;
		}
	}
	if(pos){
		ret += pos * (pos +1)/2;
	}
	return ret;
}

void fun(){
    int i,j,k;
    int sum = 0;
    int t;
    
    for(i=0;i<num;i++){
		for(k=0;k<num;k++){
			vector[k] = matrix[i][k];
		}
		sum += calc();
		for(j=i+1;j<num;j++){
			for(k=0;k<num;k++){
				vector[k] = vector[k] && matrix[j][k];
			}
			t = calc();
			if( t){
				sum += t;
			} else {
				break;
			}
		}
	}
	printf("%d\n", sum);
}

int main(){
    char c;
    int i,j;
    
    scanf("%d ", &num);
    while(! feof(stdin) ){
		for(i=0;i<num;i++){
			for(j=0;j<num;j++){
				scanf("%c ", &c);
				if(c=='#'){
					matrix[i][j] = 0;
				} else {
					matrix[i][j] = 1;
				}
			}
		}
		fun();
		
		scanf("%d ", &num);
	}
    
    return 0;
}
