#include<stdio.h>
#include<stdlib.h>

enum {
    MaxSize = 6000,
};

typedef struct {
    int len;
    char *alpha;
} Node ;

Node table[MaxSize];

void init(){
    table[0].len = 1;
    table[1].len = 1;
    table[1].alpha = (char *)malloc(sizeof(char)*2);    
    table[1].alpha[0] = 1;
    table[2].len = 1;
    table[2].alpha = table[0].alpha = table[1].alpha ;
    
}

void calc(int n){
    if(table[n].len > 0){
        return;
    }
    calc(n-1);    
    
    table[n].len = table[n-1].len + 1;
    table[n].alpha = (char *)malloc(sizeof(char)* table[n].len);
    table[n].len = 0;
    
    int i= 0;
    int carry = 0;
    int k = 0;
    
    while(i < table[n-2].len){
        carry = table[n-2].alpha[i] + table[n-1].alpha[i] + carry;
        if(carry > 9){
            table[n].alpha[k] = carry - 10;
            carry /= 10;
        } else {
            table[n].alpha[k] = carry;
            carry = 0;
        }
        i++;
        k++;
    }
    while(i < table[n-1].len){
        carry = table[n-1].alpha[i] + carry;
        if(carry > 9){
            table[n].alpha[k] = carry - 10;
            carry /= 10;
        } else {
            table[n].alpha[k] = carry;
            carry = 0;
        }
        i++;
        k++;
    }
    if(carry){
        table[n].alpha[k] = carry;
        k++;
    }
    table[n].len = k;
}

void print(int n){
    static char buffer[1020];
    int i = table[n].len-1;
    int p = 0;
    while(i>=0){
        buffer[p] = table[n].alpha[i] + '0';
        i--;
        p++;
    }
    buffer[p] = 0;
    printf("%s\n",buffer);
}

int main(){
    int num;
    init();
    
    scanf("%d",&num);
    while(!feof(stdin)){
        calc(num);
        print(num);
        scanf("%d",&num);
    }        
    
    return 0;
}
