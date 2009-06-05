#include<iostream>
using namespace std;
enum {
    SIZ = 24,
};
int num;
double rad[SIZ];
double sum[SIZ];

int fun(){
    if(num == 1) return 0;
    sum[0] = 0;
    for(int i=1; i<num; i++){
        sum[i] = sum[i-1] + rad[i-1];
        if(sum[i] >= rad[i])
            return 1;
    }
    return 0;
}
void readIn(){
    for(int i=0; i<num; i++){
        scanf("%lf", &rad[i]);
    }
    sort(rad, rad+num);
}
int main(){
    const char *ans[2] = {"NO", "YES"};

    scanf("%d", &num);
    while(num){
        readIn();
        printf("%s\n", ans[fun()]);
        scanf("%d", &num);
    }

    return 0;
}
