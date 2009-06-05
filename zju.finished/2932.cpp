#include<iostream>
using namespace std;
enum {
    SIZ = 100,
};
char o[SIZ];
char r[SIZ*3];
void fun(){
    char *s = r;
    for(int i=0; o[i]; ++i){
        *s++ = '%';
        *s++ = '2';
        switch(o[i]){
        case ' ':
            *s++ = '0'; break;
        case '!':
            *s++ = '1'; break;
        case '$':
            *s++ = '4'; break;
        case '%':
            *s++ = '5'; break;
        case '(':
            *s++ = '8'; break;
        case ')':
            *s++ = '9'; break;
        case '*':
            *s++ = 'a'; break;
        default:
            s -= 2;
            *s++ = o[i]; break;
        }
    }
    *s=0;
    printf("%s", r);
}
int main(){
    fgets(o, SIZ, stdin);
    while(o[0]!='#'){
        fun();
        fgets(o, SIZ, stdin);
    }
    return 0;
}

