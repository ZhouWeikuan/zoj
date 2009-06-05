#include<iostream>
using namespace std;
enum {
    SIZ = 40,
};
int cnt[SIZ][SIZ][SIZ];
int sav[SIZ][SIZ];
int calc(int rank, int i, int n){
    if(cnt[rank][i][n] != 0)
        return cnt[rank][i][n];
    if(i == 1)
        return cnt[rank][i][n] = 1;
    if(n == 1)
        return cnt[rank][i][n] = i;
    int ret = 0;
    for(int s=1;s<=i;s++){
        ret += calc(rank+1,i,n-1);
    }
    return cnt[rank][i][n] =ret;
}
int count(int row, int color){
    if(sav[row][color])
        return sav[row][color];
    if(color == 1 || row == color)
        return sav[row][color] = 1;
}

int fun(){

}

int main(){


    return 0;
}
