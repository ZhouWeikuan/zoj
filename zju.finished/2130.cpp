#include<iostream>
using namespace std;
// 一开始以为不能匹配过的数据就不能再匹配，结果让我失望了:)
enum {
    SIZ = 64,
    None = 0,
    FlagO = 1,
    FlagX = 2,
    FlagM = 3,
};
struct Node {
    int x,y;
    int f;
};
int tab[SIZ][SIZ], H,W;
int top,h,w;
Node tree[64*64];
int readIn(){
    if(scanf("%d%d%d%d",&H,&W,&h,&w)== EOF)
        return 0;
    int i,j; char ch;
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            scanf(" %c",&ch);
            if(ch == 'O'){
                tab[i][j] = FlagO;
            } else if(ch=='X'){
                tab[i][j] = FlagX;
            } else {
                tab[i][j] = None;
            }
        }
    }
    top = 0;
    int t;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            scanf(" %c",&ch);
            if(ch == '.'){
                continue;
            } else if(ch=='X'){
                t = FlagX;
            } else {
                t = FlagO;
            }
            tree[top].x = i;
            tree[top].y = j;
            tree[top].f = t;
            top++;
        }
    }
    return 1;
}
int check(int a, int b){
    for(int i=0;i<top;i++){
        if(tab[a+tree[i].x][b+tree[i].y] != tree[i].f){
            return 0;
        }
    }
    return 1;
}
int fun(){
    int i,j;
    int ans = 0;
    for(i=0;i+h<= H;i++){
        for(j=0;j+w<=W;j++){
            if(check(i,j)){
                ans ++;
            }
        }
    }
    return ans;
}
int main(){
    while(readIn() > 0){
        printf("%d\n",fun());
    }
    return 0;
}

