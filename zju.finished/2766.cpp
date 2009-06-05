/****************************************
 * Zju Online Judge 2766 -- Local Maxima *
 *            Algorithm Math             *
 *            Complexity O(1)            *
 *           Author LoveShsean           *
 ****************************************/
// 调和函数计算公式，本代码从网上抄的...
#include <stdio.h>
#include <math.h>

#define gamma 0.57721566490153286

double  Ans , t ;
int N;

int main()
{
    int i ;
    while (1 == scanf("%d" , &N))
    {
        if (N <= 36)
            for (Ans = 0.0 , i = 1 ; i <= N ; i ++)
                Ans += 1 / double(i) ;
        else
            t = N , Ans = log(t) + gamma + .5 / t - 1 / (12 * t * t) ;
        printf("%.8lf\n" , Ans) ;
    }
    return 0 ;
}

