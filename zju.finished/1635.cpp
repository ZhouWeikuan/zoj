#include<iostream>
#include<queue>
//  成功的，等提交
using namespace std;
enum {
    SIZ = 12,
};
const char *seven="|       ";
const char *eight="        ";
struct Node {
    char name[SIZ+4];
    int size;
    int parent;
    int child;
    int ptr[SIZ];
};
Node tree[SIZ * SIZ];
char buf[SIZ];
int num;
int readIn(){
    int size;
    if(scanf("%s%d",buf,&size)< 0)
        return 0;
    queue<int> q;
    num = 0;
    tree[num].parent = -1;
    strcpy(tree[num].name, buf);
    tree[num].size = size;
    tree[num].child = 0;
    if(buf[0] == '*')
        q.push(num);
    num++;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        scanf(" %c", &buf[0]); // (
        scanf(" %c",&buf[0] );
        while(buf[0] !=')'){
            scanf("%s%d",&buf[1],&size);
            strcpy(tree[num].name, buf);
            tree[num].size = size;
            if(buf[0] == '*')
                q.push(num);
            tree[cur].ptr[tree[cur].child++] = num;
            tree[num].parent = cur;
            tree[num].child = 0;
            num++;
            scanf(" %c",&buf[0]);
        }
    }
    return 1;
}
int calc(int d){
    int s = 0;
    for(int i=0;i<tree[d].child;i++){
        s+= calc(tree[d].ptr[i]);
    }
    tree[d].size += s;
    return tree[d].size;
}
struct Seq {
    int par;
    int ind; 
};
Seq save[SIZ];
int top;

void output(){
    int i;
    int lim;
    for(i=0;i<top-1;i++){
        if(i==0){
            printf("%s", eight);
        } else {
            lim = tree[save[i].par].child;
            if(save[i].ind == lim - 1){
                printf("%s",eight);
            } else {
                printf("%s",seven);
            }
        }
    }
    int cur = save[i].par;
    if(cur == -1){
        cur = 0;
    } else {
        cur = tree[cur].ptr[save[i].ind];
    }
    printf("|_%s[%d]\n",tree[cur].name, tree[cur].size);
}
void iter(){
    int par = save[top-1].par;
    int cur ;
    if(par == -1){
        cur = 0;
    } else {
        cur = tree[par].ptr[save[top-1].ind];
    }
    if(tree[cur].child != 0){
        save[top].par = cur;
        save[top].ind = 0;
        top++;
        return;
    }
    while((top>1&&tree[par].child-1==save[top-1].ind)){
        --top;
        par = save[top-1].par;
        cur = tree[par].ptr[save[top-1].ind];
    }
    if(top> 1){
        save[top-1].ind ++;
    } else {
        top = 0;
    }
}
int fun(){
    calc(0);
    save[0].par = -1;
    save[0].ind = 0;
    top = 1;
    while(top){
        output();
        iter();
    }
    return 0;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}
