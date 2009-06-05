#include<iostream>

using namespace std;
enum {
    SIZ = 516,
    White = 0,
    Black = 1,
    Mixed = 2,
};
const char *ans="WBQ";
char input[SIZ];
char mat[SIZ][SIZ];
int N;
struct Node {
    int val;
    Node *ptr[4];
    Node(): val(0){
        for(int i=0;i<4;i++){
            ptr[i] = 0;
        }
    }
    bool operator != (const Node &rhs ) const {
        return (val == Mixed) || (val != rhs.val);
    }
};
Node * head;

int calc(char *s){
    int t;
    sscanf(s, "%x", &t);
    return t;
}
void conv(char *s, char *in){
    int a,b;
    char *p;
    
    for(int i=0;i<N/8;i++){
        if(i == 0){
            p = strtok(in,",");
        } else {
            p = strtok(NULL,",");
        }
        a = calc(p);        
        b = i * 8;
        for(int j=0;j<8;j++){
            s[b+j] = a%2;
            a /= 2;
        }
    }
}

void readIn(){
    scanf("%s%s%d ", input, input, &N);
    scanf("%s%s%d ", input, input, &N);
    fgets(input, SIZ, stdin);
    for(int i=0;i<N;i++){
        fgets(input, SIZ, stdin);
        conv(mat[i], input);
    }
    fgets(input, SIZ, stdin);    
}
Node * fun(int r, int c, int s){ 
    Node *t = new Node();
    if(s == 1){
        t->val = mat[r][c];
        return t;
    }
    s /= 2;
    t->ptr[0] = fun(r, c, s);
    t->ptr[1] = fun(r, c+s, s);
    t->ptr[2] = fun(r+s, c, s);
    t->ptr[3] = fun(r+s, c+s, s);
    bool flag = true;
    for(int i=1;i<4;i++){
        if( *t->ptr[0] != *t->ptr[i]){
            flag = false; break;
        }
    }
    if(flag ){
        t->val = t->ptr[0]->val;
        for(int i=0;i<4;i++){
            delete t->ptr[i];
            t->ptr[i] = 0;
        }
    } else {
        t->val = Mixed;
    }
    return t;   
}
void output(Node * p){
    printf("%c", ans[p->val]);
    if(p->val < Mixed)
        return;
    for(int i=0;i<4;i++){
        output(p->ptr[i]);
    }
}

int main(){

    readIn();
    head = fun(0,0,N);
    printf("%d\n", N);
    output(head);
    printf("\n");
    
    return 0;
}