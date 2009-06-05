#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 4,
	NodeNum = 8,
};

char bitmap[Size][Size];
char matrix[NodeNum][NodeNum];
int visit[NodeNum];
int match[NodeNum];
int N;
int row,col;

int dfs(int p){
	int i,t;
	for(i=0;i<row;i++){
		if(matrix[i][p] && !visit[i]){
			visit[i] = 1;
			t = match[i];
			match[i] = p;
			if(t==-1 || dfs(t))
				return 1;
			match[i] = t;
		}
	}
	return 0;
}

int maxflow(){
	int i, res =0;
	memset(match,-1,sizeof(match));
	for(i=0;i<col;i++){
		memset(visit,0,sizeof(visit));
		if(dfs(i)){
			res ++;
		}
	}
	return res;
}

void fun(){
    int i,j,t;
    row = col = 0;
    
    memset(matrix,0,sizeof(char)*NodeNum*NodeNum);
    /* scan from col*/
    for(i=0;i<N;i++){		
		j = 0;
		while(j< N){
			while(bitmap[j][i] == -1 && j < N){
				j ++;
			}
			if(j==N)
				break;			
			while(bitmap[j][i] != -1 && j < N){
				bitmap[j][i] = col;
				j ++;
			}
			col++;
		}		
	}
	/* scan from row */
	for(i=0;i<N;i++){
		j = 0;
		while(j<N){
			while(bitmap[i][j] == -1 && j < N){
				j ++;
			}
			if(j==N)
				break;			
			while(bitmap[i][j] != -1 && j < N){
				t = bitmap[i][j];
				matrix[row][t] = 1;
				
				j ++;
			}
			row++;
		}
	}
    t = maxflow();
    printf("%d\n",t);
}

int main(){
    char c;
    
    scanf("%d ", &N);
    while(N){
		for(row=0;row<N;row++){
			for(col=0;col<N;col++){
				scanf("%c ", &c);
				if(c=='.'){
					bitmap[row][col]	=  100;
				} else { /* X */
					bitmap[row][col]	=  -1;
				}
			}
		}
		fun();
		scanf("%d ", &N);
	}
    
    return 0;
}
