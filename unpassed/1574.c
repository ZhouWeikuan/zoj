#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct {
	int x,y,z;	
}Node ;

Node triple[100008];

void init(){
	int x, y, z;
	x = 1 ,y = 2, z = 3;
	int pos = 0;
	int a,b,c;
	
	while(pos < 100008){
		y = x +1 , z = x + 2;
		
		if(c -b ==a){
			triple[pos].x = x;
			triple[pos].y = y;
			triple[pos].z = z;
			pos ++;
		}
		x ++;
	}
		
}


int main(){
    
    init();
    return 0;
}
