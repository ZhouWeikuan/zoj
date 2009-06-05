#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* DFS 确定区间，以此辨别父子，从网上拷贝思路*/
enum {
	Size = 20000008,
};
typedef struct {
	int child;
	int num;
}Node;

Node cell[Size];
int pos;
typedef struct {
    int i,n;
    int cur;
}Stack;
Stack st[300008];
int top;

void push(int t){
    ++top;
    st[top].i = cell[t].child;
    st[top].n = cell[t].num;
    st[top].cur = t;
    cell[t].child = pos++;
}

void DFS(){
    int t;
    top = -1;
    push(0);
    while(top >= 0){
        if(st[top].n){
            t = st[top].i ++; st[top].n--;
            push(t);
        } else {
            cell[st[top].cur].num = pos++; 
            --top;
        }
    }
}

int main(){
	int tstcase;
	int caseindex = 0;
	int num;
	int cur,child;

	scanf("%d", &tstcase);
	while(tstcase --){
		pos = 1;
		cur = 0;
		scanf("%d", &num);
		while(num --){
			scanf("%d", &cell[cur].num);
			cell[cur].child = pos;
			pos += cell[cur].num;
			cur++;
		}
        for( ;cur<pos; cur++){
            cell[cur].child = 0;
            cell[cur].num = 0;
        }
		printf("Case %d:\n", ++caseindex);
		pos = 0;
		DFS();
		scanf("%d", &num);
		while(num --){
			scanf("%d %d", &cur, &child);
			if(cell[cur].child< cell[child].child 
				&& cell[cur].num > cell[child].num){
				printf("Yes\n");
			}else {
				printf("No\n");
			}
		}
		
		if(tstcase)
			printf("\n");
	}

	return 0;
}

