#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 8,
};

int chess[Size][Size];
int queue[100];
int head,tail;

char buffer[20];
int source,dest;

void insert(int x, int y, int s){
	if(x >= 8 || y>= 8 || x < 0 || y < 0)
		return;
	if(chess[x][y] ==1 )
		return;
	int t = (s <<16) + (y) + (x<<8);
	queue[head ++] = t;
	chess[x][y] = 1;
}

int fun(){
	int step;
	int x,y;
	head = tail = 0;
	memset(chess,0,sizeof(chess));
	queue[head++] = source;
	chess[source>>8&0xff][source&0xff] = 1;
	while(tail < head){
		x = queue[tail ++];
		step = x >> 16;
		x &= 0xffff;
		if(x == dest){
			return step;
		}
		y = (x &0xff);
		x >>= 8;
		step ++;
		insert(x-1,y-2,step);
		insert(x-1,y+2,step);
		insert(x+1,y-2,step);
		insert(x+1,y+2,step);
		insert(x-2,y-1,step);
		insert(x-2,y+1,step);
		insert(x+2,y-1,step);
		insert(x+2,y+1,step);
	}
	return -1;
}

int main(){
	int t;
	scanf("%s", buffer);
	while(!feof(stdin)){
		printf("To get from %s to",buffer);
		source = 0;	
		t = buffer[0] -'a';
		t <<= 8;
		t += buffer[1]-'1';
		source +=t;
		scanf("%s", buffer);
		printf(" %s takes",buffer);
		t = buffer[0] -'a';
		t <<=8;
		t+= buffer[1]-'1';
		dest = t;
		t = fun();
		printf(" %d knight moves.\n",t);
		
		scanf("%s", buffer);
	}

	return 0;
}
