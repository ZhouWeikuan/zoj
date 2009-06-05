#include<iostream>
using namespace std;
enum {
    SIZ = 1008,
};
int jose[SIZ];
int die[SIZ];
int n, m;

// 先计算当jose被杀时，剩下的那个人与他的距离，再把他调整到jose的位置
// jose 向下换到新的位置
void fun(){
    int i, s = 1, t;
    m--;
    for(i=1; i<n;i++){
        t = n - i + 1;
        s = (s + m -1)% t + 1;
        die[i-1] = s;
        jose[i] = jose[i-1];
        if(jose[i-1] > s){
            jose[i]--;
        } else if(jose[i-1]==s){
            jose[i] = -1;
        }
        if(s==n-i+1){
            s = 1;
        }
    }
    if(jose[i-1]!=-1){
        printf("%d\n", jose[0]);
        return;
    }
    s = 1;
    for(i=n-1; i>0 && jose[i]==-1; i--){
        if(s>=die[i-1]){
            s++;
        }
    }
    t = n - i;
   /* if( s > jose[i]){
        m = s - jose[i];
    } else {
        m = t - jose[i] + s;
    }
    s = jose[i] - m + t; */
    s = 2 * jose[i] - s + t;
    s = (s-1) % t + 1;
    for( ; i>0; i--){
        if(s>=die[i-1]){
            s++;
        }
    }
    printf("%d\n", s);
}

int readIn(){
    scanf("%d%d%d",&n,&m,&jose[0]);
    return n+m+jose[0];
}
int main(){

    while(readIn() > 0){
        fun();
    }
    return 0;
}

