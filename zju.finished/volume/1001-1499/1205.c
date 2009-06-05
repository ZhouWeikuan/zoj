#include<stdio.h>

char alpha[120];
int apos;
char buffer[120];
int bpos;
char sum[120];
int spos;

int trans(char *p){
    int i=0;
    while(p[i]){
        if(p[i] >='0' && p[i] <= '9'){
            p[i] -= '0';
        } else {
            p[i] -= 'a';
            p[i] += 10;
        }
        i ++;        
    }
    return i;
}

void add(){
    int carry = 0;
    spos = 0;
    apos --;
    bpos --;
    
    while(apos >=0 && bpos >=0){
        sum[spos] = alpha[apos--] + buffer[bpos--] + carry;
        if(sum[spos] > 19){
            carry = sum[spos] / 20;
            sum[spos] -= 20;
        } else {
            carry = 0;
        }
        spos ++;
    }
    while(apos >=0){
        sum[spos] = alpha[apos--] + carry;
        if(sum[spos] > 19){
            carry = sum[spos] / 20;
            sum[spos] -= 20;
        } else {
            carry = 0;
        }
        spos ++;
    }
    while(bpos >=0){
        sum[spos] = buffer[bpos--] + carry;
        if(sum[spos] > 19){
            carry = sum[spos] / 20;
            sum[spos] -= 20;
        } else {
            carry = 0;
        }
        spos ++;
    }
    if(carry){
        sum[spos++] = carry;
    }
    
}

void print(){
    apos = 0;
    spos --;
    
    while(spos >=0){
        if(sum[spos] < 10){
            alpha[apos] = sum[spos] + '0';
        } else {
            alpha[apos] = sum[spos] + 'a' - 10;
        }
        
        apos ++;
        spos --;
    }
    alpha[apos] = 0;
    printf("%s\n",alpha);
}

void fun(){
    apos = trans(alpha);    
    bpos = trans(buffer);
    
    add();
    print();
}

int main(){
    
    scanf("%s", alpha);
    while(!feof(stdin)){
        scanf("%s", buffer);    
        fun();                
        scanf("%s", alpha);
    }    
    return 0;
}
