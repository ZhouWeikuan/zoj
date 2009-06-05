#include<stdio.h>

char buffer[2][100];
int apos;
int bpos;
char result[100];
int rpos;

void trans(char *p, int *len){    
    int i = 0;
    while(p[i]){
        p[i] -= '0';
        i ++;
    }
    *len = i;
}

void fun(){
    int i = 0, j =0;
    rpos = 0;
    int carry = 0;
    while(i< apos && j<bpos){
        carry = carry + buffer[0][i] + buffer[1][j];
        result[rpos++] = carry % 10;
        carry /= 10;        
        i++;
        j++;
    }
    while(i<apos){
        carry = carry + buffer[0][i];
        result[rpos++] = carry % 10;
        carry /= 10;        
        i++;        
    }
    while(j<bpos){
        carry = carry + buffer[1][j];
        result[rpos++] = carry % 10;
        carry /= 10;        
        j++;        
    }
    if(carry){
        result[rpos++] = carry;
    }
    i = 0;
    while(result[i] == 0){
        i++;
    }
    --rpos;
    while(result[rpos]==0){
        --rpos;
    }
    ++ rpos;
    j = i;
    while(i<rpos){
        result[i] += '0';
        i++;
    }
    result[rpos] = 0;
    printf("%s\n", &result[j]);
}

int main(){
    int tstnum;    
    
    scanf("%d\n",&tstnum);
    while(tstnum --){
        scanf("%s %s",buffer[0],buffer[1]);
        trans(buffer[0],&apos);
        trans(buffer[1],&bpos);
        fun();
    }
    
    return 0;
}
