#include<cstdio>
#include<cstring>

//求树中最长的点之间距离
//  先随机取一点，获取一与它距离最长的点，再对新点求距离最长的点
//
using namespace std;
enum {
    SIZ = 600008,
};
struct Node {
    int pos;
    int ptr[4];
};
int num;
Node tree[SIZ];
unsigned dis[SIZ];
int que[SIZ];
int head, tail;
char buf[1004];
int pred[1004];

inline void add(int a, int b){
    tree[a].ptr[tree[a].pos++] = b;
    tree[b].ptr[tree[b].pos++] = a;
}

void readIn(){
    int i,j;
    int R,C;
    char ch;
    num = 0;
    scanf("%d%d ", &C, &R);
    for(i=0; i<C;i++){
        pred[i] = -1;
    }
    for(i=0;i<R;i++){
        scanf("%s", buf);
        for(j=0;j<C;j++){
            if(buf[j]=='#'){
                pred[j] = -1;
                continue;
            } 
            tree[num].pos = 0;
            if(pred[j]!=-1){
                add(pred[j], num);
            }
            if(pred[j-1]!=-1){
                add(pred[j-1],num);
            }
            pred[j] = num;
            num ++;
        }
    }
}

void bfs(int s){
    int t,i;
    dis[s] = 0;
    head = tail = 0;
    que[tail++] = s;
    while(head < tail){
        s = que[head++];
        for(i=0; i< tree[s].pos;i++){
            t = tree[s].ptr[i];
            if(dis[t] > dis[s] + 1){
                dis[t] = dis[s] + 1;
                que[tail++] = t;
            }
        }
    }
}

void fun(){
    int i, val, ptr;
    memset(dis, -1, sizeof(unsigned) * num);
    bfs(0);
    val = 0, ptr = 0;
    for(i=0;i<num;i++){
        if(dis[i] > val){
            val = dis[i];
            ptr = i;
        }
        dis[i] = -1;
    }
    bfs(ptr);
    val = 0;
    for(i=0;i<num;i++){
        if(dis[i] > val){
            val = dis[i];
        }
    }

    printf("Maximum rope length is %d.\n", val);
}

int main(){
    int tstcase;

    scanf("%d", &tstcase);
    while(tstcase --){
        readIn();
        fun();
    }

	return 0;
}
