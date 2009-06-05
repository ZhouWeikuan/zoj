#include<iostream>

// 从衡阳八中拷贝
using namespace std;
long long tree[10][2001];
int N,M;

void init(){
    int i,j,k;
    for(i=0;i<2001;i++){
        tree[0][i] = 1;
    }
    // N,M = sum (N-1,1) .. (N-1,M/2)
    for(i=1; i< 10; i++){
        for(j=2;j<2001;j++){
            for(k=1; k<= j/2;k++){
                tree[i][j] += tree[i-1][k];
            }
        }
    }

}

long long fun(){
    long long ret = 0;
    for(int i=1;i<=M;i++){
        ret += tree[N-1][i];
    }
    return ret;
}

int main(){
    int tstcase = 0, tstnum;
    init();
    
    cin>>tstnum;
    while(tstcase ++ < tstnum){
        cin>>N>>M;
        cout<<"Case "<<tstcase<<": n = "<<N<<", m = "<<M<<", # lists = "
            <<fun()<<endl;
    }

	return 0;
}
