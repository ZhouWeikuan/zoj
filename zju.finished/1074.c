#include<stdio.h>
#include<stdlib.h>

enum {
    MaxSize = 120,  
};

int matrix[MaxSize][MaxSize];
int sub[MaxSize];
int N;

int maxSum(){
    int sum =0;
    int b = 0;
    int i;
    for(i=0;i<N;i++){
        if(b>0){
            b+= sub[i];
        }else {
            b = sub[i];
        }
        if(b>sum)
            sum = b;
    }
    return sum;
}

int fun(){
    int i,j;
    int k,sum=0;
    int max;
    
    for(i=0;i<N;i++){        
        for(k=0;k<N;k++)
            sub[k] = 0;
        for(j=i;j<N;j++){
            for(k=0;k<N;k++){
                sub[k] += matrix[j][k];
            }
            max = maxSum();
            if(max > sum)
                sum = max;
        }        
    }
    return sum;
}

int main(){
    int i,j;
    int maxscore;

/*freopen("input.txt","r",stdin);   */
   
    scanf("%d",&N);
    while(!feof(stdin)){
        memset(matrix,0,sizeof(int)*MaxSize *MaxSize);        
        
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                scanf("%d",&matrix[i][j]);                
            }
        }
        maxscore = fun();
        printf("%d\n",maxscore);
        scanf("%d",&N);
    }
    
    return 0;
}
