#include<iostream>
using namespace std;
enum {
    SIZ = 10,
};
char fi[SIZ];
char se[SIZ];

void fill(char *s){
    static char buf[100];
    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%s", buf);
        *s++ = buf[0];
    }
    *s = 0;
}
int main(){
    int tst;
    const char *ans[2]={"DIFFERENT","SAME"};
    scanf("%d", &tst);
    while(tst--){
        fill(fi);
        fill(se);
        printf("%s\n", ans[strcmp(fi,se)==0]);
    }
    return 0;
}

