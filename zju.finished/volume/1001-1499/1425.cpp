#include<cstdio>

using namespace std;
enum {
    SIZ = 102,
};
int A[SIZ], anum;
int B[SIZ], bnum;
int tab[SIZ][SIZ];
void readIn(){
    int i,j;
    scanf("%d%d",&anum,&bnum);
    for(i=0; i<anum; i++){
        scanf("%d", &A[i]);
    }
    for(i=0; i<bnum; i++){
        scanf("%d", &B[i]);
    }
    for(i=0;i<anum;i++){
        for(j=0;j<bnum;j++){
            tab[i][j] = -1;
        }
    }
}

int calc(int a, int b){
    if(a < 0 || b < 0)
        return 0;
    if(tab[a][b] >= 0)
        return tab[a][b];
    int ret = 0, t;
    ret = calc(a-1, b-1);
    t   = calc(a-1, b);
    if(ret < t)
        ret = t;
    t = calc(a, b-1);
    if(ret < t)
        ret = t;
    if(A[a] == B[b]){
        return tab[a][b] = ret;
    }
    int i,j;
    for(i=a-1;i>=0;i--){
        if(A[i] == B[b]){
            break;
        }
    }
    if(i < 0)
        return tab[a][b] = ret;
    for(j=b-1;j>=0;j--){
        if(A[a] == B[j]){
            break;
        }
    }
    if(j < 0)
        return tab[a][b] = ret;
    t = 2 + calc(i-1, j-1);
    if(ret < t)
        ret = t;
    return tab[a][b] = ret;
}

int fun(){
    anum--; bnum--;
    return calc(anum, bnum);
}

int main(){
    int tstcase;
    scanf("%d", &tstcase);
    while(tstcase --){
        readIn();
        printf("%d\n", fun());
    }

	return 0;
}

/*
有两行自然数，UP[1..N]，DOWN[1..M]，如果UP=DOWN[J]=K，那么上行的第I个位置的数就可以跟下行的第J个位置的数连一条线，称为一条K匹配，但是同一个位置的数最多只能连一条线。另外，每个K匹配都必须且至多跟一个L匹配相交且K≠L！
现在要求一个最大的匹配数。 数据中所有的数都为小于100的正整数。

样例： 12 11
1 2 3 3 2 4 1 5 1 3 5 10
3 1 2 3 2 4 12 1 5 5 3
则最大匹配数为8

解题思路：

这是一道典型的动态规划试题。 （直觉告诉我的。。。。。。。）

我们先看看样例：



所以最大匹配数是8，我们现在把他们分一下组。



因为题目中有这样一个条件：“每个K匹配都必须且至多跟一个L匹配相交且K≠L！”

这就限制了相交的匹配的位置，则我们可以把一个相交的匹配看成一个整体，如图中用红线框起来一样。

这样题目就转化成了这样：给出两组数，把他们划分成尽可能多的部分，使得每个部分都包含两个相交的匹配。

说到这里大家想到什么？ 很显然，这是一个经典的问题（类似邮局问题而已，只是邮局问题只有一组数据，而这里有两组数据）。则我们可以很轻易的得到这样一个方程：

Opt [ I , J ] = Max ( Opt [ A , B ] + Value ( A + 1 , I , B + 1 , J )  
Opt [ I , J ] 表示UP数组取到第I个，DOWN数组取到第J个所能划分出来的最多的部分，
Value [ A , B , C , D ]表示UP数组从第A个取到第B个，DOWN数组从第C个取到第D个，是否存在两个合法的且相交的匹配，有则 Value = 2 , 没有则Value = 0。

很显然，算法复杂度为O ( N ^ 4 )，N <= 100，比较勉强…估计要运行1s~3s的样子。不尽如人意。

我们需要对这个方程进行优化。

我们现在考虑这样一个问题：当我们求Opt [ I , J ]时，是否能尽可能多的利用以前DP出的信息呢？



看这个例子，我们就可以看到，其实我们需要求出的最关键的状态是
1 ： Opt [ 2 , 2 ]
2 ： Opt [ 5 , 4 ]
3 ： Opt [ 9 , 9 ]
4 ： Opt [ 11 , 11 ]

有了这些状态，我们就可以求出最优解。在求这样的状态中，我们可以知道，UP和DOWN[J]肯定都是属于这两个相交的匹配中的。我们只要求出另外的两个数X、Y，使得：
1 ： 1 <= X <= I  ,  1 <= Y <= J
2 ： UP[X] = DOWN [ J ]  ,  UP = DOWN [ Y]

求这样的数很简单，只要从I开始往前找X，从J开始往前找Y，符合条件便跳出来就可以了， 这时 Opt [ I , J ] = Opt [ X – 1 , Y – 1 ] + 2

那假如Opt [ I , J ]不是关键状态呢？

那这样太好求了：因为它不是关键状态，那么我们就没必要花时间去找相交的匹配。因为只有关键状态才满足UP、DOWN[J]都包含在匹配里，所以这里就会出现3种情况：
1 ： UP [ I ] 包含在匹配中 ， 这个时候 Opt [ I , J ] = Opt [ I , J – 1 ]
1 ： DOWN [ J ] 包含在匹配中 ， 这个时候 Opt [ I , J ] = Opt [ I – 1 , J ]
1 ： UP [ I ]和DOWN [ J ]都不包含在匹配中 ， 这个时候 Opt [ I , J ] = Opt [ I – 1 , J – 1 ]


所以我们总结上面的所有情况，得出另一个优化后的方程：

Opt [ I , J ] = Max ( Opt [ X – 1 , Y – 1 ] + 2 , Opt [ I – 1 , J ] , Opt [ I , J – 1 ] , Opt [ I – 1 , J – 1 ])

因为求X、Y的时候是并列的，时间复杂度仅为2N，所以这个方程的复杂度为O（N^3）

这个时候这个算法已经比较不错了。但我们还可以进行优化：

我们可以在DP之前做一个预处理：
设 LA [ I , J ] 为UP数组中小于I且满足UP[ LA [ I , J ] ] = DOWN [ J ]的最大值。
  LB [ I , J ] 为DOWN数组中小于J且满足DOWN [ LB [ I , J ] ] = UP [ I ] 的最大值。

这样DP的时候就可以直接套用了。即 X = LA [ I , J ] ; Y = LB [ I , J ] 。

这样，算法复杂度降到了O（N^2），所有测试点可以在0.0s内全部通过。

通过这个题我们可以看出，不仅写出方程是很重要的，优化方程也是解决动态规划类问题的一个非常重要的方面。 
*/
