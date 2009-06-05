#include<iostream> 
#include<cmath> 
using namespace std; 
/*
    Polya群计数法: 项链有n个位置p种颜色
        1. 计算不动时的总数 p^n
        2. 计算从1到n-1个位置旋转时总的计数 rotate()
        3. 计算点边对称的数目
            3.1 n为奇数时，n * p ^ (p+1)/2
            3.2 n为偶数时，n/2为p^(n/2)，n/2为p^(n/2 + 1)
        4. 因此，总共有2*n种情况有重复计算，除去2*n
*/
int c, s;
bool mark[40];

double rotate(){
    double ret = 0;
    int cnt, i, j, t;
    for(i=1; i<s; i++){
        cnt = 0;
        memset(mark, false, sizeof(mark[0])*(s));
        for(j=0; j<s; j++){
            if(mark[j]) continue;
            cnt++;
            t = j;
            do {
                mark[t] = true;
                t = ( t + i) % s;
            }while(t != j);
        }
        ret += pow(double(c), cnt);
    }
    return ret;
}

void fun(){
    double ret;    
    ret = pow((double)c, s);
    ret += rotate();
    if( (s & 0x01) == 0){   // even
        s /= 2;
        ret += s * ( pow((double)c, s+1) + pow(double(c), s));
        s *= 2;
    } else {    // odd
        ret += pow((double)c, (s + 1)/2) * s;
    }    
    ret /= 2;
    ret /= s;    
    printf("%.0lf\n", ret);
}

int main(){
    
    scanf("%d%d", &c, &s);
    while(c!=0 && s!=0){
        fun();
        scanf("%d%d", &c, &s);
    }
    return 0;
}
