#include<iostream>
using namespace std;
// 节省空间的一种方法，不过一开始实现时提前退出，后面的数没有读，WA到死
enum {
    SIZ = 16,
};
int tab[SIZ];
int N,M;
int fun(){
    int n=0, t,i,j;
    int flag = 1;
    memset(tab, 1, sizeof(tab));
    for(i=0;i<N;i++){
        for(j=1;j<=M;j++){
            cin>>t;
            if(t == 0 && flag){
                n++;
                if(tab[j-1] == 0 || tab[j] == 0){
                    flag = 0;
                }
            }
            tab[j] = t;
        }
    }
    return flag && n>0;
}
int fun1(){
    int i,j,X[SIZ][SIZ];
    int flag = 1, cnt = 0;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin>>X[i][j];
            if(X[i][j] != 0){
                continue;
            }
            cnt = 1;
            if(i>0 && X[i-1][j]==0){
                flag = 0;
            }
            if(j>0 && X[i][j-1]==0){
                flag = 0;
            }
        }
    }
    return flag && cnt;
}
int main(){
    const char *ans[2] = {"No","Yes"};
    while( cin>>N>>M && (N + M)){
        cout<<ans[fun()]<<endl;
    }

    return 0;
}
