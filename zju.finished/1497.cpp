#include<iostream>
using namespace std;
enum {
    SIZ = 32,
};
struct Node {
    int dir;
    int cnt;
};
int num, clean;
Node tree[SIZ];
int pred, cur;

int readIn(){
    scanf("%d",&num);
    if(num == 0) return num;
    pred = 0;
    scanf("%d", &cur);
    cur --;
    char ch;
    for(int i=0; i<num ;i++){
        tree[i].cnt = 0;
        scanf(" %c", &ch);
        if(ch == 'L'){
            tree[i].dir = -1;
        } else {
            tree[i].dir = 1;
        }
    }
    return num;
}
inline void adjust(int &t){
    if(t < 0){
        t += num;
    }else if(t >= num){
        t -= num;
    }
}
void fun(){
    int t;
    int toss = 1;
    clean = num -1;
    tree[cur].cnt = 1;
    while(clean){
        t = pred + tree[cur].dir;
        adjust(t);
        if(t == cur){
            t += tree[cur].dir;
            adjust(t);
        }
        tree[cur].dir = - tree[cur].dir;
        pred = cur; cur = t;
        toss++;
        if(tree[cur].cnt == 0){
            tree[cur].cnt = 1;
            --clean;
        }
    }
    cur++;
    printf("Classmate %d got the ball last after %d tosses.\n", cur, toss);
}

int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

