#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 1008,	
};
typedef struct {
	int start;
	int end;
	int index;
} Node;

int pred[Size];
int max[Size];
Node exon[Size];
int num;

int compare(Node *a, Node *b){
	if(a->start != b->start)
		return a->start - b->start;
	return a->end - b->end;
}

void traceback(int n){
	if(pred[n] != -1){
		traceback(pred[n]);
	}
	if(pred[n] == -1)
		printf("%d", exon[n].index);
	else 
		printf(" %d",exon[n].index);
}

void fun(){
	int i,j;
	int value = 0;
	int maxpos = 0;
    memset(pred,-1,sizeof(int)*num);
    memset(max,0,sizeof(int)*num);
    for(i=0;i<num;i++){
		for(j=i-1;j>=0;j--){
			if(exon[i].start > exon[j].end){
				if(max[i] < max[j] +1){
					max[i] = max[j] + 1;
					pred[i] = j;
					if(value < max[i]){
						value = max[i];
						maxpos = i;
					}
				}
			}
		}
	}
	
	traceback(maxpos);
	printf("\n");
}

int main(){
    int i;
    
    scanf("%d ", &num);
    while(num){
		for(i=0;i<num;i++){
			scanf("%d %d ", &exon[i].start, &exon[i].end);
			exon[i].index = i+1;
		}
		qsort(exon, num, sizeof(Node), (int (*)(const void*,const void*))compare);
		fun();
		scanf("%d ", &num);	
	}
    
    return 0;
}
