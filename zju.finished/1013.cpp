#include<iostream>
#include<cstring>
using namespace std;

const int SIZ = 504;
const int LEN = 104;
int num;
int tab[2][SIZ][SIZ];
int (*cur)[SIZ];
int (*nex)[SIZ];
int (*tmp)[SIZ];
int wei[LEN], siz[LEN];
int w[3], s[3], d[3];
int cnt[4];

int getVal(int x, int y, int z){
    int r = x*d[0] + y*d[1] + z*d[2];
    int t = min(x/cnt[0], y/cnt[1]);
    t = min(t, z/cnt[2]);
    t = t * cnt[3] + (x-t*cnt[0])*d[0] + (y-t*cnt[1])*d[1] + (z-t*cnt[2])*d[2];
    r = max(r, t);
    return r;
}

void fun(){
    memset(tab, -1, sizeof(tab));
    tab[0][0][0] = 0;
    cur = tab[0]; nex = tab[1];
    int x, y, a, b;
    for (int i=1; i<=num; ++i){
        memset(nex, -1, sizeof(tab[0]));
        int ma = min(wei[i]/w[0], siz[i]/s[0]);
        for (x=0; x<=500; ++x){
            for (y=0; y<=500; ++y){
                if (cur[x][y] < 0) continue;
                for (int a=0; a<=ma && a+x<=500; ++a){
                    int mb = min((wei[i]-w[0]*a)/w[1], (siz[i]-s[0]*a)/s[1]);
                    for (int b=0; b<=mb&&b+y<=500; ++b){
                        int v = min((wei[i]-w[0]*a-w[1]*b)/w[2], (siz[i]-s[0]*a-s[1]*b)/s[2]);
                        v += cur[x][y];
                        if (nex[x+a][y+b] < v){
                            nex[x+a][y+b] = v;
                        }
                    }
                }
            }
        }
        tmp = cur, cur = nex, nex = tmp; 
    }
    a = 0;
    for (x=0; x<=500; ++x){
        for (y=0; y<=500; ++y){
            if (cur[x][y] < 0) continue;
            b = getVal(x, y, cur[x][y]);
            a = max(a, b);
        }
    }
    printf("%d\n", a);
}

int readIn(){
    scanf("%d", &num);
    if(num == 0) return 0;
    for(int i=0; i<3; i++){
        scanf("%d%d%d", &w[i], &s[i], &d[i]);
    }
    scanf("%d%d%d%d",&cnt[0], &cnt[1], &cnt[2], &cnt[3]);
    for (int i=1; i<=num; ++i){
        scanf("%d%d", &wei[i], &siz[i]);
    }
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

