#include<iostream>
using namespace std;
enum {
    SIZ = 108,
    FLen = 66,
};
struct Node {
    int len;
    char file[FLen];
};
int num;
Node tree[SIZ];
int prefix, postfix, len;
char buf[FLen];

void match(){
    int i;
    for(i=0;buf[i];i++){
        if(buf[i]=='*'){
            prefix = i;
        }
    }
    len  = i;
    postfix = len - prefix - 1;
    int m = 0;
    for(i=0;i<num;i++){
        if(tree[i].len < prefix + postfix)
            continue;
        if(strncmp(tree[i].file, buf, prefix)==0
              && strncmp(tree[i].file+tree[i].len-postfix, 
                  buf+len-postfix, postfix)==0){
            if(m==0){
                printf("%s", tree[i].file);
            } else {
                printf(", %s", tree[i].file);
            }
            m++;
        }
    }
    if(m==0){
        printf("FILE NOT FOUND");
    }
    printf("\n");
}
void fun(){
    int i;
    for(i=0;i<num;i++){
        scanf("%s",tree[i].file);
        tree[i].len = strlen(tree[i].file);
    }
    scanf("%d",&i);
    while(i--){
        scanf("%s",buf);
        match();
    }
}

int main(){
    int tstcase = 0;
    while(scanf("%d",&num) >0){
        if(tstcase++)
            printf("\n");
        fun();
    }
    return 0;
}
