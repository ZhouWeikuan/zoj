#include<iostream>
using namespace std;
const int SIZ = 504;
struct Equip{
    int w,v, x;
};
typedef int (*ptr2d)[SIZ];
int num;
int tab[2][SIZ][SIZ];
ptr2d pre, cur, tmp;
Equip e[3];
int cnt[4];
int rx, ry;

void update(int a, int b, int v){
    int i,j;
    for(i=0; i<=rx && a + i <SIZ; i++){
        for(j=0; j<=ry && b+j<SIZ; j++){
            if(pre[i][j] < 0) continue;
            if(cur[a+i][b+j] < pre[i][j] + v){
                cur[a+i][b+j] = pre[i][j] + v;
            }
        }
    }
    rx = min(max(rx, a+i), SIZ);
    ry = min(max(ry, b+j), SIZ);
}
int getVal(int a, int b, int c){
    int t = SIZ;
    if(cnt[0]!=0) t = min(t, a/cnt[0]);
    if(cnt[1]!=0) t = min(t, b/cnt[1]);
    if(cnt[2]!=0) t = min(t, c/cnt[2]);
    int ret = t*cnt[0]*e[0].x + t*cnt[1]*e[1].x+t*cnt[2]*e[2].x;
    if(ret < t * cnt[3]) ret = t * cnt[3];
    ret += (a - t*cnt[0])*e[0].x;
    ret += (b - t*cnt[1])*e[1].x;
    ret += (c - t*cnt[2])*e[2].x;
    return ret;
}
void fun(){
    pre = tab[0], cur = tab[1];
    memset(pre, -1, sizeof(tab[0]));
    pre[0][0] = 0;
    int a, b;
    int w, v;
    rx = ry = 0;
    for(int che=0; che<num; che++){
        memset(cur, -1, sizeof(tab[1]));
        scanf("%d%d",&w,&v);
        a = min(w/e[0].w, v/e[0].v);
        for(; a>=0; a--){
            b = min((w-e[0].w*a)/e[1].w, (v-e[0].v*a)/e[1].v);
            for(;b>=0; b--){
                int t=min((w-e[0].w*a-e[1].w*b)/e[2].w,
                        (v-e[0].v*a-e[1].v*b)/e[2].v);
                if(t >= 0)
                    update(a, b, t);
            }
        }
        tmp = pre; pre= cur; cur = tmp;
    }
    v = -1;
    for(a=0; a<=rx; a++){
        for(b=0; b<=ry; b++){
            if(pre[a][b] < 0) continue;
            w = getVal(a, b, pre[a][b]);
            if(v < w){
                v = w;
            }
        }
    }
    printf("%d\n", v);
}

int readIn(){
    scanf("%d", &num);
    if(num == 0) return 0;
    for(int i=0; i<3; i++){
        scanf("%d%d%d", &e[i].w, &e[i].v, &e[i].x);
    }
    scanf("%d%d%d%d",&cnt[0], &cnt[1], &cnt[2], &cnt[3]);
    return num;
}
int main(){
    int tst = 0;
    while(readIn() > 0){
        if(tst) printf("\n");
        printf("Case %d: ", ++tst);
        fun();
    }
    return 0;
}
/*
编号所有的车辆是１，２，３，４。。。，n
F(i,x,y) 表示的是前面1...i辆车中装载x件１装备，y件二装备之后
最多还能够装多少的３装备
我们需要求出F(n,*,*)就是i = n的所有的F值

设装备的重量和尺寸分别是这样的
weight[3],size[3],防御defence[3]
而汽车的容量分别是ss[1..n],ww[1..n]

规划过程:
1.i = 1的时候，F(1,x,y)
如果x * weight[0] + y * weight[1] > ww[1] 显然F(1,x,y) 不可行，我们取-1标记不可行
同理 x * size[0] + y * size[1] > ss[1]也是一样
否则　F(1,x,y)可以由除去x,y之后的剩余重量和剩余尺寸算出来

2.设 1)
显然F(i,x,y)可以这样算出来，设其中有h件１装备，l件２装备在i车中，则F(i,x,y) =
F(i - 1,x - h,y - l) + 第i车中剩余的空间能够装下的最多的第３种装备的数量，
取F为这些所有的h,l的最大值，当然如果这样的h,l都找不到，则标记为函数值为-1
即不可行

最后得到F(n,x,y)


使用这个结果即可得到题目的解答
所有车辆中装x,y件１装备，２装备的时候还能够装下多少的３装备为F(n,x,y)
这些装备可以组成的组合装备套数可以马上得到，能够达到的最大防御里也可得到
遍历所有可能的x,y即可得到题目所求答案
*/
