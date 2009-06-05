#include<iostream>
/*
 *  一开始的想法是使用O(n^3)的DP，但时间复杂度太高，
 *  现在用的是从网上拷贝的，二分最小值搜索方法，时间复杂度为
 *  O(m*log(sum))
 */
using namespace std;
enum {
    SIZ = 504,
};
int book[SIZ];
int num;
int K,M;
double high,low,mid;
const double eps = 1e-3;
int ptr[SIZ],top;

int test(){
    double r = 0;
    int t = 1;
    for(int i=M-1;i>=0;i--){
        r += book[i];
        if(r > mid){
            t ++;
            r = book[i];
        }
    }
    return t;
}
void fun(){
    scanf("%d%d",&M,&K);
    high = low = 0;
    for(int i=0;i<M;i++){
        scanf("%d",&book[i]);
        high += book[i];
        if(low < book[i])
            low = book[i];
    }
    int k;
    mid = (low + high)/2;
    while(high - low > eps){
        k = test();
        if(k > K){
            low = mid+1;
        } else {
            high = mid;
        }
        mid = (low + high)/2;
    }
    top = 0; double r = 0;
    for(int i=M-1;i>=0;i--){
        r += book[i];
        if(r > mid || top + i == K-2){
            ptr[top++] = i;
            r = book[i];
        }
    }
    int t = 1;
    printf("%d", book[0]);
    while(top){
        --top;
        while(t <= ptr[top]){
            printf(" %d", book[t]);
            t++;
        }
        printf(" /");
    }
    while(t < M){
        printf(" %d", book[t]);
        t++;
    }
    printf("\n");
}

int main(){
    int tstcase;
    scanf("%d",&tstcase);
    while(tstcase--){
        fun();
    }

    return 0;
}
