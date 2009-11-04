#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int count;
    int pos;
    int pred;
    char conn[50];
}Node ;
Node map[50];

int num;
int pos;
int lace[2000];

void init(){
    int i;
    memset(map,0, sizeof(Node)*num);
    for(i=0;i<num;i++){
        map[i].count = num-1;
        map[i].pos = i+1;
        map[i].conn[i] = 1;
        map[i].pred = i-1;
    }
    map[num-1].pos = 0;
    map[0].pred = num-1;
    
    pos = 0;
}

void process(){
    int k=0;
    int i=0;
    int p;
    int flag = 0;
    init();
    
    lace[pos++] = i;
    
    while(k < num){
        while(map[i].count == 0){
            flag = 1;
            k++;
            i++;
            i %= num;
            if(k >= num){
                return;
            }
        }
        if(flag){
            flag = 0;
            lace[pos++] = i;
        }
        
            p = map[i].pos;
            map[i].conn[p] = 1;
            map[p].conn[i] = 1;
            lace[pos++] = p;
            map[i].pos  = (p+1) %num;
            map[i].count --;
            map[p].count --;
            
            i = p;        
    }
}
void output(){
    --pos;
    if(lace[pos] != 0){
        ++pos;
    }
    int i;
    printf("%d\n0", pos);
    for(i=1;i<pos;i++){
        printf(" %d",lace[i]);
    }
    printf("\n");
}

int main(){
    
    scanf("%d", &num);
    while(!feof(stdin)){
        process();
        output();
        scanf("%d", &num);
    }
    return 0;
}
