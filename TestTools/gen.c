#include<stdio.h>
#include<stdlib.h>
#include<time.h>
enum {
    SIZ = 20,
};
struct Node {
    int pos;
    int ptr[SIZ + 4];
};
Node tree[SIZ + 4];
int num;
void init(){
    for(int i=0;i<num;i++)
        tree[i].pos = 0;
}
void gen(){
    int k;
    for(int i=1;i<num;i++){
        k = random()%i;
        tree[k].ptr[tree[k].pos++] = i;
    }
}
void output(){
    printf("%d\n",num);
    for(int i=0;i<num;i++){
        printf("%d:(%d)", i, tree[i].pos);
        for(int j=0;j<tree[i].pos;j++){
            printf(" %d", tree[i].ptr[j]);
        }
        printf("\n");
    }
}
int main(){
    int tstcase;
    srandom(time(NULL));
    tstcase = random()%SIZ + 1;
    while(tstcase --){
        num = random()%SIZ + 1;
        if(num == 1)
            num ++;
        init();
        gen();
        output();
    }

    return 0;
}
