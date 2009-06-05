#include<iostream>
using namespace std;
// 求3*3窗口的下一窗口,这样可以减少时间
enum {
    SIZ = 1008,
};
struct Rect {
    int idx, ptr;
};
struct Node{
    int s, v;
};
int wid, pos, num;
Node tree[SIZ];
int pre, cnt, cur;
Rect win[9];

void fun(){
    pre = -1, cnt = 0;
}

int readIn(){
    scanf("%d", &wid);
    if(wid == 0) return 0;
    int a, b;
    num = pos = 0;
    scanf("%d%d",&a,&b);
    while(a + b){
        scanf("%d%d",&a,&b);
        tree[num].s = pos;
        tree[num].v = b;
        num++;
        pos += a;
    }
    tree[num].s = pos;
    return wid;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

