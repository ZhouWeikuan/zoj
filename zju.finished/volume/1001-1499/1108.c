#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int weight;
	int speed;
	int index;
}Node;

enum {
	Size = 1004,	
};

int num;
Node mouse[Size];
int  pred[Size];
int  max[Size];
int  value = 0;
int  maxpos = -1;
int comp(Node *b, Node *a){
    if(a->weight != b->weight)
    	return a->weight - b->weight;
    return a->speed - b->speed;
}

int main(){
    num = 0;
    memset(pred,-1,sizeof(pred));
    
    scanf("%d %d", &mouse[num].weight, &mouse[num].speed);
    while(!feof(stdin)){
		mouse[num].index = ++num;
		scanf("%d %d", &mouse[num].weight, &mouse[num].speed);
	}
    qsort(mouse,num,sizeof(Node),(int (*)(const void*,const void*))comp);
    
    int i,j;
    for(i=0;i<num;i++){
		for(j=i-1;j>=0;j--){
			if(mouse[i].speed > mouse[j].speed && mouse[i].weight < mouse[j].weight){
				if(max[i] <= max[j]) {
					max[i] = max[j] + 1;
					pred[i] = j;
					if(max[i] > value){
						value = max[i];
						maxpos = i;
					}
				}
			}
		}
	}
    
    printf("%d\n", value+1);
    while(maxpos >= 0){
		printf("%d\n",mouse[maxpos].index);
		maxpos = pred[maxpos];
	}
    
    return 0;
}
