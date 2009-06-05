#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char id;
	int left;
	int right;
}Node ;

enum {
	Size = 32,
};

char buffer[Size];
Node tree[Size];
int  num;

void DFS(int n){
	if(n < 0)
		return;
	printf("%c",tree[n].id);
	DFS(tree[n].left);
	DFS(tree[n].right);
}

void fun(){
	int root = num-1;
	int i,up;
	
	for(i=root-1;i>=0;i--){
		up = root;
		while(up != i){
			if(tree[i].id < tree[up].id){
				if(tree[up].left !=-1){
					up = tree[up].left;
				}else{
					tree[up].left = i;
					up = i;
				}
			}else {
				if(tree[up].right != -1){
					up = tree[up].right;
				} else {
					tree[up].right = i;
					up = i;
				}
			}
		}
	}
	DFS(root);
	printf("\n");
}

int main(){
	int i;
	scanf("%s", buffer);
	while(buffer[0] != '$'){
		num = 0;
		while(buffer[0] != '*' && buffer[0] != '$'){
			for(i=0; buffer[i]; i++){
				tree[num].id = buffer[i];
				tree[num].left = tree[num].right = -1;
				num++;
			}
			scanf("%s", buffer);
		}
		if(num ==0){
			printf("\n");
		} else {
			fun();
		}

		if(buffer[0] =='$')
			break;
		
		scanf("%s", buffer);		
	}

	return 0;
}
