#include<stdio.h>

char buf[512];
char seq[512];
int matrix[26][512][512];
int maxlen;

void init(){
    maxlen = 0;
    memset(matrix,-1,sizeof(int) *512*512 * 26);    
}

void calc(int i, int j, char c){
    int t ;
    int pos = c - 'a';
    pos = (c==0)? 0 : pos;
    if(matrix[pos][i][j] != -1){
        return ;
    }
    if(buf[i] == 0 || seq[j] == 0){        
        matrix[pos][i][j] = 0;        
        return ;
    }
    if(buf[i] == seq[j]){
        calc(i+1,j+1,buf[i]);
        t = matrix[buf[i] - 'a'][i+1][j+1] + 1;
        calc(i+1,j+1,c);        
        t = t < matrix[pos][i+1][j+1]? matrix[pos][i+1][j+1] : t;
        matrix[pos][i][j] = matrix[pos][i][j] < t?t:matrix[pos][i][j];
        t = matrix[pos][i][j];
        maxlen = maxlen < t ? t: maxlen;
        return;
    }
    calc(i+1,j,c);
    t = matrix[pos][i+1][j];
    calc(i,j+1,c);
    t = t < matrix[pos][i][j+1]? matrix[pos][i][j+1] :t;
    matrix[pos][i][j] = matrix[pos][i][j] < t?t:matrix[pos][i][j];
    maxlen = maxlen < t ? t: maxlen;
}

void fun(){
    init();
    calc(0,0,0);
    printf("%d\n", maxlen);
}


int main(){
    
    scanf("%s",buf);
    while(!feof(stdin)){
        scanf("%s",seq);
        fun();        
        scanf("%s",buf);
    }
    return 0;
}
