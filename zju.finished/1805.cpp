#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
//另一个四叉树问题，还是希望没内存泄露...
// 正常的四叉树只考虑是否有全色的情况
// 压缩的四叉树要把所有的非叶子树缩减，避免重复出现，
// 因此要保存出现过的非叶子树，但怎么计算压缩后的结点数呢？ 
// hehe, see the code below.
enum {
    SIZ = 130,    
    White = 0,
    Black = 1,
    Mixed = 2,
    Quad = 4,
};
int N;
int row,col;
int mat[SIZ][SIZ];
struct Node {
    int cnt;//压缩后的结点数
    int sum;//正常的四叉树的结点数
    int val;// 全色(0,1)，还是杂色(mixed)？
    Node ():cnt(1),sum(1)  {
        for(int i=0;i<Quad;i++){
            ptr[i] = 0;
        }
    }
    Node *ptr[Quad];    
    bool operator != (const Node & rhs) const {
        // 判断四个孩子是否为全色
        if(val == Mixed || val != rhs.val){
            return true;
        }
        return false;
    }
    bool operator == (const Node & rhs) const {
        //判断两棵子树是不是相似
        if(this == &rhs)
            return true;
        if(val != rhs.val)
            return false;
        for(int i=0;i<Quad;i++){
            if(!(*ptr[i] == *rhs.ptr[i]) ){
                return false;
            }
        }
        return true;
    }
};
vector<Node *> tab;//保存所有非叶子树
Node *head;

int readIn(){
    scanf("%d%d",&row, &col);
    if(row + col ==0)
        return 0;
    N = 1;
    while(N < row || N < col){
        N *= 2;//填充大小
    }
    char ch;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i < row && j < col){
                scanf(" %c", &ch);
                mat[i][j] = ch - '0';
            } else {
                mat[i][j] = 0;
            }
        }
    }    
    return 1;
}
Node *check_dup(Node *p){//判断有没有存在的相似子树
    for(int i=0;i<tab.size();i++){
        if( *tab[i] == *p){
            delete p;
            return tab[i];
        }
    }
    tab.push_back(p);
    return p;
}

Node *fun(int r, int c, int size){
    Node *t = new Node();
    if(size == 1){
        t->val = mat[r][c];
        return t;
    }
    size /= 2;
    t->ptr[0] = fun(r,c,size);
    t->ptr[1] = fun(r,c+size,size);
    t->ptr[2] = fun(r+size,c,size);
    t->ptr[3] = fun(r+size,c+size,size);
    bool flag = true;
    for(int i=1;i<Quad;i++){
        if(*t->ptr[0] != *t->ptr[i]){
            flag = false; break;
        }
    }
    if(flag ){
        t->val = t->ptr[0]->val;
        for(int i=0;i<Quad;i++){
            delete(t->ptr[i]);
            t->ptr[i] = 0;
        }
    } else {
        t->val = Mixed;
        for(int i=0;i<Quad;i++){
            t->sum += t->ptr[i]->sum;
            t->cnt += t->ptr[i]->cnt; 
            // 因为相似子树共享结点，
            // 第一次取压缩数目后置零，防止重复加到结果
            t->ptr[i]->cnt = 0;
        }
        t = check_dup(t);
    }
    return t;    
}

void FreeAll(){
    for(int j=0;j<tab.size();j++){
        delete tab[j];
    }
    tab.clear();
}

int main(){
    
    while(readIn() > 0){
        head = fun(0,0,N);
        printf("%d %d\n", head->sum, head->cnt);
        FreeAll();
    }
    
    return 0;
}

