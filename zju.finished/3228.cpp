#include<iostream>
#include<cstdio>
using namespace std;
enum {
    SIZ = 100004,
    ALP = 26,
};
struct Node {
    Node *lnk[ALP];
    int last;
    int cnt[2];
};

int next = 0, len;
Node cache[6*SIZ], *head;
char buf[SIZ];
Node *getNode(){
    return &cache[next++];
}

int query(int type){
    Node *p = head;
    int t;
    for(int i=0; buf[i]; ++i){
        t = buf[i] - 'a';
        if (p->lnk[t] == 0)
            return 0;
        p = p->lnk[t];
    }
    return p->cnt[type];
}

void fun(){
    int num, type;
    scanf("%d", &num);
    while(num--){
        scanf("%d%s", &type, buf);
        type = query(type);
        printf("%d\n", type);
    }
}

void gen(int s){
    Node *p = head, *q;
    int t;
    for (int e=s; e<len && e-s<6; ++e){
        t = buf[e];
        if (p->lnk[t] == 0){
            q = getNode();
            q->last = -100;
            p->lnk[t] = q;
        } else {
            q = p->lnk[t];
        }
        if (s - q->last > e - s){
            ++q->cnt[1];
            q->last = s;
        }
        ++q->cnt[0];
        p = q;
    }
}

int readIn(){
    if (scanf("%s", buf) < 0)
        return 0;
    head = getNode();
    head->last = -100;
    for (len=0; buf[len]; ++len){
        buf[len] = buf[len]-'a';
    }
    for (int i=0; i<len; ++i){
        gen(i);
    }
    return 1;
}

int main(){
    int tn = 1;
    while(readIn() > 0){
        printf("Case %d\n", tn++);
        fun();
        memset(cache, 0, sizeof(cache[0])*next);
        next = 0;
        printf("\n");
    }

    return 0;
}

