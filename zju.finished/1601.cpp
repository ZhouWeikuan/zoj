#include<cstdio>
#include<cmath>
/*看了别人的代码，设置了A*L<=1 和 A>=L的情况*/
using namespace std;
double A;
int L;

void fun(){
    if(A * L <= 1){
        printf("%d %d\n",1,L);
        return;
    }
    if(A >= L){
        printf("%d %d\n",L,1);
        return;
    }

    int a,b;
    int sa=0,sb=1;
    double eps = A,t;
    for(b=1;b<=L;b++){
        t = b * A;
        a = (int)t;
        t -= a;
        if(t >= 0.5)
            a++;
        if(a > L)
            break;
        t = fabs(A - a/(double)b);
        if(t < eps){
            eps = t;
            sa = a;
            sb = b;
        }
    }
    printf("%d %d\n",sa,sb);
}

int main(){
    
    while( scanf("%lf%d ", &A, &L) > 0){
        fun();
    }

	return 0;
}
