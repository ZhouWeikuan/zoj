#include<iostream>

using namespace std;
enum {
    SIZ = 44,
};
unsigned base[SIZ] = {1, 2};
unsigned a, b, r;
unsigned len;
char out[SIZ];

int getLen(unsigned v){
    int i;
    for(i=0; i<SIZ && v>=base[i]; i++)
        ;    
    if(i <= 0) i=1;
    return i;
}
unsigned conv(const char *s){
    unsigned v = 0;
    len = strlen(s);    
    for(unsigned i=0; i<len; ++i){
        if(s[i]=='1'){
            v += base[len-i-1];
        }
    }
    return v;
}
void canonical(unsigned v){
    len = getLen(v);
    for(unsigned i=0; i<len; i++){
        if(v >= base[len-i-1]){
            out[i] = '1';
            v -= base[len-i-1];
        } else{
            out[i] = '0';
        }
    }
    out[len] = 0;
}
void output(unsigned v, unsigned w){
    canonical(v);
    while(w > len){
        printf(" ");
        w--;
    }    
    printf("%s\n", out);
}


void init(){
    for(int i=2; i<SIZ; i++){
        base[i] = base[i-1] + base[i-2];
    }
}
void fun(){
    int w, i;
    r = a + b;    
    w = 2 + getLen(r);
    output(a, w);
    printf("+");
    output(b, w-1);
    printf("  ");
    for(i=2; i<w; i++)
        printf("-");
    printf("\n");
    output(r, w);
    printf("\n");
}

int readIn(){
    if(scanf("%s", out) < 0) return 0;
    a = conv(out);
    scanf("%s", out);
    b = conv(out);
    return 1;
}
int main(){
    init();
    while(readIn() > 0){
        fun();
    }
    return 0;
}

