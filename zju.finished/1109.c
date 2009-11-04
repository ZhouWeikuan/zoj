#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
    MaxSize = 100020,
};

char english[MaxSize][12];
char buffer[40];
int pos;

struct alphalist {
    int pos;
    struct alphalist *alpha[26];
};

struct alphalist head;

void add_alpha(char *str,int pos){
    struct alphalist *p;
    struct alphalist *pred = &head;
    int t;
    
    while(*str != '\n'){
        t = *str - 'a';
        if(pred->alpha[t]){
            pred = pred->alpha[t];
        } else {
            p = (struct alphalist*)malloc(sizeof(struct alphalist));
            memset(p,0,sizeof(struct alphalist));
            p->pos = -1;
            pred->alpha[t] = p;
            pred = p;
        }
        str ++;
    }
    pred->pos = pos;
}
int query(char * str){
    struct alphalist *p = &head;
    int t;
    while(*str != '\n'){
        t = *str - 'a';
        p = p->alpha[t];
        if(p == 0){
            return -1;
        }        
        str++;
    }
    return p->pos;
}

void addtolist(char *buf){
    int i = 0;
    while(buf[i] != ' '){
        i++;
    }
    buf[i] = 0;
    strcpy(english[pos],buf);
    i++;
    add_alpha(&buf[i],pos);
    pos ++;
}

int main(){
    int result;
    pos = 0;
    
    fgets(buffer,40,stdin);
    while(buffer[0] != '\n'){
        addtolist(buffer);
        fgets(buffer,40,stdin);
    }
    
    fgets(buffer,40,stdin);
    while(!feof(stdin)){
        result = query(buffer);
        if(result != -1){
            printf("%s\n",english[result]);
        } else {
            printf("eh\n");
        }
        fgets(buffer,40,stdin);
    }    
        
    return 0;
}
