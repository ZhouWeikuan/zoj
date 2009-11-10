#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char buffer[16];
unsigned char  accu, pc,cmd,value;
unsigned char  mem[32];

void fun(){
	int i;
	for(i=7;i>=0;i--){
		if( (accu>>i) &0x01){
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
}

int conv(){    
    int ret = 0;
    int i =0;
    
    for(i=0;i<8;i++){
		ret <<= 1;
		ret |= buffer[i] -'0';
	}    
    
    return ret;
}

int main(){
    int i;
    int flag;      
    
    scanf("%s ", buffer);
    while(!feof(stdin)){
		mem[0] = conv();
		for(i=1;i<32;i++){
			scanf("%s ", buffer);
			mem[i] = conv();
		}
		
		accu = pc = 0;
		flag = 1;
		while(flag){					
			cmd		=	(mem[pc]>>5)&0x07;
			value	=	mem[pc]& 0x1f;
			pc		=	(pc+1)&0x1f;
			
			switch(cmd){
				case 0:  /* STA */
					mem[value] = accu;
					break;
				case 1: /* LDA */
					accu = mem[value];
					break;
				case 2:
					if(accu ==0){
						pc = value;
					}
					break;
				case 3:					
					break;
				case 4:
					accu = (accu-1 + 256) &0x0ff;
					break;
				case 5:
					accu = (accu +1 ) &0x0ff;
					break;
				case 6:
					pc = value;
					break;
				case 7:
					flag = 0;
					break;
			}			
		}
		
		fun();
		
		scanf("%s ", buffer);
	}
    
    return 0;
}
