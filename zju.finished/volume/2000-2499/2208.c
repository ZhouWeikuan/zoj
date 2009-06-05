#include<stdio.h>
#include<string.h>

int Col;
int Row;
int buflen;
char buffer[240];
char output[240];
char matrix[24][24];

int fun(){
    int i,j;
    int t;
    
    buflen = strlen(buffer);
    Row = buflen / Col;
    
    for(i=0;i<Row;i++){
        if(i%2==0){
            strncpy(matrix[i], &buffer[i*Col],Col);
        } else {
            for(j=0;j<Col;j++){
                matrix[i][j] = buffer[i*Col + Col -j -1];
            }
        }
        matrix[i][Col] = 0;
    }
    t = 0;
    for(i=0;i<Col;i++){
        for(j=0;j<Row;j++){
            output[t++] = matrix[j][i];
        }
    }
    output[t] =0;
    printf("%s\n",output);
}

int main(){
    
    
    scanf("%d",&Col);
    while(Col ){
        scanf("%s",buffer);
        fun();
        scanf("%d",&Col);
    }
    
    return 0;
}
