#include<iostream>
using namespace std;
enum {
    SIZ = 516,
};
char mat[SIZ][SIZ];
char input[SIZ*SIZ];
int N;

int fill(int r, int c, int s, int p){
    if(input[p] != 'Q'){
        int v = input[p]=='B'?1:0;
        p++;
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                mat[r+i][c+j] = v;
            }
        }
        return p;
    }
    p++;
    s /= 2;
    p = fill(r, c , s, p);
    p = fill(r, c+s, s, p);
    p = fill(r+s, c, s, p);
    p = fill(r+s,c+s,s,p);
    return p;
}
void fun(){
    fill(0,0,N,0);    
}

int half(char *s){
    int t = 0;
    int base = 1;
    for(int i=0;i<8;i++){
        t += s[i] * base;
        base *= 2;
    }
    return t;
}
void print(char *m){
    int i=0;
    while(i < N){
        printf("0x");
        printf("%02x,", half(m+i));
        i += 8;
    }
}
void output(){
    printf("#define quadtree_width %d\n", N);
    printf("#define quadtree_height %d\n", N);
    printf("static char quadtree_bits[] = {\n");
    for(int i=0;i<N;i++){
        print(mat[i]);
        printf("\n");
    }
    printf("};\n");
}
int main(){

    while(scanf("%d",&N) > 0){
        scanf("%s", input);
        memset(mat, 0, sizeof(mat));
        fun();
        output();
    }
    return 0;
}