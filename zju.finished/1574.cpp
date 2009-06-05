#include<iostream>
#include<vector>
/*
 *  稍微做了一下改进，保存每个数的低半部分因子(不是素因子，网上解析有误!)
 */
using namespace std;
enum {
    NUM = 45000,
    SIZ = 100008,
    FLEN = 50,
};
struct Node {
    int x,y,z;
};
struct Fact{
    int pos;
    int f[FLEN];
};
Fact fac[NUM];
Node tree[SIZ];
int num = 0;
inline int gcd(int a, int b){
    int t;
    while(a){
        t = b % a;
        b = a;  a = t;
    }
    return b;
}
void init(){
    int i,j,t = 0;
    for(i=2;i<NUM;i++){
        fac[i].f[fac[i].pos++] = 1;
    }
    for(i=2;i*i<NUM;i++){
        for(j=i*i;j<NUM;j+=i){
            fac[j].f[fac[j].pos++] = i;
            //if(fac[j].pos > t)
            //    t = fac[j].pos;
        }
    }
    //printf("t = %d\n",t);
    int x,y,z,a,b;
    for(x=3;num<SIZ;x++){
        if(x%2==1){ // 奇数，为(p+q)*(p-q)
            for(t=fac[x].pos-1;t>=0;--t){
                a = fac[x].f[t]; b = x / a;
                i = (a+b)/2;
                j = (b-a)/2;
                y = 2 * i * j;
                if(x<y && gcd(x,y)==1){
                    tree[num].x = x, tree[num].y = y;
                    tree[num].z = i*i + j *j;
                    num++;
                }
            }
        } else {
            int tmp = x / 2;
            for(t=fac[tmp].pos-1; t>=0; --t){
                a = fac[tmp].f[t], b = tmp/a;
                y = b*b - a*a;
                if(x<y && gcd(x,y) ==1){
                    tree[num].x = x, tree[num].y = y;
                    tree[num].z = a * a + b * b;
                    num++;
                }
            }
        }
    }
}
int cmp(Node &a, Node&b){
    if(a.x != b.x)
        return a.x-b.x;
    if(a.y != b.y)
        return a.y - b.y;
    return a.z - b.z;
}
void check(){
    int t;
    for(t=1;t<SIZ;t++){
        if(cmp(tree[t-1], tree[t]) >=0){
            printf("Error on %d: %d %d %d, %d %d %d\n", t,
                    tree[t-1].x, tree[t-1].y, tree[t-1].z,
                    tree[t].x, tree[t].y, tree[t].z);
        }
    }
}
int main(){
    int t;
    init();
    while(scanf("%d",&t) > 0){
        --t;
        printf("%d %d %d\n", tree[t].x, tree[t].y, tree[t].z);
    }
    return 0;
}
/*
ZJU 1574 Pythagorean Triples
（一）题目大意：
如果一组“勾股数”(x,y,z)满足(x<y<z)&( gcd(x,y,z)=1 )，则称它们为“基本勾股数”。要求：输入 n（0<n<=100000) , 输出第n组“基本勾股数”。
（二）解题思路：
因为没有明显的直接对应关系使得x=f(n),y=g(n),z=h(n);满足x^2+y^2=z^2;故考虑先构造完范围的所有组合；
假设p>q, 我们可以很容易的得到： p^2-q^2   2*p*q    p^2+q^2是一组勾股数；而且我们可以肯定 其中之一 p^2+q^2 是最大的一个即 z ; 但是同时又产生的另外的问题：即如何使得产生的勾股数在组内和组间有序，且满足gcd(x,y,z)=1呢？
先解决gcd(x,y,z)=1的问题，显然如果 x,y,z 两两互质的话，那么这个条件就会满足。但是我们可以换一个角度考虑，我们想求gcd( x,y,z )=? 那么我们是不是会先求出他们之中两个数的最大公约数，然后再求这个最大公约数与第三个数的最大公约数呢？那么试想，如果前两个数的最大公约是1，那么这三个数的最大公约数不就是1吗？也就是说他们是两两互质的咯！~
所以，简化的约束条件：
    如果 gcd(x,y)=1 ，那么 gcd( x,y,z )=1 ; [ gcd( x,y,z )=gcd( gcd(x,y), z ) ]
还剩下一个问题，如何使得产生的勾股数在组内和组间有序；
    开始我考虑 用一个二重循环：
    int p,q;
    for( q=1; q<size; q++ )
        for( p=q+1; p<size; p++ )
            。。。。。。
    然后产生足够多的勾股数组后排序，虽然在产生的过程中很容易保证组内有序列，排序后也可以保证组间是有序的，但是序列并不能保证是完整的,即不缺少一些项.
    虽然这个方法失败了，不过还是让我发现了一个小小规律：
当满足 x<y<z & gcd(x,y,z)=1  时
    当 x%2=1 时 x= p^2-q^2 , y=2*p*q ;
    当 x&2=0 时 y= p^2-q^2   x=2*p*q ;
    因为不可能从p,q角度有序构造出有序的勾股数组，那么我们考虑从最小的x 入手，也就是枚举 x ，然后根据上面的结论：
    在假设 p>q的前提下：
    当 x%2=1 时 我们搜索满足条件的 ( p+q ) 和 ( p-q )，然后解这个方程得到p,q;
    当 x%2=0 时，我们直接搜索满足条件的 p 和 q ；
找到了当前 x 下的 p,q 后，我们可以很快构造出 y和z，然后只要保证 x<y && gcd(x,y)=1,那么很显然这就是一组满足条件的勾股数了；
PS：搜索的时候，如果通过q来找p。那么就可以从i=sqrt(x)一直搜索到i=1;只要满足 x%i=0 就可以；当x%2=0时，还可以再做一个小小的剪枝。即：当(x/2)%2==0成立时再搜索 p,q; 因为如果(x/2)%2==1 ,那么显然, p,q都是奇数，那么 p^2-q^2 就必定会是一个偶数（奇数的n次幂是奇数，奇数之差还是一个奇数）；于是我们有 x=2*p*q是一个偶数，y=p^2-q^2也是一个偶数，那么必定不能使 gcd( x,y )=1满足，也就没有必要构造了；这样可以快0.05s……
（三）我的程序

//   1574 Pythagorean Triples
#include<stdio.h>
#include<math.h>
#define SIZE 100000
int GCD( int a,int b){
    int c,t;
    if( b==0 )  return 0;
    c=a%b;
    while(c!=0){
        a=b;
        b=c;
        c=a%b;
    }
    return(b);
}
int main()
{
    int x,y;
    int p,q;
    int i;
    int list[SIZE+1][3],count=0;
    int tmp;
    for( x=3; count<SIZE; x++  ){   //枚举 勾股数 的第一个数；
       // printf("x=%d\n",x);
        if( x%2==1 ){ // x 为奇数的情况，  那么 x=(p+q)*(p-q); 假设 p>q
                      // 此时 y=2*p*q  ；分解 x ，枚举 他的质因数（p-q）
            for( i=(int)sqrt(x); i>=1; i-- )
                if( x%i==0 ){  //如果 i 是 x 的一个约数；它是(p-q):即较小的那个
                    p= ( x/i + i )/2;
                    q= ( x/i - i )/2;
                    y= 2*p*q;
                    if( x<y && GCD(x,y)==1 ){
                        list[count][0]=x;
                        list[count][1]=y;
                        list[count][2]=p*p+q*q;
                        count++;
                    }
                }
        }//end if
        else{   // x 为偶数的情况  x=2*p*q; y=p*p-q*q;  假设 p>q
                // 同样分解 x ，枚举 他的质因数 q
            tmp=x/2;
            if( tmp%2!=0 )  continue;
            for( i=(int)sqrt(tmp); i>=1; i-- )
                if( tmp%i==0 && tmp/2>i ){
                    p=tmp/i;
                    q=i;
                    y=(p-q)*(p+q);
                    if( x<y && GCD(x,y)==1 ){
                        list[count][0]=x;
                        list[count][1]=y;
                        list[count][2]=p*p+q*q;
                        count++;;
                    }//end if
                }//end if
        }//end else
    }//end else
    while( scanf("%d",&count)!=EOF )
        printf("%d %d %d\n",list[count-1][0],list[count-1][1],list[count-1][2]);
    return 0;
}
*/
