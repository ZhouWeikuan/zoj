#include<iostream>
using namespace std;
enum {
    SIZ = 26,
};
struct Node {
    int cnt;
    Node * link[SIZ];
};
int num;
char word[1008][24];
Node tmp[SIZ*1000];
Node *head, *next;
void init(){
    next = 0;
}
Node *getNode(){
    Node *p;
    if(next == 0){
        p = (Node*)malloc(sizeof(Node)*200);
        int i;
        for(i=0; i<199; i++){
            p[i].link[0] = &p[i+1];
        }
        p[i].link[0] = 0;
        next = &p[0];
    }
    p = next;
    next = p->link[0];
    memset(p, 0, sizeof(Node));
    return p;
}
void putNode(Node *p){
    p->link[0] = next;
    next = p;
}
void clear(Node *p){
    p->cnt = 0;
    for(int i=0; i<SIZ; i++){
        if(p->link[i]){
            clear(p->link[i]);
            p->link[i] = 0;
        }
    }
    putNode(p);
}

char *fetch(Node *p, char *s){
    char *e = s;
    for(;*e && p->cnt!=1; e++){
        p = p->link[*e-'a'];
    }
    *e = 0;
    return s;
}

void fun(){
    for(int i=0; i<num; i++){
        printf("%s ",  word[i]);
        printf("%s\n", fetch(head, word[i]));
    }
}

void addWord(Node *p, char *s){
    int t;
    while(*s != '\n'){
        p->cnt++;
        t = *s -'a';
        if(p->link[t] == 0){
            p->link[t] = getNode();
        }
        p = p->link[t];
        s++;
    }
    p->cnt++;
    *s = 0;
}

void readIn(){
    num = 0;
    fgets(word[num], 24, stdin);
    while(word[num][0] != '\n'){
        addWord(head, word[num]);
        num++;
        fgets(word[num], 24, stdin);
    }
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst--){
        head = getNode();
        readIn();
        fun();
        clear(head);
        if(tst) printf("\n");
    }
    return 0;
}

