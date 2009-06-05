#include<iostream>
using namespace std;
enum {
    SIZ = 16,
};
int pos[SIZ];
int sum[SIZ];
char buf[100000];

void init(){
    pos[0] = sum[0] = 2;
    for(int i=1; i<SIZ; i++){
        pos[i] = sum[i-1] + 2 + i-1;
        sum[i] = sum[i-1] + pos[i];
    }
}
int getNum(){
    int len;
    scanf("%s", buf);
    len = strlen(buf);
    for(int i=0; i<SIZ ;i++){
        if(len == pos[i])
            return i;
    }
    return -1;
}
void output(int v){
    int i;
    printf("{");
    for(i=0; i<v; i++){
        if(i) printf(",");
        output(i);
    }
    printf("}");
}

int main(){
    init();
    int tst, a, b;
    scanf("%d",&tst);
    while(tst--){
        a = getNum();
        b = getNum();
        a += b;
        output(a);
        printf("\n");
    }
    return 0;
}

