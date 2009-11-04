#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* 数据中有些关系没有列出，相当于求最大团 */
enum {
	Size = 30,
};
typedef struct {
	int pos;
	int edge[Size];
}Node;

int num,max;
Node matrix[Size];
char buffer[Size];
int stack[Size];
int sp = 0;
char map[Size][Size];

void parse(int i){
	int t;
	int j;
	for(j=2;buffer[j];j++){
		t = buffer[j] -'A';
		map[i][t] = 1;
		map[t][i] = 1;
	}
}

int MyComp(const int *a, const int *b){
	return *a - *b;
}

void fun(int i, int start){
	if(sp > max){
		max = sp;
	}
	int j,t;
	Node *n;
	for(;matrix[i].pos - start + sp > max; start++){
		t = matrix[i].edge[start];
		for(j=1;j<sp;j++){
			n = &matrix[stack[j]];
			if(bsearch(&t, n->edge, n->pos,sizeof(int), MyComp)==0){
				break;
			}
		}
		if(j!=sp)
			continue;
		stack[sp++] = t;
		fun(i,start+1);
		--sp;
	}
}

int main(){
	int i,j;
	scanf("%d", &num);
	while(num > 0){
		max = 1;
		memset(map,0,sizeof(map));
		for(i=0;i<num;i++){
			scanf("%s", buffer);
			parse(i);
		}
		for(i=0;i<num;i++){
			int n=0;
			for(j=i+1;j<num;j++){
				if(map[i][j]){
					matrix[i].edge[n++] = j;
				}
			}
			matrix[i].pos = n;
		}
		for(i=0;num - i > max;i++) {
			if(matrix[i].pos >= max){
				stack[sp++] = i;
				fun(i,0);
				--sp;
			}
		}
		printf("%d channel", max);
		if(max > 1){
			printf("s");
		}
		printf(" needed.\n");
	
		scanf("%d", &num);
	}
	return 0;
}
