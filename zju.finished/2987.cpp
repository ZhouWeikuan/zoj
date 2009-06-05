#include<iostream>
using namespace std;
enum {
    SIZ = 100,
};
char dat[SIZ];
int num, pos;
char *s;

int main(){
    int id = 1;
    scanf("%d", &num);
    while(num--> 0){
        scanf("%d %s", &pos, dat);
        s = &dat[pos];
        dat[pos-1] = 0;
        printf("%d %s%s\n",id++, dat, s);
    }
    return 0;
}

