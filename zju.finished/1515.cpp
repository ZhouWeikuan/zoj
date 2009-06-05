#include<iostream>
using namespace std;
//求斜边思想抄别人的..
enum {
    SIZ = 102,
};
/*
4 楼mmmcd（超超）回复于 2003-08-03 19:59:33 得分 0
 
我是这样：  
  n*n,从第0行取第i(0<=i<=n/2)点，从第0列取第j(0<=j<=n/2)点,以那两点为边，  
  可以画一个正方形  
  .   o   .   .   .   .  
  .   .   .   o   .   .  
  o   .   .   .   .   .  
  .   .   o   .   .   .  
  .   .   .   .   .   .  
  .   .   .   .   .   .  
  这个正方形水平移动m次后,碰到右边界。  
  .   .   .   o   .   .  
  .   .   .   .   .   o  
  .   .   o   .   .   .  
  .   .   .   .   o   .  
  .   .   .   .   .   .  
  .   .   .   .   .   .  
  则由对称性，这样的正方形有m*m个  
  --------------------------------------  
  正方形共k个  
  (n*n)!张票中有k*4!*(n*n-4)!张票中奖...  
  Top
5 楼loewe（可怜没人爱）回复于 2003-08-03 20:22:07 得分 0
 
markTop
6 楼billytank（远走高飞）回复于 2003-08-09 17:55:51 得分 0
 
sn[i]表示i×i中的正方形的个数  
  void   initial()    
  {    
      int   i,j,k;    
      for(i=2;i<=100;i++)    
      {    
          sn[i]=i*(i-1)*(2*i-1)/6;    
          for(j=1;j<i-1;j++)    
          {    
              for(k=1;k<i-j;k++)    
              {      
                  sn[i]+=(i-j-k)*(i-j-k);    
              }    
          }    
      }    
  }   
 
*/
int sum[SIZ];
void init() {
    int t;
    sum[0] = 0;
    for(int i=1;i<SIZ;i++) {
        sum[i] = i * (i-1)*(2*i-1)/6;
        for(int j=1;j<i-1;j++){ // 这个也可以优化一下..
            for(int k=1;k<i-j;k++){
                sum[i] += (i-j-k)*(i-j-k);
            }
        }
    }
}
int num,p;

void fun() {
    double val = p;
    p = num * num;
    for(int i=0;i<4;i++) {
        val *= (p-i);
    }
    for(int i=1;i<=4;i++) {
        val /= i;
    }
    p = sum[num];
    val /= p;
    val /= 100;
    printf("%.2lf\n", val);
}

int main() {
    init();
    while(cin>>num>>p && num + p) {
        fun();
    }
    return 0;
}
