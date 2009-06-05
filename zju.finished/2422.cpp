#include<iostream>
using namespace std;
enum {
    SIZ = 50004,
};
struct Node{
    int x, y;
};
int num;
Node tree[SIZ];
int l[SIZ];
int r[SIZ];
int s[SIZ], top;
int val;

// [l, r]
void fun(){
    int i;
    top = 0; s[top] = 0;
    for(i=1;i<=num;i++){
        while(tree[s[top]].y >= tree[i].y){
            top --;
        }
        l[i] = s[top] + 1;
        s[++top] = i;
    }

    top = 0; s[top] = num + 1;
    for(i=num;i>=1;i--){
        while(tree[s[top]].y >= tree[i].y){
            top --;
        }
        r[i] = s[top] - 1;
        s[++top] = i;
    }
    int t;
    val = 0;
    for(i=1;i<=num;i++){
        t = tree[r[i]].x - tree[l[i]-1].x; 
        t *= tree[i].y;
        if(t > val)
            val = t;
    }
}

int readIn(){
    scanf("%d", &num);
    tree[0].y = tree[num+1].y = -1;
    tree[0].x = tree[num+1].x = 0;
    for(int i=1; i<=num; i++){
        scanf("%d%d",&tree[i].x, &tree[i].y);
        tree[i].x += tree[i-1].x;
    }
    return num;
}
int main(){

    while(readIn() > 0){
        fun();
        printf("%d\n", val);
    }
    return 0;
}

