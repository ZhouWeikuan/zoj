#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 12,
};

struct {
	char orig[256];
	int olen;
	char rep[256];
	int rlen;
}rule[Size];
int rpos;

char buffer[2][1024];
char *from, *to;

void fun(){
	int i;
	char *p;
	int t;
	from = buffer[0];
	to 	 = buffer[1];
	
	for(i=0;i<rpos;i++){
		p = strstr(from, rule[i].orig);
		while(p != 0 ){
			t = p - from;
			strncpy(to,from,t);
			strncpy(to+t, rule[i].rep, rule[i].rlen);
			strcpy(to +t +rule[i].rlen, from +t + rule[i].olen);
			p = from, from = to, to = p;
			p = strstr(from, rule[i].orig);
		}		
	}
	printf("%s", from);
}

int main(){
	int i;
	scanf("%d ", &rpos);
	while(rpos ){
		for(i=0;i<rpos;i++){
			fgets(rule[i].orig,256,stdin);
			fgets(rule[i].rep,256,stdin);
			rule[i].olen = strlen(rule[i].orig);
			rule[i].orig[--rule[i].olen] = 0;
			rule[i].rlen = strlen(rule[i].rep);
			rule[i].rep[-- rule[i].rlen] = 0;
		}
		fgets(buffer[0], 1024, stdin);
		fun();
		scanf("%d ", &rpos);
	}

	return 0;
}
