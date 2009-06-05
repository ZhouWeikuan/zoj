/*
 * 从后向前推算，余数为各位数
*/
#include<iostream>
#include<cmath>
using namespace std;
enum {
    SIZ = 100008,
};
int K;
int nin[9][SIZ], pos, rem[9];
void fun(){
    int i, t;
    pos = 0;
    for(i=0; i<9; i++){
        nin[i][0] = i+1;
        rem[i] = 0;
    }
    bool flag = true;
    for(;flag;){
        pos++;
        for(i=0; i<9; i++){
            t = nin[i][pos-1]*K + rem[i];
            nin[i][pos] = t % 10;
            rem[i] = t / 10;
            if(rem[i] == 0 && nin[i][pos] == nin[i][0]){
                flag = false;
            }
        }
    }
    t = -1;
    for(i=0; i<9; i++){
        if(rem[i]!=0||nin[i][pos]!=nin[i][0]) continue;
        if(t == -1){
            t = i;
        } else {
            for(int j=pos; j>0; j--){
                if(nin[t][j]!=nin[i][j]){
                    if(nin[t][j]>nin[i][j]){
                        t = i;
                    }
                    break;
                }
            }
        }
    }
    for(i=pos; i>0; i--){
        printf("%d", nin[t][i]);
    }
    printf("\n");
}

int main(){
    int n;
    int blk = 0;

    cin>>n;
    while(n--){
        if(blk++){
            printf("\n");
        }
        cin>>K;
        fun();
    }

    return 0;
}

