#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct {
	int pos;
	char buffer[600];
}TABLE;

TABLE table[221];

typedef struct {
	int pos;
	int buffer[600];
}Node;
Node result[2],one;

void multply(Node *res, Node *mult, Node *from){
	memset(res,0,sizeof(Node));
	int i,j,carry;
	
	for(i=0;i<from->pos;i++){
		for(j=0;j<mult->pos;j++){
			if(i+j >= res->pos){
				res->pos = i+j+1;
			}
			res->buffer[i+j] += from->buffer[i] * mult->buffer[j];
		}
		carry = 0;
		for(j=0;j<res->pos;j++){
			carry += res->buffer[j];
			res->buffer[j] = carry %10;
			carry /= 10;
		}
		while(carry){
			res->buffer[res->pos++] = carry %10;
			carry /= 10;
		}
	}
}

void get(Node *p,int i){
	p->pos = 0;
	while(i){
		p->buffer[p->pos++] = i%10;
		i/=10;
	}
}

void insert(Node *p, int n){
	int i;
	for(i=0;i<p->pos;i++){
		table[n].buffer[i] = '0' + p->buffer[p->pos - i -1];
	}
	table[n].pos = p->pos;
}

void init(){
   int i;
   int n;
   Node *mult, *rest,*t;
   mult = &result[0];
   rest = &result[1];
   table[0].pos = 0;
   table[1].pos = 1;
   table[1].buffer[0]= '1';

   for(i=2;i<221;i++){
	   get(&one,i);
	   mult->pos = one.pos;
	   for(n=0;n<one.pos;n++)
		   mult->buffer[n] = one.buffer[n];
		n = i;
		while(n > 0){
			n --;
			multply(rest,mult,&one);
			t = mult, mult = rest, rest= t;
		}
		insert(rest,i);
   }
}

int comp(const TABLE *k, const TABLE *p){
	if( k->pos != p->pos)
		return k->pos - p->pos;
	return strcmp(k->buffer,p->buffer);
}

int main(){
	int tstcase;
	TABLE key;
	TABLE *ptr;
	init();
	
	scanf("%d",&tstcase);
	while(tstcase --){
		scanf("%s",key.buffer);
		key.pos = strlen(key.buffer); 
		ptr = bsearch(&key,table,221,sizeof(TABLE),comp);
		if(ptr != 0){
			printf("%d\n", ptr - table);
		} else {
			printf("-1\n");
		}
	}

	return 0;
}
