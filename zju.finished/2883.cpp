#include<iostream>
using namespace std;
enum {
    SIZ = 20008,
};
int num;
int p[SIZ];

void fun(){
    int i;
    scanf("%d",&num);
    for(i=0; i<num; i++){
        scanf("%d",&p[i]);
    }
    sort(p, p+num, greater<int>());
    int t=0;
    for(i=2; i<num; i+=3){
        t += p[i];
    }
    printf("%d\n", t);
}

int main(){
    int tst;
    scanf("%d",&tst);
    while(tst--){
        fun();
    }
    return 0;
}

