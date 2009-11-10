#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int sortness;
	int index;
} Node;

char buffer[120][60];
Node node[120];
int num, length;

int compare(const Node *a, const Node *b){
	if(b->sortness != a->sortness)
		return a->sortness - b->sortness;
	return a->index - b->index;
}

int calc_sortness( char *str){
    int i = 0, j;
    int mult;
    int sortness = 0;
    while(i < length){
		mult = 1;
		while(str[i] == str[i+1]){
			i++;
			mult ++;
		}
		
		for(j= i+1; str[j];j++){
			if(str[j] < str[i]){
				sortness += mult;
			}
		}
		i ++;
	}
	return sortness;
}

int main(){
    int tstcase;
    int i;
    int t;
    
    scanf("%d ", &tstcase);
    while(tstcase --){
		scanf("%d %d ", &length, &num);	
		for(i=0;i<num;i++){
			scanf("%s ", buffer[i]);
			node[i].sortness = calc_sortness(buffer[i]);
			node[i].index = i;
		}
		qsort(node,num,sizeof(Node),( int (*)(const void*, const void*))compare);
		
		for(i=0;i<num;i++){
			t = node[i].index;
			printf("%s\n", buffer[t]);
		}
		
		if(tstcase)
			printf("\n");
	}
    
    return 0;
}
