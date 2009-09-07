#include<iostream>
using namespace std;
enum {
    SIZ = 104,
};
int root[1000] = {0};
int num[2010] = {0};
int mDays[13]={
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
void init(){
    for (int i=1; i*i<1000; ++i){
        root[i*i] = i;
    }
    num[0] = 0;
    for (int i=1; i<2010; ++i){
        num[i] = num[i-1];
        int a = root[i%100];
        int b = root[i%1000];
        if (a && a<13){
            ++num[i];
        }
        if (b && b<13 && b!=a){
            ++num[i];
        }
    }
}

int main(){
    int tn, l, h;
    init();
    /*
    for (int i=1; i<2010; ++i){
        printf("%d --> %d\n", i, num[i]-num[i-1]);
    }
    return 0;
    */
    scanf("%d", &tn);
    while(tn--){
        scanf("%d%d", &l, &h);
        int t = num[h] - num[l-1];
        printf("%d\n", t);
    }

    return 0;
}

