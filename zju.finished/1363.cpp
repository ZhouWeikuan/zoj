#include<iostream>
#include<iomanip>

//以后用生成函数来做？
//从pku上知道减少迭代次数的方法
using namespace std;
enum {
    SIZ = 104,
};
int C,N,M;
double tab[2][SIZ];

double fun(){
    if(M > C)
        return 0;
    if(N > 1100){ // 减少迭代次数
        N = 1100 + (N % 2);
    }
    double *pred=tab[0], *curr=tab[1], *tmp;
    int i,j;
    for(i=1;i<=C+1;i++){
        pred[i] = 0;
    }
    pred[0] = 1;
    while(N --){
        for(i=0;i<=C+1;i++){
            curr[i] = 0;
        }
        for(i=1;i<=C;i++){
            curr[i+1] += pred[i] *(C-i) / C;
            curr[i-1] += pred[i] *i / C;
        }
        curr[1] += pred[0];
        tmp = curr; curr=pred; pred = tmp;
    }
    return pred[M];
}

int main(){
    
    cin>>C;
    while(C){
        cin>>N>>M;
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<fun()<<endl;
        cin>>C;
    }

	return 0;
}
