#include<iostream>
using namespace std;
enum {
    SIZ = 8,
};
char aba[SIZ][SIZ];
int sum;

int getVal(int p){
    int v = 0;
    if (aba[1][p] == 'o')
        v += 5;
    for (int i=3; i<SIZ&&aba[i][p]=='o'; ++i){
        ++v;
    }
    return v;
}

bool fun(){
    int s = 0, v = 0;
    for (int i=5, u=1; i>=0; --i, u*=10){
        v = getVal(i);
        s += v*u;
    }
    return s==sum;
}

void readIn(){
    int x, y;
    scanf("%d%d ", &x, &y);
    sum = (x + y) * (y-x+1)/2;
    for (x=0; x<SIZ; ++x)
        fgets(aba[x], SIZ, stdin);
}

int main(){
    int tst;
    const char *ans[] = {
        "Mistake",
        "No mistake"
    };

    scanf("%d ", &tst);
    while(tst--){
        readIn();
        printf("%s\n", ans[fun()]);
    }

    return 0;
}

