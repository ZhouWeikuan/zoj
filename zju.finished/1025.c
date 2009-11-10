#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
    MaxSize = 5020,
    RandSize = 20,
};

typedef struct {
    short length;
    short weight;
    short linknum;
    short prepos;
} Stick;

Stick wood[MaxSize];
short stack[MaxSize];

int sticknum;

int comp(const Stick *a, const Stick *b){
    if(a->length != b->length)
        return a->length - b->length;
    return a->weight - b->weight;
}

int dynamic_program(int s,int e){    
    int pos = 0;
    int flag = 0;
    int i,j;
    
    for(i=sticknum-1;i>=0;i--){
        flag = 0;
        for(j=0;j<pos;j++){
            if(wood[i].weight<= stack[j]){
                stack[j] = wood[i].weight;
                flag = 1;
                break;
            }
        }
        if(flag ==0){
            stack[pos++] = wood[i].weight;
        }
    }
    
    return pos;
}

void fun(){
    int d;
    
    d = dynamic_program(0,sticknum);    
   
    printf("%d\n", d);
}

int main(){
    int tstnum = 1;
    int i;

    scanf("%d", &tstnum);  
    
    while(tstnum--){
        scanf("%d", &sticknum);
        
        for(i=0;i<sticknum;i++){
            scanf("%d %d", &wood[i].length, & wood[i].weight); 
            
            wood[i].linknum = 0;
            wood[i].prepos = -1;
        }
        
        qsort(wood, sticknum, sizeof(Stick), (int (*)(const void *, const void*))comp);        
        fun();
    }    
    
    return 0;
}
