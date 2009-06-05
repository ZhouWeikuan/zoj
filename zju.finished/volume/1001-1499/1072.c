#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned char mem[260];

void trans(){
	int i;
	if(mem[0] > 16){
		for(i=0;i<256;i++){
			if(mem[i] <='F' && mem[i] >= 'A'){
				mem[i] -= 'A';
				mem[i] += 10;
			} else {
				mem[i] -= '0';
			}
		}
	} else {
		for(i=0;i<256;i++){
			if(mem[i] >= 10){
				mem[i] -=10;
				mem[i] +='A';
			} else {
				mem[i] += '0';
			}
		}
	}
}

void output(){
	int i;
	for(i=0;i<256;i++){
		printf("%c", mem[i]);
	}	
	printf("\n");
}

void fun(){
    unsigned char A,B;
    int pc = 0;
    int arg, flag = 1, cmd;
    
    A = B = 0;
    while(flag){
		cmd = mem[pc++];
		switch(cmd){
			case 0:
				arg = mem[pc++];
				arg <<= 4;
				arg += mem[pc++];
				A = mem[arg];
				break;
			case 1:
				arg = mem[pc++];
				arg <<= 4;
				arg += mem[pc++];
				mem[arg] = A;
				break;
			case 2:
				arg = A; A= B; B = arg;
				break;
			case 3:
				arg = A + B;
				A = arg &0x0F;
				B = arg >>4;
				break;
			case 4:
				A ++;
				A &= 0x0f;
				break;
			case 5:
				A += 0x0f;
				A &= 0x0f;
				break;				
			case 6:
				arg = mem[pc++];
				arg <<= 4;
				arg += mem[pc++];
				if(A ==0){
					pc = arg;
				}
				break;
			case 7:
				arg = mem[pc++];
				arg <<= 4;
				arg += mem[pc++];				
				pc = arg;				
				break;
			case 8:
				flag = 0;
				break;
		}
	}
    
}

int main(){
    
    scanf("%s", mem);
    while(mem[0] != '8'){
		trans();
		
		fun();
		
		trans();
		output();
		scanf("%s", mem);
	}
    
    return 0;
}
