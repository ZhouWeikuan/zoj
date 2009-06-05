#include<iostream>
#include<map>
using namespace std;
enum {
    SIZ = 3004, // d(i,j) = max{d(recent(dat[j] - dat[i]), i)} + 1
};
int num;
int dat[SIZ];
int * cnt[SIZ];
int space[SIZ*SIZ/2];
map<int, int> near;
map<int, int>::iterator it;
int m, a, b;

void output(int m, int a, int b){
    num = 0;
    dat[num++] = b;
    dat[num++] = a;
    for(;m>2;m--){
        dat[num] = dat[num-2] - dat[num-1];
        ++num;
    }
    printf("%d\n%d", num, dat[num-1]);
    for(m=num-2; m>=0; --m){
        printf(" %d", dat[m]);
    }
    printf("\n");
}

void fun(){
    int i, j;
    int m = -1, a, b;
    for(i=0;i<num;i++){
        for(j=i+1;j<num; j++)
        {
            it = near.find(dat[j] - dat[i]);
            if (it != near.end())
            {
                cnt[j][i] = cnt[i][it->second] + 1;
            }else{
                cnt[j][i] = 2;
            }
            if (cnt[j][i] > m){
                m = cnt[j][i];
                a = dat[i];
                b = dat[j];
            }
        }
        near[dat[i]] = i;
    }
   
    output(m, a, b);
}

int readIn(){
    int i;
    if( scanf("%d ", &num) < 0)
        return 0;
    near.clear();
    for(i=0; i<num; i++){
        scanf("%d ", &dat[i]);
    }
    return 1;
}
int main(){     
    int tst = 0;
    for(int i=1; i<3001; i++){
        cnt[i] = &space[tst];
        tst += i;
    }
    tst = 0;
    while( readIn() > 0){
        if(tst++)
            printf("\n");
        if (num == 1)
        {
            printf("%d\n%d\n", 1, dat[0]);
        } else {
            fun();
        }
    }
    return 0;
}

