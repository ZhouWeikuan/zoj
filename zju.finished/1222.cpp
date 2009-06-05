#include<iostream>
using namespace std;
enum {
    SIZ = 120,
};
template<int N> 
struct BigNum {
	int d[N];
	int len;
	void conv(const char *);
    void operator /=(int);
    int toInt();
    int operator %(int);
};
template<int N>
int BigNum<N>::toInt(){
    int t = 0;
    for(int i=len-1;i>=0;i--){
        t *= 10;
        t += d[i];
    }
    return t;
}
template<int N>
void BigNum<N>::conv(const char *s){
	len = strlen(s);
	int t = len;
	while(t){
		d[len -t] = s[t-1] -'0';
		t --;
	}
}
template<int N>
int BigNum<N>::operator %(int dm){
    int carry = 0;
    for(int i=len-1;i>=0;i--){
        carry *= 10;
        carry +=d[i];
        carry %= dm;
    }
    return carry;
}
template<int N>
void BigNum<N>::operator /=(int dm){
	int carry = 0;
	int i;
	for(i=len-1;i>=0;i--){
		carry *= 10;
		carry += d[i];
		d[i] = carry / dm;
		carry = carry % dm;
	}
	while(len > 0 && d[len-1] ==0){
		len--;
	}
}
int tab[10] = {1, 1, 2, 6, 4, 4, 4, 8, 4, 6};
int div2(int t){
    switch(t){
    case 2:
        t = 6;        break;
    case 6:
        t = 8;        break;
    default:
        t /= 2;       break;
    }
    return t;
}
int process(int t){
    int v;
    if(t < 10){
        v = tab[t];
        t /= 5;
        while(t--){
            v = div2(v);
        }
        return v;
    }
    v = tab[t%10];
    v *= 6;
    v %= 10;
    t /= 5;
    int cnt = t % 4;
    while(cnt--){
        v = div2(v);
    }
    v *= process(t);
    v %= 10;
    return v;
}
int process(BigNum<SIZ>& rhs){
    if(rhs.len < 7){
        return process(rhs.toInt());
    }
    int v = tab[rhs.d[0]];
    v *= 6;
    v %= 10;
    rhs /= 5;
    int cnt = rhs % 4;
    while(cnt--){
        v = div2(v);
    }
    v *= process(rhs);
    v %= 10;
    return v;
}
int fun(BigNum<SIZ> &rhs){
    int ret = 1, t, v;
    while(rhs.len > 7){
        ret *= tab[rhs.d[0]];
        ret *= 6;
        ret %= 10;
        rhs /= 5;
        v = rhs % 4;
        while(v--){
            ret = div2(ret);
        }
    }
    t = rhs.toInt();
    while(t >= 10){
        ret *= tab[t%10];
        ret *= 6;
        ret %= 10;
        t /= 5;
        v = t % 4;
        while(v--){
            ret = div2(ret);
        }
    }
    ret *= tab[t];
    v = t/5;
    ret %= 10;
    while(v--){
        ret = div2(ret);
    }
    return ret;
}
char buf[SIZ];
int main(){
    BigNum<SIZ> n;
    int v;
    while( scanf("%s", buf) > 0){
        n.conv(buf);
        //printf("%d\n", process(n));
        printf("%d\n", fun(n));
    }

    return 0;
}
/**************************************************
这道题要求N!的最后一个非0数字是多少，如果用一般作法，先统计2和5的个数，然
后补乘2，得到的将是TLE。所以还需要再做简化：

为了把0去掉，我们把所有的因数2和5都提出来，放到最后再处理。N!中的N个相乘的
数可以分成两堆：奇数和偶数。偶数相乘可以写成(2^M)*(M!)，M=N DIV 2。M!可以
递归处理，因此现在只需讨论奇数相乘。考虑1*3*5*7*9*11*13*15*17* ... *N(如果
N为偶数则是N-1)，这里面是5的倍数的有5，15，25，35，... ，可以其中的5提出来
，变成(5^P)*(1*3*5*7*9* ... )，后面括号中共P项，P=(N DIV 5+1) DIV 2，而后
面的括号又可以继续提5出来，递归处理。现在剩下的数是1 * 3 * 7 * 9 * 11 * 13
* 17 * 19 * ... 。这些数我们只需要他们的个位数，因为(1 * 3 * 9 * 11 * 13
* ... ) MOD 10 = (1 * 3 * 7 * 9 * 1 * 3 * ... ) MOD 10。我们列出余数表，
1 3 1 9 9 7 9 1 1 3 1 9 9 7 9 ……。我们发现每八项MOD 10的结果是一个循环。
算出奇数的结果后，我们再回头看统计了多少个2和5需要乘入。把2和5配对完都是N
!后面的0，看剩下的2有几个。如果有剩下的2，考虑2^N的个位数又是2 4 8 6 2 4
8 6 ……每四项一个循环，找出这个个位数后，和前面的结果相乘，再取个位数就是
答案。由于我们完全把2和5的因素另外处理，所以在所有的乘法中，都只需要计算个位数乘法，
并且只保留个位数的结果。

但让我很惊异的是：为什么我提交总是WA？后来我才知道，原因是这道题的N相当大
！达到了10^100！要用大数来处理！GPC四项编译开关全关的，自然查不出来！而且
上面这个算法换成大数后会很麻烦。还有什么别的好方法吗?

答案是有的。我们设F(N)表示N!的尾数。

先考虑简单的。考虑某一个N!(N < 10)，我们先将所有5的倍数提出来，用1代替原来
5的倍数的位置。由于5的倍数全被提走了，所以这样就不会出现尾数0了。我们先把
0..9的阶乘的尾数列出来（注意，5的倍数的位置上是1），可以得到table[0..9] =
(1, 1, 2, 6, 4, 4, 4, 8, 4, 6)。对于N < 5，直接输出table[N]即可；对于N >
= 5，由于提出了一个5，因此需要一个2与之配成10，即将尾数除以2。注意到除了0
!和1!，阶乘的最后一个非零数字必为偶数，所以有一个很特别的除法规律：2 / 2
= 6，4 / 2 = 2，6 / 2 = 8，8 / 2 =　4。比较特殊的就是2 / 2 = 12 / 2 = 6，
6 / 2 = 16 / 2 = 8。这样我们就可以得到如下式子：
代码:

         table[N]
F(N) = ------------ (0 <= N < 10)
         2^([N/5])
再考虑复杂的。考虑某一个N!(N >= 10)，我们先将所有5的倍数提出来，用1代替原
来5的倍数的位置。由于5的倍数全被提走了，所以这样就不会出现尾数0了。我们观
察一下剩下的数的乘积的尾数，通过table表，我们发现这10个数的乘积的尾数是6，
6 * 6的尾数还是6，因此我们将剩下的数每10个分成一组，则剩下的数的乘积的尾数
只与最后一组的情况有关，即与N的最后一位数字有关。由于我们把5的倍数提出来了
，N!中一次可以提出[N/5]个5的倍数，有多少个5，就需要有多少个2与之配成10，所
以有多少个5，最后就要除以多少个2。注意到除2的结果变化是4个一循环，因此如果
有A个5，只需要除(A MOD 4)次2就可以了。A MOD 4只与A的最后两位数有关，很好求
算。剩下的5的倍数，由于5已经全部处理掉了，就变成[N/5]!。于是，我们可以得到
一个递归关系：
代码:

          F([N/5]) * table[N的尾数] * 6
F(N) = ----------------------------------- (N > 10)
                2^([N/5] MOD 4)
这样我们就得到了一个O(log5(N))的算法，整除5可以用高精度加法做，乘2再除10即
可。整个算法相当巧妙，写起来也比较轻松。
*******************************************************************/
