#include<stdio.h>
#include<stdlib.h>

enum {
	Size = 26,
};

int relation[1000];
int pos;
int limit;

char matrix[Size][Size];

void searchup(int s,int cur){
	int i;
	for(i=0;i<=limit;i++){
		if(matrix[cur][i] ==1 && matrix[s][i] ==0){
			matrix[s][i] = 1;
			matrix[i][s] = -1;
			relation[pos++] = (s<<8) + i;
			searchup(s,i);
		}
	}
}

void searchdown(int s, int cur){
	int i;
	for(i=0;i<=limit;i++){
		if(matrix[cur][i] ==-1 && matrix[s][i] ==0){
			matrix[s][i] = -1;
			matrix[i][s] = 1;
			relation[pos++] = (i<<8) + s;
			searchdown(s,i);
		}
	}
}

int compare(const int *a, const int *b){
	return *a - *b;
}

int fun(){
    int i;
    int num;
    char first,c,second;
    
    memset(matrix,0, sizeof(char) *Size *Size);
    pos = 0;
    limit = 0;
    
    scanf("%d ", &num);
    for(i=0;i<num;i++){
		scanf("%c%c%c ", &first,&c,&second);
		first -= 'A';
		limit = limit < first? first:limit;
		second -= 'A';
		limit = limit < second? second: limit;
		if(c=='<'){
			matrix[first][second] = 1;
			matrix[second][first] = -1;
		} else {
			matrix[first][second] = -1;
			matrix[second][first] = 1;
		}
	}
	int j;
	for(i=0;i<=limit;i++){
		for(j=0; j<= limit; j++){
			if(i==j)
				continue;
			if(matrix[i][j] == 1){
				searchup(i,j);
			} else if(matrix[i][j] == -1){
				searchdown(i,j);
			}
		}
	}
	
	qsort(relation, pos, sizeof(int), (int (*)(const void*,const void*))compare);
}

int main(){
    int tstnum;
    int i = 0;
    
    scanf("%d ", &tstnum);
    while(i++ < tstnum){		
		fun();
		printf("Case %d:\n",i);
		if(pos ==0){
			printf("NONE\n");
		} else {
			int t;
			for(t=0;t < pos; t++){
				printf("%c<%c\n", (relation[t]>>8) + 'A', (relation[t] &0x0ff) + 'A');
			}
		}
		
	}
    
    return 0;
}
