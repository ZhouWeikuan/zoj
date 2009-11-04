#include<stdio.h>
#include<stdlib.h>

short table[8] ={
    0,
    125,
    250,
    375,
    500,
    625,
    750,
    875
};

typedef struct  myNode {
    int num;
    struct myNode *link;
}Node ;

Node head = {0,0};

void clear(){
    Node *p, *q;
    p = head.link;
    while(p){
        q = p;
        p = q->link;
        free(q);
    }
    head.num =0;
    head.link = 0;
}

void div8(){
    int left = 0;
    int t = 0;
    Node *p = &head;
    Node *q = p;
    
    while(p){
        t = p->num % 8;
        p->num = table[left] + p->num/8;
        left = t;
        q = p;
        p = p->link;        
    }
    p = q;
    if(left){
        Node * q = (Node *) malloc(sizeof(Node));
        q->num = table[left];
        q->link = 0;
        p->link = q;
    }    
}

void add(int i){
    head.num += table[i];
}

void print(){
    Node *p = &head;
    int t;
    int pre = 3;
    printf("0.");
    while(p->link){
        printf("%03d",p->num);
        p = p->link;
    }
    t = p->num;
    while( t && t%10 ==0){
        t /= 10;
        pre --;
    }
    printf("%0*d",pre,t);
    printf(" [10]\n");
}

void fun(){
    char c;
    int i;
    scanf("%c",&c);
    if(c =='\n'){
        return;
    }
    printf("%c",c);
    fun();
    i = c -'0';
    div8();
    add(i);        
}

int main(){
    char c;   
    
    scanf("%c",&c);
    while( !feof(stdin)){        
        scanf("%c",&c);
        printf("0.");
        fun();
        printf(" [8] = ");
        print();
        clear();
        scanf("%c",&c);
    }
    
    return 0;
}
