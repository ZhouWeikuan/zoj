#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pos;
int perm[50008];

int num;
int input[100];
int *data[100];

int list[100];

void siftup(int leaf){
    int t, root;
    while(leaf != 0){
		root = (leaf -1 )/2;
		t = perm[leaf]; perm[leaf] = perm[root]; perm[root] = t;
		leaf = root;
	}
}

int MyComp(const int *a, const int *b){
	return input[*a] - input[*b];
}

int main(){
    int i,t;
    num = 0;
    
    scanf("%d", &t);
    while(!feof(stdin)){
		input[num] = t;
		list[num] = num;
		data[num] = malloc(sizeof(int) * t);
		
		num ++;
		scanf("%d", &t);
	}
    
    qsort(list, num, sizeof(int), MyComp);
    
    
    
    pos = 1;
    perm[0] = 1;
    
    for(i=0;i<num;i++){
    	while(pos<input[list[i]]){		
			perm[pos] = perm[pos-1];
			perm[pos-1] = pos + 1;
			siftup(pos-1);
			pos ++;		
		}
		memcpy(data[list[i]], perm, sizeof(int) * pos);
	}
	int *ptr;
	for(i=0;i<num;i++){
		ptr = data[i];
		printf("%d", ptr[0]);
		for(t=1;t<input[i];t++){
			printf(" %d", ptr[t]);
		}
		printf("\n");
	}
    return 0;
}
