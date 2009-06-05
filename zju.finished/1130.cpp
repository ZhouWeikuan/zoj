#include<iostream>
// 首先知道题意，前一个数的后n-1位与后一个数的前n-1位相同
// 其次，知道这个序列是所有满足题意中的最小的那个
// 再次，知道这是个欧拉路径问题
// 最后，使用试探法深度递归标出序列中的每个数
using namespace std;
int *arr[16];
int *ptr;
char m[32800];
int mask;

int search(int k, int p){
    if(m[k]!=0)
        return 0;
    m[k] = 1;
    ptr[p] = k;
    if(p==mask)
        return 1;
    int nk = k<<1;
    nk &= mask;
    if(search( nk , p+1))
        return 1;
    nk++;
    if(search(nk, p+ 1))
        return 1;
    m[k] = 0;
    return 0;
}
void init(){
    int i,j;
    volatile int k;
    int lim;
    for(i=1;i<16;i++){
        lim = 1<<i;
        ptr = arr[i] = new int[lim];
        mask = lim -1;
        memset(m, 0, sizeof(char)*(lim));
        search(0,0);
    }
}
void freeAll(){
    for(int i=1;i<16;i++){
        delete [] arr[i];
    }
}

int main(){
    int n,k;
    init();
    
    cin>>n>>k;
    while(n + k){
        cout<<arr[n][k]<<endl;
        cin>>n>>k;
    }
    freeAll();

	return 0;
}
