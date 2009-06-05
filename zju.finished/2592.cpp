#include<iostream>
using namespace std;
int sum, num;

int main(){
    int tstcase,t;

    scanf("%d",&tstcase);
    while(tstcase--){
        scanf("%d",&num);
        sum = 0;
        while(num--){
            scanf("%d",&t);
            sum += t;
        }
        sum = sum <0?0:sum;
        printf("%d\n",sum);
    }

    return 0;
}
