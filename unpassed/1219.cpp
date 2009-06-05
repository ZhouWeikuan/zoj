#include<iostream>
using namespace std;
// 题意不明，什么叫satisfy at least one question?
// +A-B;
// -A+B;
// 那么"AB", " "都可以？
enum {
    SIZ = 16,
};
struct Require{
    bool use;
    int mark[SIZ];
};
int num;
Require req[SIZ];
int all[SIZ];
char buf[80];
char sav[SIZ];
int top;

void test(int v){
    int i;
    bool bAdd = true;
    for(i=0; i<num; i++){
        if(req[i].mark[v] == -1){
            bAdd = false;
        }
    }
    for(i=0; i<num; i++){
        if(bAdd && req[i].mark[v] == 1){
            req[i].use = true;
        } else if(!bAdd && req[i].mark[v]==-1){
            req[i].use = true;
        }
    }
    if(bAdd){
        sav[top++] = 'A'+v;
    }
}
void fun(){
    int i;
    top = 0;
    for(i=0; i<SIZ; i++){
        if(all[i])
            test(i);
    }
    for(i=0; i<num; i++){
        if(req[i].use == false){
            top = -1;
        }
    }
    if(top < 0){
        printf("No pizza can satisfy these requests.\n");
    } else {
        sav[top] = 0;
        printf("Toppings: %s\n", sav);
    }
}
void parse(char *s, int p){
    int v, t;
    for(int i=0; buf[i]!=';'; i+=2){
        v = (buf[i]=='+'?1:-1);
        t = buf[i+1]-'A';
        all[t] = 1;
        req[p].mark[t] = v;
    }
}
int readIn(){
    if(scanf("%s", buf)<0)return 0;
    memset(all, 0, sizeof(all));
    num = 0;
    while(buf[0]!='.'){
        req[num].use = 0;
        memset(req[num].mark, 0, sizeof(req[0].mark));
        parse(buf, num);
        num++;
        scanf("%s", buf);
    }
    return 1;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

