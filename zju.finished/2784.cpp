#include<iostream>
using namespace std;
enum {
    SIZ = 64,
};
const char *dna="ACGT";
int getDNA(char c){
    for(int i=0; i<4; i++){
        if(c==dna[i])
            return i;
    }
    return 0;
}

struct Node {
    int use;
    Node *lnk[4];
};
Node *next=0;
void putNode(Node *p){
    p->lnk[0] = next;
    next = p;
}
Node *getNode(){
    if(next == 0){
        next = (Node*) malloc(sizeof(Node)*SIZ);
        for(int i=0; i<SIZ; i++){
            next[i].lnk[0] = &next[i+1];
        }
        next[SIZ-1].lnk[0] = 0;
    }
    Node *p = next;
    next = next->lnk[0];
    memset(p, 0, sizeof(Node));
    return p;
}
void clear(Node *p){
    if(p == 0) return;
    for(int i=0; i<4; i++){
        clear(p->lnk[i]);
    }
    putNode(p);
}
void append(Node *p, char *s){
    int t;
    while(*s){
        t = getDNA(*s);
        if(p->lnk[t] == 0){
            p->lnk[t] = getNode();
        }
        p = p->lnk[t];
        p->use = 1;
        s++;
    }
}

int  num, lvl, top, pos;
int  st[SIZ], sav[SIZ];
char str[16][SIZ];
Node *head;

void search(Node *p, char *s){
    int t;
    while(*s){
        t = getDNA(*s);
        if(p->lnk[t]==0) return;
        if(p->lnk[t]->use < lvl){
            clear(p->lnk[t]);
            p->lnk[t] = 0;
            return;
        }
        p = p->lnk[t];
        p->use = lvl + 1;
        s++;
    }
}

void update(Node *p){
    int i;
    for(i=0; i<4; i++){
        if(p->lnk[i] && p->lnk[i]->use == num){
            st[top++] = i;
            update(p->lnk[i]);
            --top;
        }
    }
    if(top > pos){
        for(i=0; i<top; i++){
            sav[i] = st[i];
        }
        pos = top;
    }
}

void fun(){
    int i, j;
    for(i=1; i<num; i++){
        lvl = i;
        for(j=0; str[i][j]; j++){
            search(head, &str[i][j]);
        }
    }

    top = pos = 0;
    update(head);
    if(pos < 3){
        printf("no significant commonalities\n");
    } else {
        for(i=0; i<pos; i++){
            printf("%c", dna[sav[i]]);
        }
        printf("\n");
    }
    clear(head);
    head = 0;
}

void readIn(){
    int i;
    scanf("%d ", &num);
    for(i=0; i<num; i++){
        scanf("%s ", str[i]);
    }
    head = getNode();
    head->use = 1;
    int len = strlen(str[0])-2;
    for(i=0; i<len; i++){
        append(head, &str[0][i]);
    }
}
int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst--){
        readIn();
        fun();
    }
    return 0;
}

