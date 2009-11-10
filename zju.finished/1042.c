#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 100,
};

char buffer[Size];
int rotate[3];

typedef struct {
	char alpha;
	int pos;
}Node;

Node enc[Size];
int  num;

int inrange(int i, char alpha){
	if(i==0){
		return alpha <='i'&& alpha >= 'a';
	}else if(i==1){
		return alpha <='r' && alpha >= 'j';
	} else{
		return (alpha <='z' && alpha >='s')||(alpha=='_');
	}
	return 0;
}

void rotate_enc(int n){
	int i,j;
	for(i=0;i<num;i++){
		j = (i + - rotate[n])%num;
		j = (j + num) % num;
		buffer[enc[i].pos] = enc[j].alpha;
	}
}

int main(){
	int i,j;
	
	scanf("%d %d %d", &rotate[0], &rotate[1], &rotate[2]);
	while(rotate[0] + rotate[1] + rotate[2]){
		scanf("%s",buffer);
		for(i=0;i<3;i++){
			num = 0;
			for(j=0;buffer[j];j++){
				if(inrange(i,buffer[j])){
					enc[num].alpha = buffer[j];
					enc[num++].pos = j;
				}
			}
			rotate_enc(i);
		}		
		printf("%s\n",buffer);

		scanf("%d %d %d", &rotate[0], &rotate[1], &rotate[2]);
	}

	return 0;
}
