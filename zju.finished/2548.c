#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N,M;
char chose[10000];
int stack[200];
int pos;

const char *ans[2]={
	"no",
	"yes"
};

int main(){
	int c,k,r,f,t;
	
	scanf("%d", &N);
	while(N > 0){
		scanf("%d", &M);
		pos = 0;
		while(N--){
			scanf("%d", &c);
			chose[c] = 1;
			stack[pos++] = c;
		}
		c = 1;
		while(M--){
			scanf("%d %d", &k,&r);
			f= 0;
			while(k--){
				scanf("%d",&t);
				f += chose[t];
			}
			if(c && f<r)
				c=0;
		}
		printf("%s\n",ans[c]);
		while(pos){
			--pos;
			chose[stack[pos]] = 0;
		}

		scanf("%d", &N);
	}

	return 0;
}
