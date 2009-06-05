#include<iostream>
using namespace std;
enum {
    SIZ = 1008,
};
char str[SIZ];

void fun(){
    int s;
    char *a, *b;
    scanf("%s", str);
    a = b = str;
    while(*a){
        s = 0;
        do {
            s++;
            b++;
        }while(*a == *b);
        printf("%d%c", s, *a);
        a = b;
    }
    printf("\n");
}
int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst--){
        fun();
    }
    return 0;
}
