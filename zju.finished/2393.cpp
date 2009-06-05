#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 65540,
};
struct Node{
    char dig;
    int  rem;
    int  pre;
    int  num;
};
char rem[SIZ];
Node tree[SIZ];
unsigned pos;
char save[SIZ];
int  down;

void pro(int s){
    int v, len=1;
    v = s % down;
    while(v!=0 && rem[v] == 0){
        rem[v] = 1;
        v *= 10;
        v = (v + s)%down;
        len++;
    }
    if(v == 0 && (pos == -1||pos>len)){
        for(pos=0; pos<len; pos++){
            save[pos] = '0' + s;
        }
    }
}
void pro(int s, int a, int b){
    int v, end=1, i;
    tree[0].dig = s;
    tree[0].pre = 0;
    tree[0].num = 1;
    tree[0].rem = s;
    rem[s] = 1;
    for(i=0; i<end; i++){
        v = (tree[i].rem*10 + a)%down;
        if(rem[v] == 0){
            rem[v] = 1;
            tree[end].dig = a;
            tree[end].pre = i;
            tree[end].num = tree[i].num+1;
            tree[end].rem = v;
            end++;
        }
        if(v == 0) break;
        v = (tree[i].rem*10 + b)%down;
        if(rem[v] == 0){
            rem[v] = 1;
            tree[end].dig = b;
            tree[end].pre = i;
            tree[end].num = tree[i].num+1;
            tree[end].rem = v;
            end++;
        }
        if(v == 0) break;
    }
    if(v != 0) return;
    end--;
    if(tree[end].num >= pos) return;
    pos = 0;
    while(tree[end].pre != end){
        save[pos++] = '0' + tree[end].dig; 
        end = tree[end].pre;
    }
    save[pos++] = '0' + s;
}

void fun(){
    int i,j;
    for(i=1; i<10; i++){
        memset(rem, 0, sizeof(rem[0])*down);
        pro(i);
    }
    if(pos == -1){
        for(i=1; i<10; i++){
            for(j=0; j<i; j++){
                memset(rem, 0, sizeof(rem[0])*down);
                pro(i, j, i);
            }
            for(j=i+1; j<10; j++){
                memset(rem, 0, sizeof(rem[0])*down);
                pro(i, i, j);
            }
        }
    }
    reverse(save, save+pos);
    save[pos] = 0;
}

int main(){
    scanf("%d", &down);
    while(down > 0){
        pos = -1;
        fun();
        printf("%s\n", save);
        scanf("%d", &down);
    }
    return 0;
}

