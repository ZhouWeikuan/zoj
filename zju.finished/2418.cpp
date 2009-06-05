#include<iostream>
using namespace std;
enum {
    SIZ = 8,
};
int num;
int col[SIZ];
int mat[SIZ][SIZ];
int maxv, minv;

void shift(int p){
    if(p == num){
        maxv = col[0];
        int c;
        for(c=1; c<num; c++){
            if(maxv < col[c])
                maxv = col[c];
        }
        if(minv > maxv){
            minv = maxv;
        }
        return;
    }
    for(int i=1; i<=num; i++){
        for(int c=0; c<num; c++){
            col[c] -= mat[p][(i+num-1+c)%num];
            col[c] += mat[p][(i+num+c)%num];
        }
        shift(p+1);
    }
}
void fun(){
    for(int c=0; c<num; c++){
        col[c] = 0;
        for(int i=0; i<num; i++){
            col[c] += mat[i][c];
        }
        if(c==0 || maxv < col[c]){
            maxv = col[c];
        }
    }
    minv = maxv;
    shift(1);
    printf("%d\n", minv);
}
void readIn(){
    for(int i=0; i<num; i++){
    for(int j=0; j<num; j++){
        scanf("%d", &mat[i][j]);
    }
    }
}
int main(){

    scanf("%d",&num);
    while(num > 0){
        readIn();
        fun();
        scanf("%d",&num);
    }
    return 0;
}

