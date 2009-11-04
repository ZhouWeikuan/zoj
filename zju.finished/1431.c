#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[24];
    int  weight;
} Dieter;

Dieter  dlist[24];
int dnum = 0;

void print(){
    int i;
    for(i=0; i< dnum;i++){
        printf("%s\n", dlist[i].name);
    }
}

int comp(const Dieter * b, const Dieter *a){
    return a->weight - b->weight;
}

int main(){
    int d,w;
    int tstnum = 0;
    scanf("%s", dlist[dnum].name);
    while(!feof(stdin)){
        if(tstnum !=0 ){
            printf("\n");            
        }
        tstnum ++;
                
        dnum = 0;
        scanf("%s", dlist[dnum].name);
        while(strcmp(dlist[dnum].name,"END") != 0){
            scanf("%d %d", &d, &w);
            w  -= d;
            w = w<1?1:w;
            dlist[dnum].weight = w;
            dnum++;        
            scanf("%s", dlist[dnum].name);    
        }
        qsort(dlist,dnum, sizeof(Dieter),comp);
        print();
        scanf("%s", dlist[dnum].name);
    }   
    
    return 0;
}
