#include<iostream>
#include<queue>
#include<cstring>

// 树型问题，希望没有内存泄露:)
using namespace std;
enum {
    SIZ = 516,
};
struct Node {
    char val[4];    // 三种值："00","01","1"
    Node *ptr[4];
    bool operator == (const Node &rhs) const {// 相等情况
        if( strcmp(val, "1")==0 || strcmp(val, rhs.val)!=0){
            return false;
        }        
        return true;
    }
};

Node * head;
char mat[SIZ][SIZ];
int N, pos;
char bin[SIZ * SIZ];

// 从mat[r][c]开始，分别向下和向右扩展size个元素所生成的四叉树
Node * fun(int r,int c, int size){
    Node *t = new Node;
    if(size== 1){// "00" 或"01"
        t->val[0] = '0';
        t->val[1] = mat[r][c] + '0';
        t->val[2] = 0;    
        return t;
    }
    size /= 2;
    t->ptr[0] = fun(r,c,size);
    t->ptr[1] = fun(r,c+size, size);
    t->ptr[2] = fun(r+size,c,size);
    t->ptr[3] = fun(r+size,c+size,size);
    bool flag = true;
    for(int i=1;i<4;i++){ // 判断是否为全色，全1或全0
        if( *t->ptr[0] == *t->ptr[i]){
            ;
        } else {
            flag = false; break;
        }
    }
    if(flag ){
        strcpy(t->val, t->ptr[0]->val);
        for(int i=0;i<4;i++){
            delete t->ptr[i];
            t->ptr[i] = 0;
        }
    } else {
        strcpy(t->val, "1");
    }
    return t;
}
void out(char *s, int len){
    int t = 0;
    for(int i=0;i<len;i++){
        t *= 2;
        t += s[i] -'0';
    }
    printf("%X", t);
}
void output(){
    pos = 0;
    queue<Node *> q;
    q.push(head);
    int t;
    Node *p;
    // 生成01串
    while(!q.empty()){
        p = q.front(); q.pop();
        t = strlen(p->val);
        strcpy(bin + pos, p->val);
        pos += t;
        if(p->val[0] == '0'){
            delete p;
            continue;
        }
        for(int i=0;i<4;i++){
            q.push(p->ptr[i]);
        }
        delete p;
    }
    bin[pos] = 0;
    // 输出生成的串
    t = pos % 4;
    if(t ){
        out(bin, t);
    }
    while(t < pos){
        out(bin + t, 4);
        t += 4;
    }
    printf("\n");
}

void readIn(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &mat[i][j]);
        }
    }
}
int main(){
    int tstcase;
    scanf("%d", &tstcase);
    while(tstcase --){
        readIn();
        head = fun(0,0,N);
        output();
    }
    
    return 0;
}
