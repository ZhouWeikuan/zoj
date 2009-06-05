#include<iostream>
using namespace std;
enum {
    SIZ = 12,
};

long long C[SIZ][SIZ] = {0}; // 组合数
long long L[SIZ][SIZ] = {0}; // L[i][j],i>=j,i个数分在j个锁上
long long tab[SIZ];
long long sum[SIZ];
void init(){
    int i,j;
    for(i=0;i<SIZ;i++)
        C[i][0] = 1;
    for(i=1;i<SIZ;i++){
        for(j=1;j<i;j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
        C[i][i] = 1;
    }
    int f,b;
    for(i=1;i<SIZ;i++){
        L[i][1] = 1;
        for(j=2;j<=i;j++){
            L[i][j] = 0;
            for(f=1, b=i-f;b>=j-1;f++,b--){
                L[i][j] += C[i][f] * L[b][j-1];
            }
        }
    }
}

// n numbers choosed to form a chained button lock
long long calc(int n){
    long long ret = 0;
    for(long long i=1;i<=n;i++){
        ret += L[n][i];
    }
    return ret;
}

void fun(){
    int i,j;
    for(i=1;i<SIZ;i++){
        tab[i] = calc(i);
    }
    for(i=1;i<SIZ;i++){
        sum[i] = 0;
        for(j=1;j<=i;j++){
            sum[i] += C[i][j] * tab[j];
        }
    }
}

int main(){
    init(); fun();
    int tstcase=0,tstnum;
    cin>>tstnum;
    int n;
    while(tstcase ++ < tstnum){
        cin>>n;
        cout<<tstcase<<" "<<n<<" "<<sum[n]<<endl;
    }


    return 0;
}
