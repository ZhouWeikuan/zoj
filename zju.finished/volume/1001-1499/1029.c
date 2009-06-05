#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 408,	
};

typedef struct {
	int start;
	int end;
} Node;

Node table[Size];
Node sequence[Size];
int num,pos;

int comp(const Node *a, const Node *b){
	if(a->start != b->start)
		return a->start - b->start;
	return a->end - b->end;
}

int fun(){
	int i,j;
	int flag;
    pos =0;
    
    for(i=0;i<num;i++){
		flag = 0;
		for(j=0;j<pos;j++){
			if(table[i].start > sequence[j].end){				
				if(table[i].start - sequence[j].end ==1 && table[i].start%2==0){
					;
				} else {
					flag = 1;
					sequence[j] = table[i];				
					break;
				}
			}
		}
		if(flag ==0){
			sequence[pos] = table[i];
			pos ++;
		}
	}
	return pos;
}

int main(){
    int tstcase ;
    int i;
    int t;
    
    scanf("%d", &tstcase);
    while(tstcase --){
		scanf("%d", &num);
		for(i=0;i<num;i++){
			scanf("%d %d", &table[i].start, &table[i].end);
			if( table[i].start > table[i].end){
				t = table[i].start;
				table[i].start = table[i].end;
				table[i].end = t;
			}
		}
		qsort(table,num,sizeof(Node),comp);
		i = fun();
		i *= 10;
		printf("%d\n", i);
		
	}
    
    return 0;
}
