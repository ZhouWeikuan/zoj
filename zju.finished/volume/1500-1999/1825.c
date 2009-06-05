#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize (120020)
typedef struct {
    int len;
    union{
        char *ptr;
        char alpha[20];
    };
} Node ;

Node words[MaxSize];
Node * wordlist[MaxSize];
int wnum = 0;
int pos=0;
char buffer[1024];
int buflen;

struct Alphalist {
    int tag;
    struct Alphalist *link[26];
};
typedef struct Alphalist Alphalist;

Alphalist head;

int find(char *s){
    int t;
    Alphalist *alp = &head;
    
    while(*s){
        t = *s - 'a';
        if(! alp->link[t]){
            return 0;
        }
        alp = alp->link[t];        
        s++;
    }
    
    return alp->tag;
}
void insert(Node *n){
    char *s = n->alpha;
    int t ;
    int add= 0;     /* 0, to be dicide,   1, not add, 2 add */
    Alphalist *alp = &head;
    Alphalist *ptr;
    
    do {
        t = *s - 'a';
        s++;
        
        if(alp->link[t]){
            alp  = alp ->link[t];
            if(alp->tag && add == 0){
                if(find(s)){
                    add = 2;
                    wordlist[pos++] = n;
                }
            }
        } else {
            ptr = (Alphalist *)malloc(sizeof(Alphalist));
            memset(ptr, 0, sizeof(Alphalist));
            alp->link[t] = ptr;
            alp = ptr;
            add = 1;
        }     
        
    } while(*s);
    
    alp->tag = 1;
}

int compbylen(const Node ** a, const Node **b){
    return (*a)->len - (*b)->len;
}

int compbyalpha(const Node ** a, const Node **b){
    return strcmp((*a)->alpha, (*b)->alpha);
}

int main(){
    int i;
    
    /*freopen("input.txt","r",stdin);*/
    
    scanf("%s", buffer);
    while(!feof(stdin)){
        buflen = strlen(buffer);
        wordlist[wnum] = &words[wnum];
        words[wnum].len = buflen;
        if(buflen < 20){
            strcpy(words[wnum].alpha, buffer);
        } else {
            words[wnum].ptr = malloc(sizeof(char) * (buflen +1));
            strcpy(words[wnum].alpha, buffer);
        }
        wnum ++;
        scanf("%s", buffer);
    }
    qsort(wordlist, wnum, sizeof(Node *), compbylen);
    for(i=0;i<wnum;i++){
        insert(wordlist[i]);
    }
    
    qsort(wordlist,pos, sizeof(Node *), compbyalpha);
    for(i=0;i<pos;i++){
        printf("%s\n",wordlist[i]->alpha);
    }
    
    return 0;
}
